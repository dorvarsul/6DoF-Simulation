#ifndef MISSILE_H
#define MISSILE_H

#include "components/Engine.h"
#include "components/FuelTank.h"
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Geometry>

class Missile {
private:
    Eigen::Vector3d position; // Coordinates in 3D space
    Eigen::Vector3d velocity; // Velocity components
    Eigen::Vector3d acceleration; // Force-driven acceleration
    Eigen::Vector3d angularVelocity; // Roll, Pitch, Yaw rates
    Eigen::Quaterniond orientation; // 3D Orientation
    double mass; // Total mass (including fuel)

    Engine* engine; // Missile's engine
    FuelTank* fuelTank; // Missile's fuel chamber
    /*
    FlightSystem* flightSystem; // Controls aerodynamics and stability
    GuidanceSystem* guidanceSystem; // Tracks target
    Warhead* warhead; // Payload
    */

public:
    Missile();
};

#endif  