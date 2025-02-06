#include "missile.h"

// Constructor
Missile::Missile(const Eigen::Vector3d& initialPos, const Eigen::Vector3d& initialVel, double m, double fuel ,double thrust)
: position(initialPos), velocity(initialVel), angularVelocity(Eigen::Vector3d::Zero()), dryMass(m),
fuelRemaining(fuel), thrust(thrust), momentOfInertia(1.0) {
   // Initialize acceleration and orientation
   acceleration = Eigen::Vector3d::Zero();
   orientation = Eigen::Quaterniond(1,0,0,0); // Identity quaternion (no rotation) 
}

Missile::~Missile() {}

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

// Returns true if missile is in air
bool Missile::inAir() {
    if (position.z() < 0) {
        return false;
    }
    return true;
}