// Linker to Header File
#include "LineSegmentIntersection.h"

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

void reportLineSegmentIntersection(Line_Segment_2D segment1, Line_Segment_2D segment2)
{
	// The auto keyword specifies that the type of the variable that is being declared will be automatically deducted from its initializer.
	// https://www.geeksforgeeks.org/type-inference-in-c-auto-and-decltype/
	const auto result = intersection(segment1, segment2);

	if (result) 
	{
		// If there is a result, I want the type cast Point_2D of the
		// value of result pointer
		const Point_2D* s = boost::get<Point_2D>(&*result);
		std::cout << std::fixed << std::setprecision(3) << "(" << (*s).x() << "," << (*s).y() << ")" << std::endl;
	}
	else 
	{
		//There is no result
		std::cout << "No intersection point detected" << std::endl;
	}


}

