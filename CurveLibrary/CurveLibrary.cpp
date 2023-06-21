#include "pch.h"
#include "CurveLibrary.h"
#include "Validation.h"
#include <cmath>


#pragma region Point

Point3D::Point3D(double x, double y, double z) : x(x), y(y), z(z) {}

#pragma region Getters and Setters

double Point3D::GetX() { return x; };
double Point3D::GetY() { return y; };
double Point3D::GetZ() { return z; };

void Point3D::SetX(double x) { this->x = x; };
void Point3D::SetY(double y) { this->y = y; };
void Point3D::SetZ(double z) { this->z = z; };

#pragma endregion


#pragma endregion


#pragma region Vector

Vector3D::Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}

#pragma region Getters and Setters

double Vector3D::GetX() { return x; };
double Vector3D::GetY() { return y; };
double Vector3D::GetZ() { return z; };

void Vector3D::SetX(double x) { this->x = x; };
void Vector3D::SetY(double y) { this->y = y; };
void Vector3D::SetZ(double z) { this->z = z; };

#pragma endregion

#pragma endregion


#pragma region Circle

Circle::Circle(double radius) : radius(radius)
{
	CheckLength(radius);
}


#pragma region Methods

Point3D Circle::getPoint(double t)const
{
	double x = radius * cos(t);
	double y = radius * sin(t);

	return Point3D(x, y, 0);
}


Vector3D Circle::getDerivative(double t) const
{
	double dx_dt = -radius * sin(t);
	double dy_dt = radius * cos(t);

	return Vector3D(dx_dt, dy_dt, 0);
}

#pragma endregion


#pragma region Getters and Setters

double Circle::GetRadius() { return radius; };

void Circle::SetRadius(double radius)
{
	CheckLength(radius);

	this->radius = radius;
};

#pragma endregion


#pragma endregion


#pragma region Ellipse

Ellipse::Ellipse(double majorAxis, double minorAxis) : majorAxis(majorAxis), minorAxis(minorAxis)
{
	CheckLength(majorAxis);
	CheckLength(minorAxis);
}

#pragma region Methods

Point3D Ellipse::getPoint(double t) const
{
	double x = majorAxis * cos(t);
	double y = minorAxis * sin(t);

	return Point3D(x, y, 0);
}


Vector3D Ellipse::getDerivative(double t) const
{
	double dx_dt = -majorAxis * sin(t);
	double dy_dt = minorAxis * cos(t);

	return Vector3D(dx_dt, dy_dt, 0);
}

#pragma endregion

#pragma region Getters and Setters

double Ellipse::GetMajorAxis() { return majorAxis; };
void Ellipse::SetMajorAxis(double length)
{
	CheckLength(length);

	this->majorAxis = length;
};

double Ellipse::GetMinorAxis() { return minorAxis; };
void Ellipse::SetMinorAxis(double length)
{
	CheckLength(length);

	this->minorAxis = length;
};

#pragma endregion


#pragma endregion


#pragma region Helix

Helix::Helix(double radius, double pitch) : radius(radius), pitch(pitch)
{
	CheckLength(radius);
	CheckLength(pitch);
}

#pragma region Methods

Point3D Helix::getPoint(double t) const
{
	double x = radius * cos(t);
	double y = radius * sin(t);
	double z = pitch * t;

	return Point3D(x, y, z);
}


Vector3D Helix::getDerivative(double t) const
{
	double dx_dt = -radius * sin(t);
	double dy_dt = radius * cos(t);
	double dz_dt = pitch;

	return Vector3D(dx_dt, dy_dt, dz_dt);
}

#pragma endregion


#pragma region Getters and Setters

double Helix::GetRadius() { return radius; };
void Helix::SetRadius(double radius)
{
	CheckLength(radius);

	this->radius = radius;
};

double Helix::GetPitch() { return pitch; };
void Helix::SetPitch(double pitch)
{
	CheckLength(radius);

	this->pitch = pitch;
};

#pragma endregion


#pragma endregion