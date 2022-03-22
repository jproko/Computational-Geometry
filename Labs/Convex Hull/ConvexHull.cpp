// Linker to Header File
#include "ConvexHull.h"

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

// CGAL Convex Hull Libraries (2D)
// https://doc.cgal.org/5.0.4/Convex_hull_2/

// Predefined Kernel:
// * Exact Geometric Predicates Inexact Geometric Constructions 
// * It uses Cartesian representation.
// * It supports constructions of points from double Cartesian coordinates.
// * It provides exact geometric predicates, but inexact geometric constructions.
// * https://doc.cgal.org/5.0.4/Kernel_23/classCGAL_1_1Exact__predicates__inexact__constructions__kernel.html
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>

// Graham - Andrew O(nlogn) Scan Algorithm
// https://doc.cgal.org/5.0.4/Convex_hull_2/group__PkgConvexHull2Functions.html#gaeccc6dda2f9d3096c94a7ff84cc91a85
#include <CGAL/ch_graham_andrew.h>

// Naming Conventions for simplicity
// * Kernel : CGAL::Exact_predicates_inexact_constructions_kernel
typedef CGAL::Exact_predicates_inexact_constructions_kernel Kernel;

// * Point_2D : CGAL::Exact_predicates_inexact_constructions_kernel
typedef Kernel::Point_2 Point_2D;

// * Vector_2D : std::vector<Point_2D>
typedef std::vector<Point_2D> Vector_2D;

Vector_2D GrahamAndrew(Vector_2D points)
{
	Vector_2D result;
	CGAL::ch_graham_andrew(points.begin(), points.end(), std::back_inserter(result));
	return result;
}

Vector_2D Generate2DInstance(int minBound, int maxBound, int nrOfElements)
{
	// A random number generator that produces non-deterministic random numbers, if supported.
	// Unlike the other standard generators, this is not meant to be an engine that generates pseudo - random numbers, 
	// but a generator based on stochastic processes to generate a sequence of uniformly distributed random numbers.
	// https://www.cplusplus.com/reference/random/random_device/
	std::random_device randomDevice;
	
	// This is a random number engine class that generates pseudo-random numbers.
	// It is the library implemention's selection of a generator that provides at least acceptable 
	// engine behavior for relatively casual, inexpert, and/or lightweight use.
	// https://www.cplusplus.com/reference/random/default_random_engine/
	std::default_random_engine randomEngine(randomDevice());

	// This distribution (also know as rectangular distribution) produces random numbers in a range [a,b) 
	// where all intervals of the same length within it are equally probable.
	// https://www.cplusplus.com/reference/random/uniform_real_distribution/
	std::uniform_real_distribution<> rectangularDistribution(minBound, maxBound);

	// std::fixed
	// Use fixed floating-point notation (function )
	// std::setprecision(int)
	// Sets the decimal precision to be used to format floating - point values on output operations.
	// https://www.cplusplus.com/reference/iomanip/setprecision/

	Vector_2D randomPoints;

	for (int n = 0; n < nrOfElements; n++)
	{
		double x;
		double y;
		x = rectangularDistribution(randomEngine);
		y = rectangularDistribution(randomEngine);
		
		// vector::push_back(<T> value)
		// Adds a new element at the end of the vector, after its current last element. The content of val is copied (or moved) to the new element.
		// https://www.cplusplus.com/reference/vector/vector/push_back/
		randomPoints.push_back(Point_2D(x, y));
	}
	return randomPoints;
}

void DisplayVector(Vector_2D vector, int precission) 
{
	for (int i = 0; i < vector.size(); i++)
	{
		std::cout << std::fixed << std::setprecision(precission) << "(" << vector[i][0] << "," << vector[i][1] << ")" << std::endl;
	}
}