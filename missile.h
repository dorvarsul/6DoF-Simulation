#ifndef MISSILE_H
#define MISSILE_H

#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Geometry>

#define G 9.81
#define FUEL_EFFICIENCY 0.01

class Missile {
public:
    // State variables
    Eigen::Vector3d position; // Current location of the missile
    Eigen::Vector3d velocity; // Speed and direction of movement
    Eigen::Vector3d acceleration; // The rate of change of velocity
    Eigen::Quaterniond orientation; // Represents the missile's rotation using quartenion
    Eigen::Vector3d angularVelocity; // How fast the missiles rotates around each axis

    // Missile properties
    double dryMass; // Missile's weight
    double momentOfInertia; // Missile's resistance to rotation
    double fuelRemaining; // Remaining fuel
    double thrust; // Engine's thrust

    // Constructor
    Missile(const Eigen::Vector3d& initialPos, const Eigen::Vector3d& initialVel, double m, double fuel, double thrust);

    // Methods
    double getMass();
    double getX();
    double getY();
    double getZ();
    
    void consumeFuel(double dt); // Consume fuel based on thrust
    void update(double dt); // Update pos, velocity and rotation
    bool inAir();
};

#endif  