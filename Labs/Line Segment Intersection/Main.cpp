#include <iostream>
// Linker to Header File
#include "LineSegmentIntersection.h"
int main()
{
    std::cout << "Hello World!\n";

	Vector_2D Random_4_Point_2D = Generate2DInstance(1,10,4);
	std::cout << "Random Points:" << std::endl;
	DisplayVector(Random_4_Point_2D, 3);
	Line_Segment_2D segment1 = Line_Segment_2D(Random_4_Point_2D[0], Random_4_Point_2D[1]);
	Line_Segment_2D segment2 = Line_Segment_2D(Random_4_Point_2D[2], Random_4_Point_2D[3]);
	std::cout << "------------------------------------" << std::endl;
	std::cout << "Intersection:" << std::endl;
    reportLineSegmentIntersection(segment1, segment2);
}