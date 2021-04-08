#pragma once
#include "Point2D.h"

//Josh Berc - 2021

class Rectangle
{
public:
	// --- Functions ---
	Rectangle(); //Default constructor
	Rectangle(float x, float y, float length, float width); //Constuctor
	Rectangle& operator=(const Rectangle& toCopy); //Assignment Operator 
	Rectangle(const Rectangle& rectangleCopy); // Copy Constructor

	bool PointCollision(Point2D& point); 
	bool RectangleCollision(Rectangle& rectangle); 

	void Print();
	
private:
	// --- Variables ---
	float length, width;
	Point2D topLeft;
	Point2D topRight;
	Point2D botLeft;
	Point2D botRight;
};