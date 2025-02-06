#ifndef MISSILE_H
#define MISSILE_H

#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Geometry>

#define G 9.81
#define FUEL_EFFICIENCY 0.01
#define NAV_CONSTANT 3.0

class Missile {
protected:
    // State variables
    Eigen::Vector3d position, velocity, acceleration;
    Eigen::Quaterniond orientation; // Represents the missile's rotation using quartenion
    Eigen::Vector3d angularVelocity; // How fast the missiles rotates around each axis

    double dryMass;
    double fuelRemaining;
    double thrust;
    double momentOfInertia;
    
public:

    // Constructor
    Missile(const Eigen::Vector3d& initialPos, const Eigen::Vector3d& initialVel, double m, double fuel, double thrust);
    virtual ~Missile();

    virtual void update(double dt) = 0; // Update missile position , velocity etc

    // Getters
    double getMass();
    double getX();
    double getY();
    double getZ();
    
    void consumeFuel(double dt); // Consume fuel based on thrust
    bool inAir();
};

class BallisticMissile : public Missile {
public:
    BallisticMissile(const Eigen::Vector3d& initialPos, const Eigen::Vector3d& initialVel, double m, double fuel, double thrust);

    void update(double dt) override;

private:
    Eigen::Vector3d launchDirection;
};

class GuidedMissile : public Missile {
public:
    GuidedMissile(const Eigen::Vector3d& initialPos, const Eigen::Vector3d& initialVel, double m, double fuel, double thrust, const Eigen::Vector3d& targetPos);

    void update(double dt) override;

private:
    Eigen::Vector3d targetPos;
    Eigen::Vector3d lastLOSV;
};

#endif  