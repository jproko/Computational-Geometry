// Linker to Header File
#include "PointLocation.h"

Vector_Point_2D GeneratePoints2DInstance(int minBound, int maxBound, int nrOfElements)
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

Vector_Line_Segment_2D GenerateLineSegments2DInstance(int minBound, int maxBound, int nrOfElements) 
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

	Vector_Line_Segment_2D randomSegments;

	for (int n = 0; n < nrOfElements; n++)
	{
		double x1;
		double y1;

		double x2;
		double y2;

		x1 = rectangularDistribution(randomEngine);
		y1 = rectangularDistribution(randomEngine);

		x2 = rectangularDistribution(randomEngine);
		y2 = rectangularDistribution(randomEngine);

		// vector::push_back(<T> value)
		// Adds a new element at the end of the vector, after its current last element. The content of val is copied (or moved) to the new element.
		// https://www.cplusplus.com/reference/vector/vector/push_back/
		Line_Segment_2D segment = Line_Segment_2D(Point_2D(x1, y1), Point_2D(x2, y2));
		randomSegments.push_back(segment);
	}
	return randomSegments;
}

void DisplayPoints(Vector_Point_2D vector, int precission)
{
	for (int i = 0; i < vector.size(); i++)
	{
		std::cout << std::fixed << std::setprecision(precission) << "(" << vector[i][0] << "," << vector[i][1] << ")" << std::endl;
	}
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

Vector_Line_Segment_2D ConvertSegmentsFromFile(Vector_Point_2D vector) 
{
	Vector_Line_Segment_2D lineSegments;
	for(int i=0;i<vector.size();i+=2)
	{
		Point_2D pointA = vector[i];
		Point_2D pointB = vector[i+1];
		Line_Segment_2D segmentAB = Line_Segment_2D(pointA, pointB);
		lineSegments.push_back(segmentAB);	
	}		
	return lineSegments;
}

Vector_Point_2D ReadPointsFromFile(String path) 
{
	//Initialize vector
	Vector_Point_2D filePoints;

	// std::ifstream
	// Input stream class to operate on files.
	// https://www.cplusplus.com/reference/fstream/ifstream/
	std::ifstream file(path);

	//Initialize text data
	String data;

	// std::getline
	// getline reads characters from an input stream and places them into a string
	// https://en.cppreference.com/w/cpp/string/basic_string/getline
	while (std::getline(file, data))
	{
		Point_2D point = ParseLineToPoint(data);
		filePoints.push_back(point);
	}
	file.close();
	return filePoints;
}

Point_2D ParseLineToPoint(String data) 
{
	int index = 0;
	size_t len = data.length();
	int mode = 0;
	String x="";
	String y = "";
	while (index < len) 
	{
		char charachter = data[index];
		if (mode == 0) 
		{
			x += charachter;
		}
		else if (mode == 1) 
		{
			y += charachter;
		}
		
		if (charachter == ',') 
		{
			mode = 1;
		}
		index += 1;
	}

	// std::stod
	// Parses str interpreting its content as a floating-point number, which is returned as a value of type double.
	// https://www.cplusplus.com/reference/string/stod/

	Point_2D point = Point_2D(std::stod(x), std::stod(y));
	return point;
}

Vector_Point_2D GrahamAndrew(Vector_Point_2D points) 
{
	Vector_Point_2D result;
	CGAL::ch_graham_andrew(points.begin(), points.end(), std::back_inserter(result));
	return result;
}

void WriteConvexHullSegmentsToFile(Vector_Point_2D convexHull)
{
	std::ofstream myfile("convexHull.txt");
	if (myfile.is_open())
	{
		for (int i = 0; i < convexHull.size()-1; i++) 
		{
			Point_2D pointA = convexHull[i];
			Point_2D pointB = convexHull[i+1];
			myfile << pointA.x() << "," << pointA.y()<<'\n';
			myfile << pointB.x() << "," << pointB.y() << '\n';
		}
		Point_2D pointA = convexHull[convexHull.size() - 1];
		Point_2D pointB = convexHull[0];
		myfile << pointA.x() << "," << pointA.y() << '\n';
		myfile << pointB.x() << "," << pointB.y();
		myfile.close();
	}
	else 
		std::cout << "Unable to open file";
}

Arrangement_2D ConstructArrangment(Vector_Line_Segment_2D segmentVector)
{
	// Construct the arrangement of given segments
	Arrangement_2D arr;

	insert(arr, segmentVector.begin(), segmentVector.end());
	// Print the size of the arrangement.
	std::cout << "Displaying arrangement size:" << std::endl
		<< "Vertices : " << arr.number_of_vertices()
		<< ",  Edges : " << arr.number_of_edges()
		<< ",  Faces : " << arr.number_of_faces() << std::endl;
	return arr;
}

void DisplayFacesOfArrangment(Arrangement_2D arr) 
{
	// Print the outer boundary.
	Face_iterator f = arr.faces_begin();
	for(int i=0;i< arr.number_of_faces();i++)
	{
		std::cout << "Face:" << i << std::endl;
		DisplayFace(f);
		std::cout << "------------------" << std::endl;
		f++;
	}
}

void DisplayFace(Face_handle f) 
{
	if (f->is_unbounded())
	{
		std::cout << "Unbounded face. " << std::endl;
	}
	else
	{
		std::cout << "Outer boundary: " << std::endl;
		HalfEdge_circulator circulator = f->outer_ccb();
		HalfEdge_circulator indexcirculator = circulator;
		std::cout << "vector((" << indexcirculator->source()->point().x() << ", " << indexcirculator->source()->point().y() << "), ";
		std::cout << "(" << indexcirculator->target()->point().x() << ", " << indexcirculator->target()->point().y() << ")) " << std::endl;
		indexcirculator++;
		while (indexcirculator != circulator)
		{
			std::cout << "vector((" << indexcirculator->source()->point().x() << ", " << indexcirculator->source()->point().y() << "), ";
			std::cout << "(" << indexcirculator->target()->point().x() << ", " << indexcirculator->target()->point().y() << ")) " << std::endl;
			indexcirculator++;
		}
	}
}

void displayQueryResult(Point_2D point, Location_Result_Type Point_Location_Result_Object)
{
	const Vertex_handle* v;
	const HalfEdge_handle* e;
	const Face_handle* f;

	if (f = boost::get<Face_handle>(&Point_Location_Result_Object)) 
	{
		// Located inside a face
		std::cout << "Point:(" << point.x() << "," << point.y() << ") was located inside a face." << std::endl;
		std::cout << "Face details:"<< std::endl;
		DisplayFace((*f));
		std::cout << "-------------------------------------" << std::endl;
	}
	else if (e = boost::get<HalfEdge_handle>(&Point_Location_Result_Object)) 
	{
		// Located on an edge
		std::cout << "Degenerate Case: "
			<<"Point:(" << point.x() << ", " << point.y() << ") was located on an edge." << std::endl;
		std::cout << "Edge details:" << (*e)->curve() << std::endl;
		std::cout << "-------------------------------------" << std::endl;
		
	} 
	else if (v = boost::get<Vertex_handle>(&Point_Location_Result_Object)) 
	{
		// Located on a vertex
		std::cout << "Degenerate Case: "
			<< "Point:(" << point.x() << ", " << point.y() << ") was located on/as a vertex." << std::endl;
		std::cout << "Vertex details:" << (*v)->point() << std::endl;
		std::cout << "-------------------------------------" << std::endl;
	} 
}

void LocateAndDisplayPointNaive(Arrangement_2D arr, Vector_Point_2D points)
{
	Naive_Point_Location naive_pl(arr);
	Location_Result_Type Point_Location_Result_Object; 
	for (int i=0;i<points.size();i++) 
	{
		Point_Location_Result_Object = naive_pl.locate(points[i]);
		displayQueryResult(points[i], Point_Location_Result_Object);
	}
}

void LocateAndDisplayPointWalkAlongLine(Arrangement_2D arr, Vector_Point_2D points)
{
	Walk_Along_Line_Point_Location walk_along_line_pl(arr);
	Location_Result_Type Point_Location_Result_Object;
	for (int i = 0; i < points.size(); i++)
	{
		Point_Location_Result_Object = walk_along_line_pl.locate(points[i]);
		displayQueryResult(points[i], Point_Location_Result_Object);
	}
}

void LocateAndDisplayPointLandmarks(Arrangement_2D arr, Vector_Point_2D points)
{
	LandMarks_Point_Location landmarks_pl(arr);
	Location_Result_Type Point_Location_Result_Object;
	for (int i = 0; i < points.size(); i++)
	{
		Point_Location_Result_Object = landmarks_pl.locate(points[i]);
		displayQueryResult(points[i], Point_Location_Result_Object);
	}
}

void LocateAndDisplayPointTrapezoid(Arrangement_2D arr, Vector_Point_2D points)
{
	Trapezoid_Point_Location trapezoid_pl(arr);
	Location_Result_Type Point_Location_Result_Object;
	for (int i = 0; i < points.size(); i++)
	{
		Point_Location_Result_Object = trapezoid_pl.locate(points[i]);
		displayQueryResult(points[i], Point_Location_Result_Object);
	}
}

void SaveArrangment(Arrangement_2D arr)
{
	std::ofstream myfile("arrangment.txt");
	if (myfile.is_open())
	{
		Vertex_handle v = arr.vertices_begin();
		Face_handle f = arr.faces_begin();

		for (int i = 0; i < arr.number_of_vertices(); i++)
		{
			Point_2D point = v->point();
			myfile << point.x() << "," << point.y() << '\n';
			v++;
		}
		myfile << "----------------------" << '\n';
		for (int j = 0; j < arr.number_of_faces(); j++) 
		{
			if (f->is_unbounded()) 
			{
				myfile << "Unbounded" << '\n';
			}
			else 
			{
				HalfEdge_circulator circulator = f->outer_ccb();
				HalfEdge_circulator indexcirculator = circulator;
				myfile << indexcirculator->source()->point().x() << ", " << indexcirculator->source()->point().y() <<"\n";
				myfile << indexcirculator->target()->point().x() << ", " << indexcirculator->target()->point().y() <<"\n";
				indexcirculator++;
				while (indexcirculator != circulator)
				{
					myfile << indexcirculator->source()->point().x() << ", " << indexcirculator->source()->point().y() << "\n";
					myfile << indexcirculator->target()->point().x() << ", " << indexcirculator->target()->point().y() << "\n";
					indexcirculator++;
				}
			}
			myfile << "----------------------" << '\n';
			f++;
		}
		myfile.close();
	}
	else
		std::cout << "Unable to open file";
}

Arrangement_2D LoadArrangment() 
{
	Arrangement_2D arr;
	std::ifstream file("arrangment.txt");
	String data;
	int mode = 0;
	
	while (std::getline(file, data))
	{
		if (data == "----------------------") 
		{
			mode = 1;
			continue;
		}
		if (mode == 0) 
		{
			Point_2D point = ParseLineToPoint(data);
			insert_point(arr, point);
		}
		else 
		{
			if (data == "Unbounded")
			{
				continue;
			}
			Point_2D pointA = ParseLineToPoint(data);
			std::getline(file, data);
			Point_2D pointB = ParseLineToPoint(data);
			Arr_Curve_2D segment(pointA,pointB);
			insert(arr, segment); 
		}
		
	}
	file.close();
	std::cout << "Displaying arrangement size:" << std::endl
		<< "Vertices : " << arr.number_of_vertices()
		<< ",  Edges : " << arr.number_of_edges()
		<< ",  Faces : " << arr.number_of_faces() << std::endl;
	return arr;
}