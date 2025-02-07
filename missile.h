#ifndef MISSILE_H
#define MISSILE_H

#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Geometry>

#define G 9.81
#define NAV_CONSTANT 3.0

class Missile {
protected:
    // State variables
    Eigen::Vector3d position, velocity, acceleration;
    Eigen::Quaterniond orientation; // Represents the missile's rotation using quartenion
    Eigen::Vector3d angularVelocity; // How fast the missiles rotates around each axis

    double dryMass;
    double fuelRemaining;
    double burnRate;    
    double thrust;
    double momentOfInertia;
    
public:

    // Constructor
    Missile(const Eigen::Vector3d& initialPos, const Eigen::Quaterniond& launchDirection, double m, double fuel, double burnRate, double thrust);
    virtual ~Missile();

    virtual void update(double dt) = 0; // Update missile position , velocity etc

    // Getters
    double getMass();
    double getX();
    double getY();
    double getZ();
    
    void applyPhysics(double dt);
    void consumeFuel(double dt); // Consume fuel based on thrust
    bool inAir();
};

#endif  