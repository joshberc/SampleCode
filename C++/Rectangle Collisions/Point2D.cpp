#include "Point2D.h"

//Josh Berc - 2021


/// <summary>
/// Default Constructore. Sets X and Y to zero.
/// </summary>
Point2D::Point2D()
{
	x = 0;
	y = 0;
}

/// <summary>
/// Set X and Y value of this point.
/// </summary>
/// <param name="x">X</param>
/// <param name="y">Y</param>
Point2D::Point2D(float X, float Y)
{
	x = X;
	y = Y;
}

/// <summary>
/// Returns X value.
/// </summary>
/// <returns></returns>
float Point2D::GetX() {
	return x;
}

/// <summary>
/// Returns Y value.
/// </summary>
/// <returns></returns>
float Point2D::GetY() {
	return y;
}