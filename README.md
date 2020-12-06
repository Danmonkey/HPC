# HPC
A collection of homeworks/programs done for my High-Performance Computing independent study with Dr. Asai Asaithambi.


# Program 1: Gauss-Jacobi Method
The first program in the collection implements the Gauss-Jacobi iterative method for solving linear systems of equations as a matrix.
The Matrix class is implemented as a flattened (I.E. a one-dimensional) array.

# Project 2: Octave scripts for 3 iterative methods.
The 2nd project contains a collection of Octave (Matlab) scripts for iterative methods for matrices. They utilize a static case, but could be adapted for more general cases easily. There are 3 scripts. The first is for the Gauss-Jacobi method (the simplest one, and the same general algorithm as porject 1), the second corresponds to the Gauss-Seidel method, and the final one being Successive Over-Relaxation (SOR). Of the three, SOR typically converges fastest (if it converges at all). Not included are ways to test if convergence is possible, which is easily doable with Octave, but was not required for this project.
