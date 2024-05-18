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













