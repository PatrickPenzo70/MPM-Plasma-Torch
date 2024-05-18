# MPM-Plasma-Torch
Implementing the Material Point Method (MPM) for simulating many particles in a hot gas flow in C++ involves severals steps.
The MPM is a numerical technique that combines the advantages of both Eulerian and Lagrangian methods, making it suitable for handling large deformations 
and complex intercations such as thos found in fluid and solid mechanics.

Steps 
# Initialization:

a) Define the domain and discretize it using a background grid.
b) Initialize particles with properies such as position, velocity, mass, temperature, etc.

"initializeParticles" creates particles with random positions and initial velocities
"initializeGrid" sets up the grid nodes

# Grid Construction:

a) Assign particles to the grid cells

# Grid Update:

a) Compute grid forces based on particle data
b) Update grid velocities and other quantities

"particleToGrid" maps particle properties (mass, velocity) to the grid nodes

# Particle Update:

a) Interpolate grid data back to particles
b) Update particle positions and properties

"gridToParticles" interpolates updated grid velocities back to the particles

# Time Integration

a) Use a time-stepping method to advance the simulation

"updateParticles" moves particles based on their velocities

# Boundary Conditions

a) Apply appropriate boundary conditions to both particles and the grid.

"applyBoundaryConditions" handles particles that move outside the simualtion domain.

# ENHANCEMENTS
# Force Calculations
Implement forces such as pressure, viscosity and thermal effects     
# Collision Handling
More sophisticated bounday conditions and particle collisions
# Thermal Effects
Integrate temperature change and heat transfer mechanisms
# Optimizartions
Use spatial data structures for efficient neighbor searching

The above framework can be expanded with more physics and optimizations depending on the specific requirements of the simulation.
We can think many particles that can be melt in the hot gas flow.

Implementing the MPM to simulate particles that can melt in a hot gas flow involves addiional complexity compared to the basic MPM implementation.
The main challenge is to account for phase changes (solid to liquid) and handle the interactions between particles in different phases.

Steps
# Initialization:

a) Define the domain and discretize it using a background grid.
b) Initialize particles with properies such as position, velocity, mass, temperature, phase (solid or liquid) etc.

# Grid Construction:

a) Assign particles to the grid cells

# Grid Update:

a) Compute grid forces based on particle data
b) Update grid velocities and other quantities

# Particle Update:

a) Interpolate grid data back to particles
b) Update particle positions and properties

# Phase Transition Handling:

a) Implement rules for phase changes (e.g., melting when temperature exceeds a certain threshold).

# Time Integration

a) Use a time-stepping method to advance the simulation

# Boundary Conditions

a) Apply appropriate boundary conditions to both particles and the grid.











