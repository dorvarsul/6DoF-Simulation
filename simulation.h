#ifndef SIMULATION_H
#define SIMULATION_H

#include "missile.h"
#include "UnguidedMissile.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>

class Simulation {

public:
    static void runSimulation();
    static double toRadians(double degrees);
    static Eigen::Quaterniond getOrientation(double pitchDeg, double yawDeg);
};

#endif