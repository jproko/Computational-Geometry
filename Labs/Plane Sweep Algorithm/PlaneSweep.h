//Header guards
//https://www.educative.io/edpresso/what-are--sharpifndef-and--sharpdefine-used-for-in-cpp

// CGAL Convex Hull Libraries (2D)
// https://doc.cgal.org/5.0.4/Convex_hull_2/

#ifndef PLANE_SWEEP_H
#define PLANE_SWEEP_H

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

// --------------------------------------------------------------------

// Predefined Kernel:
// * Exact Geometric Predicates Exact Geometric Constructions 
// * It uses Cartesian representation.
// * It supports constructions of points from double Cartesian coordinates.
// * It provides both exact geometric predicates and exact geometric constructions.
// * https://doc.cgal.org/latest/Kernel_23/classCGAL_1_1Exact__predicates__exact__constructions__kernel.html
#include <CGAL/Exact_predicates_exact_constructions_kernel.h>

// Traits:
// * The traits class "Arr_segment_traits_2" is a model of the ArrangementTraits_2 concept, which allows 
// * the construction and maintenance of arrangements of line segments.
// https://doc.cgal.org/latest/Arrangement_on_surface_2/classCGAL_1_1Arr__segment__traits__2.html
#include <CGAL/Arr_segment_traits_2.h>

// Curve Intersection Algorithm:
// * Outpout - sensitive sweep - plane algorithm that reports all the intersections between curves.
// * Given that any curve can be represented with high - approximation ratio as a set of continuous line segments, these
// * algorithm reports all intersections for any set of given line segments.
// * https://doc.cgal.org/latest/Surface_sweep_2/index.html#Chapter_2D_Intersection_of_Curves
#include <CGAL/Surface_sweep_2_algorithms.h>

// --------------------------------------------------------------------

// Naming Conventions for simplicity
// * Kernel : CGAL::Exact_predicates_exact_constructions_kernel
typedef CGAL::Exact_predicates_exact_constructions_kernel Kernel;

// * Point_2D : Kernel::Point_2
typedef Kernel::Point_2 Point_2D;

// * Traits_2D : CGAL::Arr_segment_traits_2<Kernel>
typedef CGAL::Arr_segment_traits_2<Kernel> Traits_2D;

// * Line_Segment_2D : Kernel::Segment_2
typedef Kernel::Segment_2 Line_Segment_2D;

// * Vector_2D : std::vector<Point_2D>
typedef std::vector<Point_2D> Vector_Point_2D;

// * Vector_2D : std::vector<Point_2D>
typedef std::vector<Line_Segment_2D> Vector_Line_Segment_2D;

// --------------------------------------------------------------------

/*
* This function is responsible for generating a random set of 2D points using the rectangular distribution.
* It takes as input parameters the minimum bound, the maximum bound as well as the number of desired points
* to be generated and returns a vector of 2D - points containing elements in range [a,b)x[a,b).
*/
Vector_Point_2D Generate2DInstance(int minBound, int maxBound, int nrOfElements);

/*
* This function is responsible for displaying in the screen a complete list of a 2D-points vector, given
* the desired fixed precission.
*/
void DisplayVector(Vector_Point_2D vector, int precission);

/*
* This function is responsible for returning a vector of line segments that corresponds 
* to the given vector of 2D - points.
* Example:
* Input 2D - point vector : ((xa,ya), (xb,yb), (xc,yc), (xd,yd), ...)
* Outpout: A vector of the line segments: ((xa,ya) - (xb,yb)), ((xb,yb) - (xc,yc)), ((xc,yc) - (xd,yd)), ((xd,yd) - ...
*/
Vector_Line_Segment_2D MapPointsToSegments(Vector_Point_2D vector);

/*
* This function is responsible for displaying in the screen a complete list of a 2D-line segment vector, given
* the desired fixed precission.
*/
void DisplayLineSegments(Vector_Line_Segment_2D LineSegments, int precission);

/*
* This function is responsible for using the sweep plane algorithm, to find all the points where 
* the given line segments intersect. 
*/
Vector_Point_2D findSegmentLineIntersection(Vector_Line_Segment_2D LineSegments);
#endif