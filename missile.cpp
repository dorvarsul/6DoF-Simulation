#include "missile.h"

// Constructor
Missile::Missile(
const Eigen::Vector3d& initialPos,
const Eigen::Quaterniond& launchDirection,
double m,
double fuel,
double burnRate,
double thrust)
:position(initialPos),
velocity(Eigen::Vector3d::Zero()),
acceleration(Eigen::Vector3d::Zero()),
orientation(launchDirection),
angularVelocity(Eigen::Vector3d::Zero()),
dryMass(m),
fuelRemaining(fuel),
burnRate(burnRate),
thrust(thrust),
momentOfInertia(1.0) {}

Missile::~Missile() {}

double Missile::getMass() {
    return (dryMass + fuelRemaining);
}

void Missile::consumeFuel(double dt) {

    // Compute fuel usage
    double fuelUsed = burnRate * dt;

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

void Missile::applyPhysics(double dt) {
    Eigen::Vector3d totalForce = Eigen::Vector3d::Zero();
    // Apply thrust along initial launch direction
    if (thrust > 0) {
        // Local forward direction of the missile
        Eigen::Vector3d localForward(0,0,1);

        // Convert to world space using quaternion rotation
        Eigen::Vector3d thrustForce = thrust * (orientation * localForward);
        totalForce += thrustForce;
    }

    // Apply gravity
    Eigen::Vector3d gravityForce(0,0,-G * getMass());
    totalForce += gravityForce;

    // Compute linear acceleration
    acceleration = totalForce / getMass();

    // Update velocity and position
    velocity += acceleration * dt;
    position += velocity * dt;
}

// Returns true if missile is in air
bool Missile::inAir() {
    return getZ() >= 0 || fuelRemaining > 0;
}