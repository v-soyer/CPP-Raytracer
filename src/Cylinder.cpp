/*
** EPITECH PROJECT, 2019
** C++ Raytracer
** File description:
** Cylinder impl
*/

#include <iostream>
#include "Cylinder.hpp"
#include "DataStruct.hpp"

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

void	Cylinder::displayInfo()
{
	vec3f_t pos = this->getPosition();
	vec3f_t rot = this->getRotation();
	Color::color col = this->getColor();

	std::cout << "This object is a Cylinder" << std::endl;
	std::cout << "Its postion is: X:" << pos.x << "  Y:" << pos.y << "  Z:" << pos.z << std::endl;
	std::cout << "Its rotation is: X:" << rot.x << "  Y:" << rot.y << "  Z:" << rot.z << std::endl;
	std::cout << "Its color is:  R:" << static_cast<int>(col.r) << "  G:" << static_cast<int>(col.g) << "  B:" << static_cast<int>(col.b) << std::endl;
}