#include "missile.h"

BallisticMissile::BallisticMissile(const Eigen::Vector3d& initialPos, const Eigen::Vector3d& initialVel, double m, double fuel, double thrust)
: Missile(initialPos, initialVel, m, fuel, thrust), launchDirection(initialVel.normalized()) {}

void BallisticMissile::update(double dt) {
    consumeFuel(dt);

    Eigen::Vector3d totalForce = Eigen::Vector3d::Zero();

    // Apply thrust along initial launch direction
    if (thrust > 0) {
        Eigen::Vector3d thrustForce = thrust * launchDirection;
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