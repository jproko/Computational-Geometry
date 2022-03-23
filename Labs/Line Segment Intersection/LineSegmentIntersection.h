//Header guards
//https://www.educative.io/edpresso/what-are--sharpifndef-and--sharpdefine-used-for-in-cpp

// CGAL Convex Hull Libraries (2D)
// https://doc.cgal.org/5.0.4/Convex_hull_2/

#ifndef LINE_SEGMENT_INTERSECTION_H
#define LINE_SEGMENT_INTERSECTION_H

// CGAL Convex Hull Libraries (2D)
// https://doc.cgal.org/5.0.4/Convex_hull_2/

// General C++ Standard Libraries
// * Header that defines the standard input/output stream objects
#include <iostream>

// * Vectors are sequence containers representing arrays that can change in size.
// * https://www.cplusplus.com/reference/vector/vector/
#include <vector>

// * This header introduces random number generation facilities.
// * https://www.cplusplus.com/reference/random/
#include <random>

// * Header providing parametric manipulators :
// * https://www.cplusplus.com/reference/iomanip/
#include <iomanip>

// Predefined Kernel:
// * Exact Geometric Predicates Exact Geometric Constructions 
// * It uses Cartesian representation.
// * It supports constructions of points from double Cartesian coordinates.
// * It provides both exact geometric predicates and exact geometric constructions.
// * https://doc.cgal.org/latest/Kernel_23/classCGAL_1_1Exact__predicates__exact__constructions__kernel.html
#include <CGAL/Exact_predicates_exact_constructions_kernel.h>

// Object - intersection:
// * Two objects obj1 and obj2 intersect if there is a point p that is part of both obj1 and obj2.
// * We are going to use the library for line intersection
// * https://doc.cgal.org/latest/Kernel_23/group__intersection__linear__grp.html
#include <CGAL/intersections.h>

// * Vectors are sequence containers representing arrays that can change in size.
// * https://www.cplusplus.com/reference/vector/vector/
#include <vector>

// Naming Conventions for simplicity
// * Kernel : CGAL::Exact_predicates_exact_constructions_kernel
typedef CGAL::Exact_predicates_exact_constructions_kernel Kernel;

// * Point_2D : Kernel::Point_2
typedef Kernel::Point_2 Point_2D;

// * Line_Segment_2D : Kernel::Segment_2
typedef Kernel::Segment_2 Line_Segment_2D;

// * Intersection_2D : Kernel::Intersect_2
typedef Kernel::Intersect_2 Intersection_2D;

// * Vector_2D : std::vector<Point_2D>
typedef std::vector<Point_2D> Vector_2D;

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

/*
* This function is responsible for displaying on screen a 2D - point where two line intersections intersect.
* If no such point exists, it displays empty intersection message.
*/
void reportLineSegmentIntersection(Line_Segment_2D segment1, Line_Segment_2D segment2);
#endif
