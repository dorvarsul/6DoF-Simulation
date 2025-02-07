#include "UnguidedMissile.h"

UnguidedMissile::UnguidedMissile(const Eigen::Vector3d& initialPos,
const Eigen::Quaterniond& launchDirection,
double m,
double fuel,
double burnRate,
double thrust)
: Missile(initialPos, launchDirection, m, fuel, burnRate, thrust) {}

void UnguidedMissile::update(double dt) {
    consumeFuel(dt);
    applyPhysics(dt);
}