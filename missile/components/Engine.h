#ifndef ENGINE_H
#define ENGINE_H

#include <eigen3/Eigen/Dense>

class Engine {
private:
    double thrust; // Amount of force generated in Newtons
    double burnTime; // Maximum burn duration
    double specificImpulse; // Engine's efficiency
    Eigen::Vector3d thrustVector;
    bool isRunning;

public:
    Engine(double thrust, double burnTime, double specificImpulse);
    void ignite(); // Activates engine
    void shutdown(); // Stops thrust
    void update(double dt, const Eigen::Quaterniond& missileOrientation, void* fuelTank); // Adjusts thrust over time
    bool isEngineRunning();
    Eigen::Vector3d getThrustVector();
};

#endif