/*
** EPITECH PROJECT, 2019
** C++ Raytracer
** File description:
** Cone impl
*/

#include <iostream>
#include "Cone.hpp"
#include "DataStruct.hpp"

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

void	Cone::displayInfo()
{
	vec3f_t pos = this->getPosition();
	vec3f_t rot = this->getRotation();
	Color::color col = this->getColor();

	std::cout << "This object is a Cone" << std::endl;
	std::cout << "Its postion is: X:" << pos.x << "  Y:" << pos.y << "  Z:" << pos.z << std::endl;
	std::cout << "Its rotation is: X:" << rot.x << "  Y:" << rot.y << "  Z:" << rot.z << std::endl;
	std::cout << "Its color is:  R:" << static_cast<int>(col.r) << "  G:" << static_cast<int>(col.g) << "  B:" << static_cast<int>(col.b) << std::endl;
}