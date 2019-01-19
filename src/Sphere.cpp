/*
** EPITECH PROJECT, 2019
** C++ Raytracer
** File description:
** Sphere impl
*/

#include "Sphere.hpp"

Sphere::Sphere(int const id):
AShape(id)
{
}

void	Sphere::setRadius(const double radius)
{
	this->radius = radius;
}

double	Sphere::getRadius()
{
	return (this->radius);
}
