#include "missile.h"

GuidedMissile::GuidedMissile(const Eigen::Vector3d& initialPos, const Eigen::Vector3d& initialVel, double m, double fuel, double thrust, const Eigen::Vector3d& target)
    : Missile(initialPos, initialVel, m, fuel, thrust), targetPos(target), lastLOSV(Eigen::Vector3d::Zero()) {}

void GuidedMissile::update(double dt) {
    consumeFuel(dt);

    Eigen::Vector3d totalForce = Eigen::Vector3d::Zero();

    if (thrust > 0) {
        // Compute current LOS (Line of Sight) vector
        Eigen::Vector3d losVector = (targetPos - position).normalized();

        // Compute LOS rate of change (approximated)
        Eigen::Vector3d losRate = (losVector - lastLOSV).normalized() / dt;
        lastLOSV = losVector; // update LOS vector for next frame

        // Compute Proportional Navigation acceleration
        double navigationConstant = NAV_CONSTANT;
        Eigen::Vector3d lateralAcceleration = navigationConstant * velocity.norm() * losRate;

        // Compute thrust direction using PN guidance
        Eigen::Vector3d thrustDirection = (velocity + lateralAcceleration * dt).normalized();
        Eigen::Vector3d thrustForce = thrust * thrustDirection;
        totalForce += thrustForce;
    }

    // Apply gravity
    Eigen::Vector3d gravityForce(0,0,-G * getMass());
    totalForce += gravityForce;

    // Compute acceleration
    acceleration = totalForce / getMass();

    // Update velocity and position
    velocity += acceleration * dt;
    position += velocity * dt;
}