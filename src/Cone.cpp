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

void	Cone::setSemiangle(const double semiangle)
{
	this->semiangle = semiangle;
}

double	Cone::getSemiangle()
{
	return (this->semiangle);
}