#include <iostream>
#include <stdlib.h>
#include "Rectangle.h"

//Josh Berc - 2021

using namespace std;

/// <summary>
/// Default constructor. Sets all values to zero;
/// </summary>
Rectangle::Rectangle() {

	length		= 0;
	width		= 0;
	topLeft		= Point2D();
	topRight	= Point2D();
	botRight	= Point2D();
	botLeft		= Point2D();
}

/// <summary>
/// Creates a new rectangle. X/Y being the top left vertex coordinate.
/// </summary>
/// <param name="x">X-Coordinate</param>
/// <param name="y">Y-Coordinate</param>
/// <param name="lengthIn">Length</param>
/// <param name="widthIn">Width(Height)</param>
Rectangle::Rectangle(float x, float y, float lengthIn, float widthIn) {

	length      = lengthIn;
	width       = widthIn;
	topLeft		= Point2D(x, y);
	topRight	= Point2D(x + length, y);
	botRight    = Point2D(x + length, y - width);
	botLeft     = Point2D(x, y - width);
}

/// <summary>
/// Copy Constructor. Initializes a new object using another object of the same class.
/// </summary>
/// <param name="rectangleCopy">Rectangle instance to copy.</param>
Rectangle::Rectangle(const Rectangle& rectangleCopy) {

	//Copying
	length		= rectangleCopy.length;
	width		= rectangleCopy.width;
	topLeft		= rectangleCopy.topLeft;
	topRight	= rectangleCopy.topRight;
	botRight	= rectangleCopy.botRight;
	botLeft		= rectangleCopy.botLeft;
}

/// <summary>
/// Assignment Operator. Initialized object is assigned a new value from another existing object.
/// </summary>
/// <param name="rectangleCopy">Rectangle instance to re-assign</param>
/// <returns></returns>
Rectangle& Rectangle::operator=(const Rectangle& rectangleCopy) {

	//Detetcts self assignment. Unecessary in this case but good practice.
	if (this == &rectangleCopy) {
		return *this;
	}

	//Copying
	length		= rectangleCopy.length;
	width		= rectangleCopy.width;
	topLeft		= rectangleCopy.topLeft;
	topRight	= rectangleCopy.topRight;
	botRight	= rectangleCopy.botRight;
	botLeft		= rectangleCopy.botLeft;

	return *this;
}

/// <summary>
/// Algorithm that checks whether or not a 2D point is contained in an axis-aligned Rectangle.
/// </summary>
/// <param name="point"></param>
/// <returns></returns>
bool Rectangle::PointCollision(Point2D& point) {

	//Checks if point is between left and right points and then top and bottom. Will only return true if all of these conditions are met.
	if (((topLeft.GetX() <= point.GetX()) && (topRight.GetX() >= point.GetX())) && ((topLeft.GetY() >= point.GetY()) && (botLeft.GetY() <= point.GetY()))) {
		return true;
	}

	return false;
}

/// <summary>
/// Algorithm that checks whether or not two axis-aligned Rectangles intersect.
/// </summary>
/// <param name="rectangle"></param>
/// <returns></returns>
bool Rectangle::RectangleCollision(Rectangle& test) {

	//Checks all four points of rectangle for intersections. If none intersect, returns false.
	if (test.PointCollision(topLeft) || test.PointCollision(topRight) || test.PointCollision(botLeft) || test.PointCollision(botLeft)) {
		return true;
	}

	return false;
}

/// <summary>
/// Prints out the rectangle coordinates.
/// </summary>
/// <param name="rectangle"></param>
void Rectangle::Print() {
	//                            TopLeft                                                 Bottom Left                                              BottomRight                                    TopRight
	cout << "Actual:         (" << topLeft.GetX() << ", " << topLeft.GetY() << "), (" << botLeft.GetX() << ", " << botRight.GetY() << "), (" << botRight.GetX() << ", " << botRight.GetY() << "), (" << topRight.GetX() << ", " << topRight.GetY() << ")."   << endl;
}

/// <summary>
/// Test code.
/// </summary>
int main() {

	//Test Rectangles           X, Y, len, width
	Rectangle test1 = Rectangle(2, 10,  4,    2);
	Rectangle test2 = Rectangle(2,  9,  3,    2);
	Rectangle test3 = Rectangle(5.1,4.2,2.3,1.4);
	//Rectangles 1 & 2 collide. 3 does not.

	//Test Points
	Point2D testPoint1 = Point2D(1, 1);
	Point2D testPoint2 = Point2D(3, 9);
	//Point1 will collide with nothing. Point2 collides with test 1 & 2.

	cout << " ---- Data ----" << endl;
	cout << "Test1 Expected: (2, 10), (2, 8), (6, 8), (6, 10)." << endl;
	test1.Print();
	cout << "Test2 Expected: (2, 9), (2, 7), (5, 7), (5, 9)." << endl;
	test2.Print();
	cout << "Test3 Expected: (5.1, 4.2), (5.1, 3.8), (7.4, 3.8), (7.4, 4.2)." << endl;
	test3.Print();
	cout << "Point1 = (1,1)" << endl;
	cout << "Point2 = (3,9)" << endl;
	cout << endl;
	

	//Testing Point Collisions
	cout << "---- Testing ----" << endl;
	cout << "-- Point Collisions --" << endl;
	cout << "Point1 colliding with Test1" << endl;
	cout << "Expected: No." << endl;
	if (test1.PointCollision(testPoint1)) {
		cout << "Actual: Yes." << endl;
	}
	else {
		cout << "Actual: No." << endl;
	}

	cout << "Point1 colliding with Test2" << endl;
	cout << "Expected: No." << endl;
	if (test2.PointCollision(testPoint1)) {
		cout << "Actual: Yes." << endl;
	}
	else {
		cout << "Actual: No." << endl;
	}

	cout << "Point2 colliding with Test1" << endl;
	cout << "Expected: Yes." << endl;
	if (test1.PointCollision(testPoint2)) {
		cout << "Actual: Yes." << endl;
	}
	else {
		cout << "Actual: No." << endl;
	}

	cout << "Point2 colliding with Test2" << endl;
	cout << "Expected: Yes." << endl;
	if (test2.PointCollision(testPoint2)) {
		cout << "Actual: Yes." << endl;
	}
	else {
		cout << "Actual: No." << endl;
	}

	cout << endl;

	//Testing Rectangle collisions
	cout << "-- Rectangle Collisions --" << endl;
	cout << "Test1 colliding with Test2" << endl;
	cout << "Expected: Yes." << endl;
	if (test1.RectangleCollision(test2)) {
		cout << "Actual: Yes." << endl;
	}
	else {
		cout << "Actual: No." << endl;
	}

	cout << "Test2 colliding with Test1" << endl;
	cout << "Expected: Yes." << endl;
	if (test2.RectangleCollision(test1)) {
		cout << "Actual: Yes." << endl;
	}
	else {
		cout << "Actual: No." << endl;
	}

	cout << "Test1 colliding with Test3" << endl;
	cout << "Expected: No." << endl;
	if (test1.RectangleCollision(test3)) {
		cout << "Actual: Yes." << endl;
	}
	else {
		cout << "Actual: No." << endl;
	}

	cout << "Test2 colliding with Test3" << endl;
	cout << "Expected: No." << endl;
	if (test2.RectangleCollision(test3)) {
		cout << "Actual: Yes." << endl;
	}
	else {
		cout << "Actual: No." << endl;
	}

	cout << endl;

	//Testing Assignment and Copy constructor.
	cout << "-- Copy and Assignment --" << endl;
	cout << "Copy Constructor" << endl;
	Rectangle test4(test1);
	cout << "Test4 Expected: (2, 10), (2, 8), (6, 8), (6, 10)." << endl;
	test4.Print();
	cout << "Assignment Operator" << endl;
	Rectangle test5 = test2;
	cout << "Test5 Expected: (2, 9), (2, 7), (5, 7), (5, 9)." << endl;
	test5.Print();

	return 1;
}


