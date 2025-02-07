#ifndef UNGUIDEDM_H
#define UNGUIDEDM_H

#include "missile.h"

class UnguidedMissile : public Missile {
public:
    UnguidedMissile(const Eigen::Vector3d& initialPos,
    const Eigen::Quaterniond& launchDirection,
    double m,
    double fuel,
    double burnRate,
    double thrust);

    void update(double dt) override;
};

#endif