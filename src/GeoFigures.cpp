#include "GeoFigures.h"

int compareDouble(double x) noexcept
{
	if (fabs(x) < EPS) return 0;
	if (x < 0) return -1;
	else return 1;
}