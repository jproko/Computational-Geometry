//General C++ Standard Libraries
#include <iostream>

// Linker to Header File
#include "ConvexHull.h"

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

int main()
{
	Vector_2D generatedRandomPoints = Generate2DInstance(1,30, 8);
	std::cout << "Generated points:" << std::endl;
	DisplayVector(generatedRandomPoints, 3);
	std::cout << "-------------------------------" << std::endl;
	Vector_2D convexPolygon = GrahamAndrew(generatedRandomPoints);
	std::cout << "Convex Polygon:" << std::endl;
	DisplayVector(convexPolygon, 3);
	std::cout << "-------------------------------" << std::endl;
	return 0;
}