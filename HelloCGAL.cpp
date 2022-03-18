#include <iostream> //Input - Outpout library
#include <CGAL/Simple_cartesian.h> //Geometry Kernel : A model for a Kernel using Cartesian coordinates to represent the geometric objects.

//typedef: https://www.cprogramming.com/tutorial/typedef.html
//Syntax of typedef: typedef data_type_name new_data_type_name

//https://doc.cgal.org/latest/Kernel_23/structCGAL_1_1Simple__cartesian.html
//CGAL::Simple_cartesian<double> => CartesianKernel
typedef CGAL::Simple_cartesian<double> SimpleCartesianKernel;

//https://doc.cgal.org/latest/Kernel_23/classCGAL_1_1Point__2.html
//CartesianKernel::Point_2 => Point_2D
typedef SimpleCartesianKernel::Point_2 Point_2D;

//https://doc.cgal.org/latest/Kernel_23/classCGAL_1_1Segment__2.html
//SimpleCartesianKernel::Segment_2 => LineSegment_2D
typedef SimpleCartesianKernel::Segment_2 LineSegment_2D;

int main()
{
    //Declaration of 2 2D - points p and q, with coordinates: (1,1) and (10,10) 
    Point_2D p(1, 1), q(10, 10);

    //Displaying the coordinates of the points in two ways
    //First method: displaying a point as a Point_2D object
    std::cout << "p = " << p << std::endl;
    //Second method: displaying a point as an x and y coordinate of a Point_2D object
    std::cout << "x of q = " << q.x() << " and y of q =" << q.y() << std::endl;

    //https://doc.cgal.org/latest/Kernel_23/group__squared__distance__grp.html
    float euclidean_distance = CGAL::squared_distance(p, q);
    std::cout << "Euclidean distance of p and q = " << euclidean_distance << std::endl;

    //A line segment s between 2d points p and q
    LineSegment_2D s(p, q);
    std::cout<< "Line s pointed connecting p and q:" << s << std::endl;

    //Introducing a new 2D point
    Point_2D m(5, 9);

    std::cout << "m = " << m << std::endl;
    float euclidean_point_from_line = CGAL::squared_distance(s, m);
    std::cout << "Euclidean distance between line - segment s and point m = "<< euclidean_point_from_line << std::endl;
    
    //Now we intend to examine the orientation of 3 points p q m
    //https://doc.cgal.org/latest/Kernel_23/group__kernel__enums.html
    std::cout << "Examine the orientation of points p q m" << std::endl;
    int orientation = CGAL::orientation(p, q, m);
    switch (orientation) 
    {
        case CGAL::COLLINEAR:
            std::cout << "Points are collinear\n";
        break;
        case CGAL::LEFT_TURN:
            std::cout << "Points make a left turn\n";
        break;
        case CGAL::RIGHT_TURN:
            std::cout << "Points make a right turn\n";
        break;
    }
    
    //Calculate the midpoint of a line segment
    //https://doc.cgal.org/latest/Kernel_23/group__midpoint__grp.html
    Point_2D mid = CGAL::midpoint(p, q);
    std::cout << "Midpoint(p,q) = " << mid << std::endl;
    return 0;
}