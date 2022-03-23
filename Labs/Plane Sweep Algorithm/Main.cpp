// Linker to Header File
#include "PlaneSweep.h"

int main()
{
    std::cout << "Generate a random set of 6 points between 0-10:" << std::endl;
    Vector_Point_2D instance = Generate2DInstance(0, 10, 6);
    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "Displaying points:" << std::endl;
    DisplayVector(instance, 3);
    std::cout << "--------------------------------------------------" << std::endl;
    
    std::cout << "Map points to consequential line segments:" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;
    Vector_Line_Segment_2D lineSegments = MapPointsToSegments(instance);
    std::cout << "Displaying line segments:" << std::endl;
    DisplayLineSegments(lineSegments, 3);
    std::cout << "--------------------------------------------------" << std::endl;

    std::cout << "Plane sweep line algorithm for segment line intersection:" << std::endl;
    Vector_Point_2D intersectionPoints = findSegmentLineIntersection(lineSegments);
    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "Displaying intersection points:" << std::endl;
    DisplayVector(intersectionPoints, 3);
    std::cout << "--------------------------------------------------" << std::endl;

    return 0;
}