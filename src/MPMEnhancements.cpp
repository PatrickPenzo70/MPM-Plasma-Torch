//Headers and Includes

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib> // for drand48

//Constants and Types

const double dt = 0.01; // Time step
const int grid_size = 100; // Grid resolution
const double particle_mass = 1.0;
const double particle_temp = 300.0; // Initial temperature in Kelvin
const double melting_temp = 1000.0; // Melting temperature in Kelvin

enum Phase {SOLID, LIQUID};

struct Particle {
     double x, y;
     double vx, vy;
     double mass; 
     double temperature;
     Phase phase;
     
};

struct GridNode {
     double mass = 0.0;
     double vx = 0.0, vy = 0.0;
     double fx = 0.0, fy = 0.0; 
}

// Initialization

std::vector<Particle> inizializeParticles(int num_particles) { 
    std::vector<Particle> particles;
    particles.reserve(num_particles);
    for (int i = 0; i < num_particles; ++i) {
    Particles p = {drand48() * grid_size, drand48() * grid_size, 0.0, 0.0, particles_mass, particles_temp};
    particles.push_back(p);
    }
    return particles;

}

std::vector<std::vector<GridNode>> initializeGrid(int size) {
    return std::vector<std::vector<GridNode>>(size, std::vector<GridNode>>(size));
    
}


// Particle to Grid Transfer

void particleToGrid(std::vector<Particle>& particles, std::vector<std::vector<GridNode>>& grid) {
   for (auto& p : particles) {
       int gx = static_cast<int>(p.x);
       int gy = static_cast<int>(p.y);
       if (gx >= 0 && gx < grid_size && gy >= 0 && gy < grid_size) {
          grid[gx][gy].mass += p.mass;
          grid[gx][gy].vx += p.vx * p.mass;
          grid[gx][gy].vy += p.vy * p.mass;
       }
   
   }

for (int i = 0; i < grid.size; ++i) {
    for (int j = 0; j < grid.size; ++j) {
        if (grid[i][j].mass > 0) {
            grid[i][j].vx /= grid[i][j].mass;
            grid[i][j].vy /= grid[i][j].mass;
        }
    }
  } 
}


// Grid to Particle Transfer

void gridToParticle(std::vector<Particle>& particles, std::vector<std::vector<GridNode>>& grid) {
   for (auto& p : particles) {
       int gx = static_cast<int>(p.x);
       int gy = static_cast<int>(p.y);
       if (gx >= 0 && gx < grid_size && gy >= 0 && gy < grid_size) {
          p.vx = grid[gx][gy].vx;
          p.vy = grid[gx][gy].vy;         
       }
   
   }
}


// Time Integration and Phase Transition

void updateParticles(std::vector<Particles>& particles) {
     for (auto& p : particles) {
         // Check for phase transition
         if (p.temperature > melting_temp) {
            p.phase = LIQUID;
         }
         
         // Update positions
         p.x += p.vx * dt;
         p.y += p.vy * dt;
         
         // Example temperature update (simple model)
         if (p.phase == LIQUID) {
             p.temperature -= 1.0 * dt // Cool down if in liquid phase
         }
     }
  }

void applyBoundaryConditions(std::vector<Particels>& particles) {
     for (auto& p : particles) {
         if (p.x < 0) p.x = 0, p.vx = -p.vx;
         if (p.x >= grid.size) p.x = grid.size - 1, p.vx = -p.vx;
         if (p.y < 0) p.y = 0, p.vy = -p.vy;
         if (p.y >= grid.size) p.y = grid.size - 1, p.vy = -p.vy;

     }
}


// Main Loop

int main() {
    int num_particles = 1000;
    std::vector<Particles> particles = initializeParticles(num_particles);
    std::vector<std::vector<GridNode>> grid = initializeGrid(grid_size);
    
    for (int step = 0; step < 1000; ++step) {
        // Reste grid
        grid = initializeGrid(grid_size);
        
        // Particle to grid
        particleToGrid(partices, grid);

        // update grid forces here if needed (e.g., gravity, pressure, etc.)
        
        // Grid to particle
        gridToParticle(particles, grid);        
        
        // Update particles and handle phase transitions
        updateParticles(particles);
        
        // Apply boundary conditions
        applyBoundaryConditions(particles);
        
        // Output or visualization step here if needed 
    } 
    
    return 0;
    
}

// Explanation
// 1. Initialization:
// a) "initializeParticles" creates particles with random positions, initial velocities, and initial phases (all solid) 
// b) "initializeGrid" sets up the grid nodes.

// 2. Particle to Grid Transfer:
// a) "particleToGrid" maps particle properties (mass, velocity) to the grid nodes.

// 3. Grid to Particle Transfer:
// a) "gridToParticle" interpolates updated grid velocities back to the particles

// 4. Time Integration and Phase Transition:
// a) "updateParticles" moves particles based on their velcoities and checks for phase transitions (solid to liquid) based on temperature.
// b) "applyBoundaryConditiions" handles particles that move outside the simualtion domain.

// 5. Phase Transition Handling:
// a) When a psrticle's temperature exceeds the melting temperature, it changes phase from solid to liquid. 





















