cmake_minimum_required(VERSION 3.6)
project(MyStrategy)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-Wno-unknown-pragmas -static -fno-optimize-sibling-calls -fno-strict-aliasing")

set(CPACK_GENERATOR "ZIP")
set(CPACK_PACKAGE_FILE_NAME "${PROJECT_NAME}")
set(CPACK_PACKAGE_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/src")

include(CPack)

set(SRC
        csimplesocket/ActiveSocket.cpp
        csimplesocket/ActiveSocket.h
        csimplesocket/Host.h
        csimplesocket/HTTPActiveSocket.cpp
        csimplesocket/HTTPActiveSocket.h
        csimplesocket/PassiveSocket.cpp
        csimplesocket/PassiveSocket.h
        csimplesocket/SimpleSocket.cpp
        csimplesocket/SimpleSocket.h
        csimplesocket/StatTimer.h
        model/ActionType.h
        model/Bonus.cpp
        model/Bonus.h
        model/BonusType.h
        model/Building.cpp
        model/Building.h
        model/BuildingType.h
        model/CircularUnit.cpp
        model/CircularUnit.h
        model/Faction.h
        model/Game.cpp
        model/Game.h
        model/LivingUnit.cpp
        model/LivingUnit.h
        model/Message.cpp
        model/Message.h
        model/Minion.cpp
        model/Minion.h
        model/MinionType.h
        model/Move.cpp
        model/Move.h
        model/Player.cpp
        model/Player.h
        model/PlayerContext.cpp
        model/PlayerContext.h
        model/Projectile.cpp
        model/Projectile.h
        model/ProjectileType.h
        model/SkillType.h
        model/Status.cpp
        model/Status.h
        model/StatusType.h
        model/Tree.cpp
        model/Tree.h
        model/Unit.cpp
        model/Unit.h
        model/Wizard.cpp
        model/Wizard.h
        model/World.cpp
        model/World.h
        RemoteProcessClient.cpp
        RemoteProcessClient.h
        Runner.cpp
        Runner.h
        Strategy.cpp
        Strategy.h

        src/MyStrategy.cpp
        src/MyStrategy.h
        src/State.cpp
        src/State.h src/Situation.cpp
        src/Situation.h
        src/Ranked.h
        src/Refreshable.h
        src/Behavior.cpp
        src/Behavior.h
        src/NonCopyable.h
        src/Controller.h
        src/Relationship.cpp
        src/Relationship.h
        src/Pointer.h
        src/Point.h
        src/Point.cpp
        src/Action.h
        src/MapGraph.cpp
        src/MapGraph.h
        src/Log.cpp
        src/Log.h
        src/Mechanism.h
        src/WalkingAction.cpp
        src/WalkingAction.h
        src/CastAction.cpp
        src/CastAction.h
        src/MessagingAction.cpp
        src/MessagingAction.h
        src/LearningAction.cpp
        src/LearningAction.h
        src/Graph.h
        src/PathFinder.cpp
        src/PathFinder.h
        src/AStarPathFinder.cpp
        src/AStarPathFinder.h
        src/Grid.h
        src/GridMapGraph.h
        src/Size.cpp
        src/Size.h
        src/Named.h
        src/Named.cpp
        src/BigTeacher.cpp
        src/BigTeacher.h
        src/GridMap.h
        src/Path.cpp
        src/Path.h
        src/VectorProxy.h
        src/ObstaclesGridMaker.h
        src/WorldFilter.cpp
        src/WorldFilter.h
        src/CallbackBehavior.cpp
        src/CallbackBehavior.h
        src/CallbackSituation.cpp
        src/CallbackSituation.h
        src/BonusExistsSituation.cpp
        src/BonusExistsSituation.h
        src/BuildingUnderAttackSituation.cpp
        src/BuildingUnderAttackSituation.h
        src/SelfDisabler.cpp
        src/SelfDisabler.h
        src/DamagedWizardSituation.cpp
        src/DamagedWizardSituation.h
        src/DamagedBuildingSituation.cpp
        src/DamagedBuildingSituation.h
        src/BerserkTools.cpp
        src/BerserkTools.h
        src/BerserkBehavior.h
        src/Ranked.cpp
        src/SelfDisabler.h
        src/Clusterer.cpp
        src/Clusterer.h
        src/MinionCluster.cpp
        src/MinionCluster.h
        src/MagicSensors.cpp
        src/MagicSensors.h
        src/HoldingPositionChecker.cpp
        src/HoldingPositionChecker.h
        src/TakeBonusBehavior.cpp
        src/TakeBonusBehavior.h
        src/RetreatBehavior.cpp
        src/RetreatBehavior.h
        src/WalkingBehavior.cpp
        src/WalkingBehavior.h
        src/AttackBuildingSituation.cpp
        src/AttackBuildingSituation.h
        src/Defines.h
        src/BerserkBehavior.cpp src/Teacher.h src/Controller.cpp src/SimpleTeacher.cpp src/SimpleTeacher.h)

add_executable(${PROJECT_NAME} ${SRC})
add_definitions(-D_LINUX -D__DEBUG__)


