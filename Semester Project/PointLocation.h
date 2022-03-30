//Header guards
//https://www.educative.io/edpresso/what-are--sharpifndef-and--sharpdefine-used-for-in-cpp

// CGAL Convex Hull Libraries (2D)
// https://doc.cgal.org/5.0.4/Convex_hull_2/

#ifndef POINT_LOCATION_H
#define POINT_LOCATION_H
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

// * Header responsible for Input/Output stream class to operate on files.
// * https://www.cplusplus.com/reference/fstream/fstream/
#include <fstream>

// * Header responsible for support of strings: objects that represent sequences of characters.
// * https://www.cplusplus.com/reference/string/string/
#include <string>
// --------------------------------------------------------------------

// Predefined Kernel:
// * Exact Geometric Predicates Exact Geometric Constructions 
// * It uses Cartesian representation.
// * It supports constructions of points from double Cartesian coordinates.
// * It provides both exact geometric predicates and exact geometric constructions.
// * https://doc.cgal.org/latest/Kernel_23/classCGAL_1_1Exact__predicates__exact__constructions__kernel.html
#include <CGAL/Exact_predicates_exact_constructions_kernel.h>

// --------------------------------------------------------------------

// Graham - Andrew O(nlogn) Scan Algorithm
// https://doc.cgal.org/5.0.4/Convex_hull_2/group__PkgConvexHull2Functions.html#gaeccc6dda2f9d3096c94a7ff84cc91a85
#include <CGAL/ch_graham_andrew.h>

// --------------------------------------------------------------------

// The traits class Arr_segment_traits_2 is a model of the ArrangementTraits_2 concept, which allows the construction and 
// maintenance of arrangements of line segments.
// https://doc.cgal.org/latest/Arrangement_on_surface_2/classCGAL_1_1Arr__segment__traits__2.html
#include <CGAL/Arr_segment_traits_2.h>

// The class Arrangement_2<Traits, Dcel> encapsulates a data structure that maintains arrangements of arbitrary bounded planar curves.
// It comes with a variety of algorithms that operate on planar arrangement, such as point - location queries and overlay computations, 
// which are implemented as peripheral classes or as free(global) functions.
// https://doc.cgal.org/latest/Arrangement_on_surface_2/index.html
#include <CGAL/Arrangement_2.h>

// --------------------------------------------------------------------

// The Arr_naive_point_location class implements a naive algorithm that traverses all the vertices and halfedges in the arrangement in search for an answer to a point-location query. 
// The query time is therefore linear in the complexity of the arrangement. 
// Naturally, this point-location strategy could turn into a heavy time-consuming process when applied to dense arrangements.
// https://doc.cgal.org/5.0.4/Arrangement_on_surface_2/classCGAL_1_1Arr__naive__point__location.html
#include <CGAL/Arr_naive_point_location.h>

// The Arr_walk_along_line_point_location class implements a very simple point-location (and vertical ray-shooting) strategy that improves the naive one.
// The algorithm considers an imaginary vertical ray emanating from the query point, and simulates a walk along the zone of this ray, starting from the unbounded face 
// until reaching the query point. In dense arrangements this walk can considerably reduce the number of traversed arrangement edges, with respect to the naive algorithm.
// https://doc.cgal.org/5.0.4/Arrangement_on_surface_2/classCGAL_1_1Arr__walk__along__line__point__location.html
#include <CGAL/Arr_walk_along_line_point_location.h>

// The Arr_landmarks_point_location class implements a Jump& Walk algorithm, where special points, referred to as "landmarks", are chosen in a preprocessing stage, 
// their place in the arrangement is found, and they are inserted into a data - structure that enables efficient nearest - neighbor search(a Kd - tree).
// Given a query point, the nearest landmark is locatedand a "walk" strategy is applied from the landmark to the query point.
// https://doc.cgal.org/5.0.4/Arrangement_on_surface_2/classCGAL_1_1Arr__landmarks__point__location.html
#include <CGAL/Arr_landmarks_point_location.h>

// The Arr_trapezoid_ric_point_location class implements the incremental randomized algorithm introduced by Mulmuley as presented in Chapter 6. 
// It subdivides each arrangement face to pseudo-trapezoidal cells, each of constant complexity, and constructs and maintains a linear-size search structure on top of these cells, 
// such that each query can be answered in O(logn) time, where n is the complexity of the arrangement.
// Constructing the search structures takes O(nlogn) expected timeand may require a small number of rebuilds.
// Therefore attaching a trapezoidal point - location object to an existing arrangement may incur some overhead in running times.
// In addition, the point - location object needs to keep its auxiliary data structures up - to - date as the arrangement goes through structural changes.
// It is therefore recommended to use this point - location strategy for: 
// * static arrangements(or arrangement that do not alter frequently), and 
// * when the number of issued queries is relatively large.
// https://doc.cgal.org/5.0.4/Arrangement_on_surface_2/classCGAL_1_1Arr__trapezoid__ric__point__location.html
#include <CGAL/Arr_trapezoid_ric_point_location.h>

// The elements in this header deal with time. This is done mainly by means of three concepts:
// * Durations: They measure time spans, like: one minute, two hours, or ten milliseconds.
//   In this library, they are represented with objects of the duration class template, that couples a count representationand 
//   a period precision(e.g., ten milliseconds has ten as count representationand milliseconds as period precision).
// * Time points: A reference to a specific point in time, like one's birthday, today's dawn, or when the next train passes.
//   In this library, objects of the time_point class template express this by using a duration relative to an epoch
//   (which is a fixed point in time common to all time_point objects using the same clock).
// * Clocks:
//   A framework that relates a time point to real physical time.
//   The library provides at least three clocks that provide means to express the current time as a time_point : system_clock, steady_clockand high_resolution_clock.
// https://www.cplusplus.com/reference/chrono/
#include <chrono>
// --------------------------------------------------------------------

// Naming Conventions for simplicity
// * Kernel : CGAL::Exact_predicates_exact_constructions_kernel
typedef CGAL::Exact_predicates_exact_constructions_kernel Kernel;

// * Point_2D : Kernel::Point_2
typedef Kernel::Point_2 Point_2D;

// * Line_Segment_2D : Kernel::Segment_2
typedef Kernel::Segment_2 Line_Segment_2D;

// * Vector_2D : std::vector<Point_2D>
typedef std::vector<Point_2D> Vector_Point_2D;

// * Vector_2D : std::vector<Point_2D>
typedef std::vector<Line_Segment_2D> Vector_Line_Segment_2D;

// String: std::basic_string<char>
typedef std::basic_string<char> String;
// --------------------------------------------------------------------

// Arrangment_Traits_2D :: CGAL::Arr_segment_traits_2<Cartesian_Kernel> 
typedef CGAL::Arr_segment_traits_2<Kernel> Arrangment_Traits_2D;


typedef Arrangment_Traits_2D::X_monotone_curve_2 Arr_Curve_2D;

// Arrangement_2D :: CGAL::Arrangement_2<Arrangment_Traits_2D> 
typedef CGAL::Arrangement_2<Arrangment_Traits_2D> Arrangement_2D;

// A handle for an arrangement vertex.
// Vertex_handle::Arrangement_2D::Vertex_const_handle
typedef Arrangement_2D::Vertex_const_handle Vertex_handle;

// A handle for an arrangement halfedge.
// HalfEdge_handle::Arrangement_2D::Halfedge_const_handle
typedef Arrangement_2D::Halfedge_const_handle HalfEdge_handle;

// A handle for an arrangement face.
// Face_handle::Arrangement_2D::Face_handle
typedef Arrangement_2D::Face_const_handle Face_handle;

// A bidirectional circulator over the halfedges of a CCB (Connected Component of the Boundary). Its value-type is Halfedge. 
// Each bounded face has a single CCB representing it outer boundary, and may have several inner CCBs representing its holes.
// HalfEdge_circulator :: Arrangement_2D::Ccb_halfedge_const_circulator
typedef Arrangement_2D::Ccb_halfedge_const_circulator HalfEdge_circulator;

// Face_iterator :: Arrangement_2D::Face_iterator
typedef Arrangement_2D::Face_iterator Face_iterator;
// --------------------------------------------------------------------

// Naive_Point_Location :: CGAL::Arr_naive_point_location<Arrangement_2D>
typedef CGAL::Arr_naive_point_location<Arrangement_2D> Naive_Point_Location;

// Walk_Along_Line_Point_Location :: CGAL::Arr_walk_along_line_point_location<Arrangement_2D>
typedef CGAL::Arr_walk_along_line_point_location<Arrangement_2D> Walk_Along_Line_Point_Location;

// LandMarks_Point_Location :: CGAL::Arr_landmarks_point_location<Arrangement_2D>
typedef CGAL::Arr_landmarks_point_location<Arrangement_2D> LandMarks_Point_Location;

// Trapezoid_Point_Location :: CGAL::Arr_trapezoid_ric_point_location<Arrangement_2D>
typedef CGAL::Arr_trapezoid_ric_point_location<Arrangement_2D> Trapezoid_Point_Location;

// Location_Result_Type :: CGAL::Arr_point_location_result<Arrangement_2D>::Type
typedef CGAL::Arr_point_location_result<Arrangement_2D>::Type Location_Result_Type;
// --------------------------------------------------------------------


/*
* This function is responsible for generating a random set of 2D points using the rectangular distribution.
* It takes as input parameters the minimum bound, the maximum bound as well as the number of desired points
* to be generated and returns a vector of 2D - points containing elements in range [a,b)x[a,b).
*/
Vector_Point_2D GeneratePoints2DInstance(int minBound, int maxBound, int nrOfElements);

/*
* This function is responsible for generating a random set of 2D line segments using the rectangular distribution.
* It takes as input parameters the minimum bound, the maximum bound as well as the number of desired segments
* to be generated and returns a vector of 2D - line segments containing elements in range ([a,b)x[a,b), [a,b)x[a,b)).
*/
Vector_Line_Segment_2D GenerateLineSegments2DInstance(int minBound, int maxBound, int nrOfElements);

/*
* This function is responsible for displaying in the screen a complete list of a 2D-points vector, given
* the desired fixed precission.
*/
void DisplayPoints(Vector_Point_2D vector, int precission);

/*
* This function is responsible for displaying in the screen a complete list of a 2D-line segment vector, given
* the desired fixed precission.
*/
void DisplayLineSegments(Vector_Line_Segment_2D LineSegments, int precission);

/*
* This function is responsible for converting a set of 2n points, into n
* line segments as follows: 
* (x_0,y_0), (x_1,y_1) => segment: ((x_0,y_0), (x_1,y_1))
* (x_2,y_2), (x_3,y_3) => segment: ((x_2,y_2), (x_3,y_3))
* ...
* (x_2n-1,y_2n-1), (x_2n,y_2n) => segment: ((x_2n-1,y_2n-1), (x_2n,y_2n))
*/
Vector_Line_Segment_2D ConvertSegmentsFromFile(Vector_Point_2D vector);

/*
* This funtion is responsible for reading the file provided by the given path, line by line, 
* and generating the given data to Point_2D. All the given points are inserted into a vector
* which is the return value of the given function.
*/
Vector_Point_2D ReadPointsFromFile(String path);

/*
* This function is responsible for returning a Point_2D object, corresponding to the given 
* String data entry. An example might be of the following:
* Given data: 2.411245643, 3.45545423456
* Return Point_2D: (2.411245643, 3.45545423456)
*/
Point_2D ParseLineToPoint(String data);

/*
 * This algorithm is responsible for calculating the convex hull of a given point, using the
 * Graham - Andrew Scanning algorithm. It takes as input a Vecor of 2D points in the form of:
 * points = ((x0,y0), (x1,y1), (x2,y2), ..., (xn,yn))
 * and returns a Vector of 2D points containing the extreme points in counter - clockwise order.
*/
Vector_Point_2D GrahamAndrew(Vector_Point_2D points);

/*
* This function is responsible for writting (not appending but overwritting), the line segments that,
* represent the convex hull. The result is written in convexHull.txt file.
*/
void WriteConvexHullSegmentsToFile(Vector_Point_2D convexHull);

/*
* This function is responsible for generating a plane Arangment based uppon the given segment vector.
* The representation of a 2D Arrangment is a Doubly - Connected - Edge - List (DCEL).
*/
Arrangement_2D ConstructArrangment(Vector_Line_Segment_2D segmentVector);

/*
* This function is responsible for diplaying to the screen, the half-edge traversal list, of the outter bound of 
* each face of a given arrangment.  
*/
void DisplayFacesOfArrangment(Arrangement_2D arr);

/*
* This function is reponsible for displaying to the screen, the half-edge traversal list, of the outter bound of the given face.
*/
void DisplayFace(Face_handle f);

/*
* This function is responsible for displaying the result of the query of a point location search. It takes
* as main parameter a location result object, which might be face, line segment or vertex, and based uppon the case, 
* displays the necessary message to the screen.
*/
void displayQueryResult(Point_2D point, Location_Result_Type Point_Location_Result_Object);

/*
* This function is responsible for performing a series of point location querys on the given points vector.
* The algorithmic approach used is: Naive_Point_Location
*/
void LocateAndDisplayPointNaive(Arrangement_2D arr, Vector_Point_2D points);

/*
* This function is responsible for performing a series of point location querys on the given points vector.
* The algorithmic approach used is: Walk_Along_Line_Point_Location
*/
void LocateAndDisplayPointWalkAlongLine(Arrangement_2D arr, Vector_Point_2D points);

/*
* This function is responsible for performing a series of point location querys on the given points vector.
* The algorithmic approach used is: LandMarks_Point_Location
* Given that we have not set an explicit Generator for the algorithm, the vertices of the arrangment are used.
*/
void LocateAndDisplayPointLandmarks(Arrangement_2D arr, Vector_Point_2D points);

/*
* This function is responsible for performing a series of point location querys on the given points vector.
* The algorithmic approach used is: Trapezoid_Point_Location
*/
void LocateAndDisplayPointTrapezoid(Arrangement_2D arr, Vector_Point_2D points);

/*
* This function is responsible for saving the nodes as well as the half-edges of every face, of a given arrangment,
* in "arrangments.txt" file. 
*/
void SaveArrangment(Arrangement_2D arr);

/*
* This function is responsible for reading the arrangment.txt file and returning its corresponding arrangment to the invoker.
*/
Arrangement_2D LoadArrangment();
#endif
