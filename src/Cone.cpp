/*
** EPITECH PROJECT, 2019
** C++ Raytracer
** File description:
** Cone impl
*/

#include "Cone.hpp"

Cone::Cone(int const id):
AShape(id)
{
}

Cone::Cone(int const id, vec3f_t pos, vec3f_t rot, Color::color col):
AShape(id, pos, rot, col)
{
}

void	Cone::setSemiangle(const double semiangle)
{
	this->semiangle = semiangle;
}

double	Cone::getSemiangle()
{
	return (this->semiangle);
}