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

Cylinder::Cylinder(int const id, vec3f_t pos, vec3f_t rot, Color::color col):
AShape(id, pos, rot, col)
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
