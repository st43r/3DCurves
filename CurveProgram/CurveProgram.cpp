#include "CurveLibrary.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <numbers>

#ifdef _OPENMP
#include <omp.h>
#endif


int main()
{
	std::vector<Curve3D*> curves;


	curves.push_back(new Circle(5.0));
	curves.push_back(new Ellipse(3.0, 2.0));
	curves.push_back(new Helix(2.0, 1.0));


	double t = std::numbers::pi / 4.0;

	for (const auto curve : curves)
	{
		Point3D point = curve->GetPoint(t);
		Point3D derivative = curve->GetDerivative(t);

		std::cout << "Point: (" << point.GetX() << ", " << point.GetY() << ", " << point.GetZ() << ")\n";
		std::cout << "Derivative (vector coordinates): (" << derivative.GetX() << ", " << derivative.GetY() << ", " << derivative.GetZ() << ")\n";
	}


	std::vector<Circle*> circles;

	for (const auto curve : curves)
	{
		if (Circle* circle = dynamic_cast<Circle*>(curve))
		{
			circles.push_back(circle);
		}
	}

	std::sort(circles.begin(), circles.end(),
		[](Circle* a, Circle* b)
		{
			return a->GetRadius() < b->GetRadius();
		});


	double totalRadiusSum = 0.0;

#ifdef _OPENMP
#pragma omp parallel for reduction(+:totalRadiusSum)
#endif

	for (size_t i = 0; i < circles.size(); ++i)
	{
		totalRadiusSum += circles[i]->GetRadius();
	}

	std::cout << "Total sum of radii: " << totalRadiusSum << std::endl;


	for (const auto curve : curves)
	{
		delete curve;
	}

	return 0;
}
