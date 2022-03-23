// Linker to Header File
#include "PlaneSweep.h"

Vector_Point_2D Generate2DInstance(int minBound, int maxBound, int nrOfElements)
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

	Vector_Point_2D randomPoints;

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

void DisplayVector(Vector_Point_2D vector, int precission)
{
	for (int i = 0; i < vector.size(); i++)
	{
		std::cout << std::fixed << std::setprecision(precission) << "(" << vector[i][0] << "," << vector[i][1] << ")" << std::endl;
	}
}

Vector_Line_Segment_2D MapPointsToSegments(Vector_Point_2D vector) 
{
	Vector_Line_Segment_2D lineSegments;

	for (int i = 0; i < vector.size() - 1; i++) 
	{
		Point_2D pointA = vector[i];
		Point_2D pointB = vector[i+1];
		Line_Segment_2D segmentAB = Line_Segment_2D(pointA, pointB);
		lineSegments.push_back(segmentAB);
	}

	return lineSegments;
}

void DisplayLineSegments(Vector_Line_Segment_2D LineSegments, int precission)
{
	for (int i = 0; i < LineSegments.size(); i++)
	{
		Point_2D pointSource = LineSegments[i].source();
		Point_2D pointTarget = LineSegments[i].target();
		std::cout << std::fixed << std::setprecision(precission) << "Line segment: source (" << pointSource.x() << "," << pointSource.y() << "), target (" << pointTarget.x() << "," 
			<< pointTarget.y() << ")" << std::endl;
	}
}

Vector_Point_2D findSegmentLineIntersection(Vector_Line_Segment_2D LineSegments)
{
	Vector_Point_2D intersectionPoints;
	CGAL::compute_intersection_points(LineSegments.begin(), LineSegments.end(),std::back_inserter(intersectionPoints));
	return intersectionPoints;
}