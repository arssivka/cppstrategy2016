/**
 *  @autor arssivka
 *  @date 11/30/16
 */
#pragma once

#include <vector>
#include "Point.h"
#include "Pointer.h"

class Graph {
public:
    Graph() = default;

    virtual std::vector<std::pair<Point, double>> getNeighbourVertexes(const Point& point) const = 0;

    virtual Point getNearestVertex(const Point& point) const = 0;

    virtual ~Graph() {}

};

