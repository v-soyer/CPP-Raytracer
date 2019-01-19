/*
** EPITECH PROJECT, 2019
** C++ Raytracer
** File description:
** Cylinder impl
*/

#include "Cylinder.hpp"

Cylinder::Cylinder(int const id):
AShape(id)
{
}

void	Cylinder::setRadius(const double radius)
{
	this->radius = radius;
}

double	Cylinder::getRadius()
{
	return (this->radius);
}
