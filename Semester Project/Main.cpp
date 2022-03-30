// Linker to Header File
#include "PointLocation.h"


int main()
{
    std::chrono::steady_clock::time_point begin;
    std::chrono::steady_clock::time_point end;
    
    //Vector_Point_2D randomPoints = GeneratePoints2DInstance(0, 10000, 10000);
    //DisplayPoints(randomPoints, 3);
    
    std::cout << "Reading points from file 'points.txt':" << std::endl;
    Vector_Point_2D file_points = ReadPointsFromFile("points.txt");
    std::cout << "--------------------------------------------------" << std::endl;
    
    //std::cout << "Displaying points (.3 precission):\n" << std::endl;
    //DisplayPoints(file_points,3);
    //std::cout << "--------------------------------------------------" << std::endl;

    std::cout << "Reading line segment points from 'segments.txt':" << std::endl;
    Vector_Point_2D file_segment_points = ReadPointsFromFile("segments.txt");
    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "Converting segment points to segments:" << std::endl;
    Vector_Line_Segment_2D file_line_segments = ConvertSegmentsFromFile(file_segment_points);
    std::cout << "--------------------------------------------------" << std::endl;
    
    //std::cout << "Displaying line segments (.3 precission):\n" << std::endl;
    //DisplayLineSegments(file_line_segments, 3);
    //std::cout << "--------------------------------------------------" << std::endl;

    std::cout << "Merge all points of A:" << std::endl;
    Vector_Point_2D points_of_A = file_points;
    points_of_A.insert(points_of_A.end(), file_segment_points.begin(), file_segment_points.end());
    std::cout << "--------------------------------------------------" << std::endl;
    
    std::cout << "Calculating convex hull via Graham Andrew Algorithm." << std::endl;
    begin = std::chrono::steady_clock::now();
    Vector_Point_2D convexHull = GrahamAndrew(points_of_A);
    end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << " miliseconds" << std::endl;
    WriteConvexHullSegmentsToFile(convexHull);
    std::cout << "--------------------------------------------------" << std::endl;

    //std::cout << "Displaying convex hull(.3 precission):\n" << std::endl;
    //DisplayPoints(convexHull, 3);
    //std::cout << "--------------------------------------------------" << std::endl;
    
    std::cout << "Reading line segment points from 'convexHull.txt':" << std::endl;
    Vector_Point_2D convex_segment_points = ReadPointsFromFile("convexHull.txt");
    std::cout << "--------------------------------------------------" << std::endl;
    
    std::cout << "Converting segment points to segments:" << std::endl;
    Vector_Line_Segment_2D convex_line_segments = ConvertSegmentsFromFile(convex_segment_points);
    std::cout << "--------------------------------------------------" << std::endl;
    
    std::cout << "Displaying Convex Hull line segments (.3 precission):\n" << std::endl;
    DisplayLineSegments(convex_line_segments, 3);
    std::cout << "--------------------------------------------------" << std::endl;

    Vector_Line_Segment_2D totalLineSegments = file_line_segments;
    totalLineSegments.insert(totalLineSegments.end(), convex_line_segments.begin(), convex_line_segments.end());

    std::cout << "Creating the corresponding arrangment:" << std::endl;
    Arrangement_2D arr = ConstructArrangment(totalLineSegments);
    std::cout << "--------------------------------------------------" << std::endl;

    std::cout << "Saving Arrangment to arrangment.txt:" << std::endl;
    SaveArrangment(arr);
    std::cout << "--------------------------------------------------" << std::endl;

    std::cout << "Loading arrangment from file:" << std::endl;
    LoadArrangment();
    std::cout << "--------------------------------------------------" << std::endl;

    //std::cout << "Displaying faces:" << std::endl;
    //DisplayFacesOfArrangment(arr);
    //std::cout << "--------------------------------------------------" << std::endl;
    
    //std::cout << "=== Naive Point Location ===" << std::endl;
    //begin = std::chrono::steady_clock::now();
    //LocateAndDisplayPointNaive(arr, file_points);
    //end = std::chrono::steady_clock::now();
    //std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << " miliseconds" << std::endl;
    //std::cout << "--------------------------------------------------" << std::endl;
    
    //std::cout << "=== Walk Along Line Point Location ===" << std::endl;
    //begin = std::chrono::steady_clock::now();
    //LocateAndDisplayPointWalkAlongLine(arr, file_points);
    //end = std::chrono::steady_clock::now();
    //std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << " miliseconds" << std::endl;
    //std::cout << "--------------------------------------------------" << std::endl;

    
    //std::cout << "=== Landmarks Point Location ===" << std::endl;
    //begin = std::chrono::steady_clock::now();
    //LocateAndDisplayPointLandmarks(arr, file_points);
    //end = std::chrono::steady_clock::now();
    //std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << " miliseconds" << std::endl;
    //std::cout << "--------------------------------------------------" << std::endl;
    
    
    //std::cout << "=== Trapezoid Point Location ===" << std::endl;
    //begin = std::chrono::steady_clock::now();
    //LocateAndDisplayPointTrapezoid(arr, file_points);
    //end = std::chrono::steady_clock::now();
    //std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << " miliseconds" << std::endl;
    //std::cout << "--------------------------------------------------" << std::endl;
}
