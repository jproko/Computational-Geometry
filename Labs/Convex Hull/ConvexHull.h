//Header guards
//https://www.educative.io/edpresso/what-are--sharpifndef-and--sharpdefine-used-for-in-cpp

// CGAL Convex Hull Libraries (2D)
// https://doc.cgal.org/5.0.4/Convex_hull_2/

#ifndef CONVEXHULL_H
#define CONVEXHULL_H

// * Vectors are sequence containers representing arrays that can change in size.
// * https://www.cplusplus.com/reference/vector/vector/
#include <vector>

// Predefined Kernel:
// * Exact Geometric Predicates Inexact Geometric Constructions 
// * It uses Cartesian representation.
// * It supports constructions of points from double Cartesian coordinates.
// * It provides exact geometric predicates, but inexact geometric constructions.
// * https://doc.cgal.org/5.0.4/Kernel_23/classCGAL_1_1Exact__predicates__inexact__constructions__kernel.html
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>

// Naming Conventions for simplicity
// * Kernel : CGAL::Exact_predicates_inexact_constructions_kernel
typedef CGAL::Exact_predicates_inexact_constructions_kernel Kernel;

// * Point_2D : CGAL::Exact_predicates_inexact_constructions_kernel
typedef Kernel::Point_2 Point_2D;

// * Vector_2D : std::vector<Point_2D>
typedef std::vector<Point_2D> Vector_2D;

/*
 * This algorithm is responsible for calculating the convex hull of a given point, using the
 * Graham - Andrew Scanning algorithm. It takes as input a Vecor of 2D points in the form of:
 * points = ((x0,y0), (x1,y1), (x2,y2), ..., (xn,yn))
 * and returns a Vector of 2D points containing the extreme points in counter - clockwise order.
*/
Vector_2D GrahamAndrew(Vector_2D points);

/*
* This function is responsible for generating a random set of 2D points using the rectangular distribution.
* It takes as input parameters the minimum bound, the maximum bound as well as the number of desired points
* to be generated and returns a vector of 2D - points containing elements in range [a,b)x[a,b).
*/
Vector_2D Generate2DInstance(int minBound, int maxBound, int nrOfElements);

/*
* This function is responsible for displaying in the screen a complete list of a 2D-points vector, given
* the desired fixed precission.
*/
void DisplayVector(Vector_2D vector, int precission);
#endif