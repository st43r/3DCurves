#include "pch.h"
#include "Validation.h"

#include <stdexcept>


void CheckLength(double length)
{
	if (length <= 0.)
	{
		throw std::out_of_range("Length must be positive.\n");
	}
};