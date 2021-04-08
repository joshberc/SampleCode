#pragma once

//Josh Berc - 2021

class Point2D
{
public:
	// --- Functions ---
	Point2D(); //Default constructor
	Point2D(float X, float Y); //Constructor
	float GetX(); //Getter
	float GetY(); //Getter
private:
	// --- Variables ---
	float x;
	float y;
};
