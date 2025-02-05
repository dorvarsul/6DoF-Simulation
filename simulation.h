#ifndef SIMULATION_H
#define SIMULATION_H

#include "missile.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>

class Simulation {
public:
    static void runSimulation(double duration, double timeStep);
};

#endif