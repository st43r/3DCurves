#ifndef CURVELIBRARY_H
#define CURVELIBRARY_H

#ifdef CURVELIBRARY_EXPORTS
#define CURVELIBRARY_API __declspec(dllexport)
#else
#define CURVELIBRARY_API __declspec(dllimport)
#endif

/// <summary>
/// Point in 3D space.
/// </summary>
extern CURVELIBRARY_API class Point3D
{
public:
	/// <summary>
	/// Default constructor that sets coordinates value.
	/// </summary>
	/// <param name="x">Abscissa.</param>
	/// <param name="y">Ordinate.</param>
	/// <param name="z">Applicate.</param>
	CURVELIBRARY_API Point3D(double x, double y, double z);


#pragma region Getters and Setters

	/// <summary>
	/// Get coordinate of abscissa.
	/// </summary>
	/// <returns>X coordinate.</returns>
	CURVELIBRARY_API double GetX();

	/// <summary>
	/// Get coordinate of ordinate.
	/// </summary>
	/// <returns>c</returns>
	CURVELIBRARY_API double GetY();

	/// <summary>
	/// Get coordinate of applicate.
	/// </summary>
	/// <returns>Z coordinate.</returns>
	CURVELIBRARY_API double GetZ();

	/// <summary>
	/// Set coordinate of abscissa.
	/// </summary>
	/// <param name="x">X coordinate.</param>
	CURVELIBRARY_API void SetX(double x);

	/// <summary>
	/// Set coordinate of ordinate.
	/// </summary>
	/// <param name="y">Y coordinate.</param>
	CURVELIBRARY_API void SetY(double y);

	/// <summary>
	/// Set coordinate of applicate.
	/// </summary>
	/// <param name="z">Z coordinate.</param>
	CURVELIBRARY_API void SetZ(double z);

#pragma endregion


private:
	/// <summary>
	/// Coordinates.
	/// </summary>
	double x, y, z;
};


/// <summary>
/// Abstract curve in 3D space.
/// </summary>
extern CURVELIBRARY_API class Curve3D
{
public:
	/// <summary>
	/// Get point of curve at  <paramref name="t"/>.
	/// </summary>
	/// <param name="t">Parameter.</param>
	/// <returns>Point.</returns>
	CURVELIBRARY_API virtual Point3D getPoint(double t) const = 0;

	/// <summary>
	/// Get derivative of curve at <paramref name="t"/>.
	/// </summary>
	/// <param name="t">Parameter.</param>
	/// <returns>Derivative.</returns>
	CURVELIBRARY_API virtual Point3D getDerivative(double t) const = 0;
};


/// <summary>
/// Circle in 3D space.
/// </summary>
extern CURVELIBRARY_API class Circle : public Curve3D
{
public:
	/// <summary>
	/// Default constructor that sets radius value.
	/// </summary>
	/// <param name="radius">Radius value.</param>
	CURVELIBRARY_API Circle(double radius);

#pragma region Methods

	/// <summary>
	/// Get point of circle at  <paramref name="t"/>.
	/// </summary>
	/// <param name="t">Parameter.</param>
	/// <returns>Point.</returns>
	CURVELIBRARY_API Point3D getPoint(double t) const override;

	/// <summary>
	/// Get derivative of circle at <paramref name="t"/>.
	/// </summary>
	/// <param name="t">Parameter.</param>
	/// <returns>Derivative.</returns>
	CURVELIBRARY_API Point3D getDerivative(double t) const override;

#pragma endregion


#pragma region Getters and Setters

	/// <summary>
	/// Get radius value.
	/// </summary>
	/// <returns>Length of radius.</returns>
	CURVELIBRARY_API double GetRadius();

	/// <summary>
	/// Set radius value.
	/// </summary>
	/// <param name="radius">Radius value.</param>
	CURVELIBRARY_API void SetRadius(double radius);

#pragma endregion


private:
	/// <summary>
	/// Radius length.
	/// </summary>
	double radius;
};


/// <summary>
/// Ellipse in 3D space.
/// </summary>
extern CURVELIBRARY_API class Ellipse : public Curve3D
{
public:
	/// <summary>
	/// Default constructor that sets axises value.
	/// </summary>
	/// <param name="majorAxis"></param>
	/// <param name="minorAxis"></param>
	CURVELIBRARY_API Ellipse(double majorAxis, double minorAxis);


#pragma region Methods

	/// <summary>
	/// Get point of ellipse at  <paramref name="t"/>.
	/// </summary>
	/// <param name="t">Parameter.</param>
	/// <returns>Point.</returns>
	CURVELIBRARY_API Point3D getPoint(double t) const override;

	/// <summary>
	/// Get derivative of ellipse at <paramref name="t"/>.
	/// </summary>
	/// <param name="t">Parameter.</param>
	/// <returns>Derivative.</returns>
	CURVELIBRARY_API Point3D getDerivative(double t) const override;

#pragma endregion


#pragma region Getters and Setters

	/// <summary>
	/// Get value of major axis.
	/// </summary>
	/// <returns>Length.</returns>
	CURVELIBRARY_API double GetMajorAxis();

	/// <summary>
	/// Set major axis value.
	/// </summary>
	/// <param name="length">Length of axis.</param>
	CURVELIBRARY_API void SetMajorAxis(double length);

	/// <summary>
	/// Get value of minor axis.
	/// </summary>
	/// <returns>Length.</returns>
	CURVELIBRARY_API double GetMinorAxis();

	/// <summary>
	/// Set minor axis value.
	/// </summary>
	/// <param name="length">Length of axis.</param>
	CURVELIBRARY_API void SetMinorAxis(double length);

#pragma endregion


private:
	/// <summary>
	/// Length of major axis.
	/// </summary>
	double majorAxis;

	/// <summary>
	/// Length of minor axis.
	/// </summary>
	double minorAxis;
};


/// <summary>
/// Helix in 3D space.
/// </summary>
extern CURVELIBRARY_API class Helix : public Curve3D
{
public:
	/// <summary>
	/// Default constructor that sets radius and pitch values.
	/// </summary>
	/// <param name="radius">Radius length.</param>
	/// <param name="pitch">Pitch length.</param>
	CURVELIBRARY_API Helix(double radius, double pitch);


#pragma region Methods

	/// <summary>
	/// Get point of helix at  <paramref name="t"/>.
	/// </summary>
	/// <param name="t">Parameter.</param>
	/// <returns>Point.</returns>
	CURVELIBRARY_API Point3D getPoint(double t) const override;

	/// <summary>
	/// Get derivative of helix at <paramref name="t"/>.
	/// </summary>
	/// <param name="t">Parameter.</param>
	/// <returns>Derivative.</returns>
	CURVELIBRARY_API Point3D getDerivative(double t) const override;

#pragma endregion


#pragma region Getters and Setters

	/// <summary>
	/// Get radius value.
	/// </summary>
	/// <returns>Radius length.</returns>
	CURVELIBRARY_API double GetRadius();

	/// <summary>
	/// Set radius value.
	/// </summary>
	/// <param name="radius">Radius value.</param>
	CURVELIBRARY_API void SetRadius(double radius);

	/// <summary>
	/// Get pitch value.
	/// </summary>
	/// <returns>Pitch length.</returns>
	CURVELIBRARY_API double GetPitch();

	/// <summary>
	/// Set pitch value.
	/// </summary>
	/// <param name="pitch">Pitch length.</param>
	CURVELIBRARY_API void SetPitch(double pitch);

#pragma endregion


private:
	/// <summary>
	/// Radius length.
	/// </summary>
	double radius;

	/// <summary>
	/// Pitch length.
	/// </summary>
	double pitch;
};


#endif // CURVELIBRARY
