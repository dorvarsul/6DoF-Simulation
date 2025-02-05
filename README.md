# Missile Simulation

This project simulates missile trajectory and allows visualization of its path in 3D space. It includes a basic missile class with physics-based movement, fuel consumption, and thrust application. The simulation outputs the missile's trajectory over time, which can be visualized using Python and `matplotlib`.

## Features
- Missile movement simulation in 3D space.
- Fuel consumption model.
- Thrust and gravity effects.
- Trajectory visualization using `matplotlib` in Python.

## Project Structure
- **simulation.h / simulation.cpp**: Entry point and core simulation code and logic.
- **missile.h / missile.cpp**: Missile class implementation with physics models.
- **visualization.py**: Python script to visualize the missile trajectory.

## Prerequisites

Before running the project, make sure you have the following installed:

### 1. C++ Environment
- [g++](https://gcc.gnu.org/) (or another C++ compiler)
- [Eigen](https://eigen.tuxfamily.org/dox/): C++ library for linear algebra (included in the project)

### 2. Python Environment
- Python 3.6+
- `pandas` and `matplotlib` libraries

### 3. Clone or download repository to your local machine
git clone https://github.com/yourusername/missile-simulation.git
cd missile-simulation

### 4. Build and run the simulation
using 'make' and '/missile_sim'

### 5. Run the visualization script
You should have a new file called 'trajectory.csv', type python3 visualize.py into the terminal
This will generate a 3D plot of the missile's trajectory.

### To-Do List

    1. Add Guidance Systems: Implement guidance algorithms to adjust the missile's trajectory based on target coordinates.
    2.Multiple Rocket Launchers: Add the ability to launch multiple missiles simultaneously and visualize all their trajectories.
    3.Optimization: Refactor code for better performance and memory management.
    4,Enhance Physics Model: Add more advanced physics, like wind effects or resistance, for more accurate simulations.
    5.Add UI for Settings: Implement a graphical user interface (GUI) for setting missile parameters before launching.

### Image
![image](https://github.com/user-attachments/assets/35ca6895-8aa2-455c-b3b2-da733b2eae7c)
