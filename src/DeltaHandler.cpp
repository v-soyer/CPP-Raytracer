/*
** EPITECH PROJECT, 2019
** C++ raytracer
** File description:
** deltaHandler implémentation
*/

#include "DeltaHandler.hpp"

double DeltaHandler::calcDelta(vec3f_t &coeff) const
{
	double	delta;

	if (coeff.x == 0)
		return (-1.0);
	delta = pow(coeff.y, 2) - (4 * coeff.x * coeff.z);
	if (delta > 0)
		return (this->superiorZero(delta, coeff));
	else if (delta == 0)
		return (this->equalZero(coeff));
	else
		return (-1.0);
}

double DeltaHandler::equalZero(vec3f_t &coeff) const
{
	double x = 0;

	x = (-coeff.y / (2 * coeff.x));
	if (x > 0)
		return (x);
	else
		return (-1.0);
}

double DeltaHandler::superiorZero(double delta, vec3f_t &coeff) const
{
	double	x1;
	double	x2;

	x1 = ((-coeff.y - sqrt(delta)) / (2 * coeff.x));
	x2 = ((-coeff.y + sqrt(delta)) / (2 * coeff.x));
	if (x1 < 0 && x2 < 0)
		return (-1.0);
	else if (x1 > 0 && x2 < 0)
		return (x1);
	else if (x2 > 0 && x1 < 0)
		return (x2);
	else if (x1 > x2)
		return (x2);
	else if (x1 < x2)
		return (x1);
	else
		return (0.0);
}
