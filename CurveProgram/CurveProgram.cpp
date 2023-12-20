#include "CurveLibrary.h"
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <numeric>
#include <numbers>
#include <random>

#ifdef _OPENMP
#include <omp.h>
#endif


int main()
{

#pragma region Initialization

	std::vector<std::shared_ptr<Curve3D>> curves;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> radiusDistribution(1.5, 10.);
	std::normal_distribution<> pitchDistribution(0.5, 4.);


	while (true)
	{
		try
		{
			curves.push_back(std::make_shared<Circle>(radiusDistribution(gen)));
			curves.push_back(std::make_shared<Ellipse>(radiusDistribution(gen), radiusDistribution(gen)));
			curves.push_back(std::make_shared<Helix>(radiusDistribution(gen), pitchDistribution(gen)));

			break;
		}
		catch (const std::out_of_range& err)
		{
			std::cerr << "Exception caught: " << err.what();
		}
	}

#pragma endregion



#pragma region Derivatives

	double t = std::numbers::pi / 4.;


	for (const auto& curve : curves)
	{
		Point3D point = curve->GetPoint(t);
		Point3D derivative = curve->GetDerivative(t);

		std::cout << "Point: (" << point.GetX() << ", " << point.GetY() << ", " << point.GetZ() << ")\n";
		std::cout << "Derivative (vector coordinates): (" << derivative.GetX() << ", " << derivative.GetY() << ", " << derivative.GetZ() << ")\n";
	}

#pragma endregion



#pragma region Cast to circles

	std::vector<std::shared_ptr<Circle>> circles;

	for (const auto& curve : curves)
	{
		if (auto circle = std::dynamic_pointer_cast<Circle>(curve))
		{
			circles.push_back(circle);
		}
	}

	std::sort(circles.begin(), circles.end(),
		[](std::shared_ptr<Circle> a, std::shared_ptr<Circle> b)
		{
			return a.get()->GetRadius() < b.get()->GetRadius();
		});

#pragma endregion



#pragma region Parallel computin sum of radii

	double totalRadiusSum = 0.;

#ifdef _OPENMP
#pragma omp parallel for reduction(+:totalRadiusSum)
#endif

	for (const auto& circle : circles)
	{
		totalRadiusSum += circle->GetRadius();
	}

	std::cout << "Total sum of radii: " << totalRadiusSum << std::endl;

#pragma endregion


	return 0;
}


