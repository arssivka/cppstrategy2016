/**
 *  @autor tekatod
 *  @date 11/30/16
 */
#include "AStarPathFinder.h"
#include "Log.h"
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <queue>


AStarPathFinder::AStarPathFinder(Ptr<Graph> graph, size_t initialQueueSize)
        : PathFinder(std::move(graph)), mInitialQueueSize(initialQueueSize) {}

std::forward_list<Point> AStarPathFinder::findPath(const Point& start, const Point& end) {
    using Waypoint = std::pair<Point, double>;
    if (start == end) {
        return std::forward_list<Point>{start};
    }
    double dist = 0;
    auto comparator = [&end](const Waypoint& first, const Waypoint& second) -> bool {
        return first.first.getDistanceTo(end) + first.second  > second.first.getDistanceTo(end) + second.second;
    };
    std::vector<Waypoint> container;
    container.reserve(mInitialQueueSize);
    std::priority_queue<Waypoint, std::vector<Waypoint>, decltype(comparator)> q{std::move(comparator),
                                                                                 std::move(container)};
    q.push({start, dist});
    std::unordered_map<Point, double> waypoints;
    waypoints.max_load_factor(0.8);
    bool found = false;
    auto graph = this->getGraph();
    while (!q.empty()) {
        auto current = std::move(q.top());
        q.pop();
        auto& pos = current.first;
        dist =  current.second;
        auto contains = waypoints.find(pos);
        if (contains == waypoints.cend()) {
            waypoints.emplace(current);
        } else if (contains->second > dist) {
            contains->second = dist;
        } else {
            continue;
        }

        if (pos == end) {
            found = true;
            break;
        }
        auto neighbours = graph->getNeighbours(pos);
        for (auto&& neighbour : neighbours) {
            q.push({neighbour.first, neighbour.second + dist});
        }

    }

    if (!found) {
        return std::forward_list<Point>{start};
    }

    std::forward_list<Point> path;
    auto current = end;
    while (current != start) {
        path.push_front(current);
        const auto& neighbours = graph->getNeighbours(current);
        auto place = std::accumulate(neighbours.cbegin(), neighbours.cend(), current,
                                     [&waypoints, &dist](const Point& acc, const auto& pair) -> Point {
            const auto& point = pair.first;
            auto found = waypoints.find(point);
            if (found == waypoints.end()) return acc;
            auto len = found->second;
            if (len < dist) {
                dist = len;
                return point;
            } else {
                return acc;
            }
        });
        current = place;

    }
    path.push_front(start);
    return std::move(path);
}


size_t AStarPathFinder::getInitialQueueSize() const {
    return mInitialQueueSize;
}


void AStarPathFinder::setInitialQueueSize(size_t initialQueueSize) {
    mInitialQueueSize = initialQueueSize;
}


