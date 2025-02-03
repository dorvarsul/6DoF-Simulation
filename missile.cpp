#include "missile.h"

// Constructor
Missile::Missile(const Eigen::Vector3d& initialPos, const Eigen::Vector3d& initialVel, double m, double fuel ,double thrust)
: position(initialPos), velocity(initialVel), dryMass(m), momentOfInertia(1.0), angularVelocity(Eigen::Vector3d::Zero()),
fuelRemaining(fuel), thrust(thrust) {
   // Initialize acceleration and orientation
   acceleration = Eigen::Vector3d::Zero();
   orientation = Eigen::Quaterniond(1,0,0,0); // Identity quaternion (no rotation) 
}

double Missile::getMass() {
    return (dryMass + fuelRemaining);
}

void Missile::consumeFuel(double dt) {
    const double fuelEfficiency = FUEL_EFFICIENCY; // Fuel consumption per unit thrust (kg/N - s)

    // Compute fuel usage
    double fuelUsed = thrust * fuelEfficiency * dt;

    // Reduce fuel
    fuelRemaining = std::max(0.0, fuelRemaining - fuelUsed);

    if (fuelRemaining <= 0) thrust = 0;
}

void Missile::update(double dt) {
    // Consume fuel
    consumeFuel(dt);

    Eigen::Vector3d totalForce = Eigen::Vector3d::Zero();
    Eigen::Vector3d totalTorque = Eigen::Vector3d::Zero();

    // Apply thrust if there's fuel remaining
    if (thrust > 0) {
        Eigen::Vector3d thrustForce = orientation * Eigen::Vector3d(0,0, thrust);
        totalForce += thrustForce;
    }

    // Apply gravity
    Eigen::Vector3d gravityForce(0, 0, -G * getMass()); // F = mg
    totalForce += gravityForce;

    // Complete linear acceleration
    acceleration = totalForce / getMass();

    // Update velocity and position
    velocity += acceleration * dt;
    position += velocity * dt;

    // Complete angular acceleration
    Eigen::Vector3d angularAcceleration = totalTorque / momentOfInertia;

    // Update angular velocity and orientation
    angularVelocity += angularAcceleration * dt;

    Eigen::Quaterniond deltaOrientation(1, angularVelocity.x() * dt / 2, angularVelocity.y() * dt / 2, angularVelocity.z() * dt / 2);
    orientation = orientation * deltaOrientation;
    orientation.normalize();
}