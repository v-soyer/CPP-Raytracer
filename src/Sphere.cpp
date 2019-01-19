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

Sphere::Sphere(int const id, vec3f_t pos, vec3f_t rot, Color::color col):
AShape(id, pos, rot, col)
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
