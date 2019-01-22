/*
** EPITECH PROJECT, 2019
** C++ Raytracer
** File description:
** Plane instance
*/

#include <iostream>
#include "Plane.hpp"
#include "DataStruct.hpp"

Plane::Plane(const int id):
AShape(id)
{
}

Plane::Plane(int const id, vec3f_t pos, vec3f_t rot, Color::color col):
AShape(id, pos, rot, col)
{
}

void	Plane::displayInfo()
{
	vec3f_t pos = this->getPosition();
	vec3f_t rot = this->getRotation();
	Color::color col = this->getColor();

	std::cout << "This object is a Plane" << std::endl;
	std::cout << "Its postion is: X:" << pos.x << "  Y:" << pos.y << "  Z:" << pos.z << std::endl;
	std::cout << "Its rotation is: X:" << rot.x << "  Y:" << rot.y << "  Z:" << rot.z << std::endl;
	std::cout << "Its color is:  R:" << static_cast<int>(col.r) << "  G:" << static_cast<int>(col.g) << "  B:" << static_cast<int>(col.b) << std::endl;
}