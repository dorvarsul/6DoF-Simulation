#include "missile.h"

// Constructor
Missile::Missile(const Eigen::Vector3d& initialPos, const Eigen::Vector3d& initialVel, double m, double fuel ,double thrust)
: position(initialPos), velocity(initialVel), angularVelocity(Eigen::Vector3d::Zero()), dryMass(m), momentOfInertia(1.0),
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

double Missile::getX() {
    return position.x();
}

double Missile::getY() {
    return position.y();
}

double Missile::getZ() {
    return position.z();
}

void Missile::update(double dt) {
    // Consume fuel
    consumeFuel(dt);

    Eigen::Vector3d totalForce = Eigen::Vector3d::Zero();
    Eigen::Vector3d totalTorque = Eigen::Vector3d::Zero();

    // Apply thrust if there's fuel remaining
    if (thrust > 0) {
        Eigen::Vector3d thrustForce = thrust * velocity.normalized();
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

// Returns true if missile is in air
bool Missile::inAir() {
    if (position.z() < 0) {
        return false;
    }
    return true;
}