/*
** EPITECH PROJECT, 2019
** C++ Raytracer
** File description:
** Sphere impl
*/

#include <iostream>
#include "Sphere.hpp"
#include "DataStruct.hpp"
#include "DeltaHandler.hpp"

Sphere::Sphere(int const id):
AShape(id), radius(50)
{
}

Sphere::Sphere(int const id, vec3f_t const &pos, vec3f_t const &rot, double radius, Color::color const &col):
AShape(id, pos, rot, col), radius(radius)
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

double	Sphere::intersect(vec3f_t const &eyePos, vec3f_t const &dirVector) const
{
	vec3f_t			coeff;
	DeltaHandler	delta;

	coeff.x = pow(dirVector.x, 2) + pow(dirVector.y, 2) + pow(dirVector.z, 2);
	coeff.y = (2 * eyePos.x * dirVector.x) + (2 * eyePos.y * dirVector.y) + (2 * eyePos.z * dirVector.z);
	coeff.z = (pow(eyePos.x, 2) + pow(eyePos.y, 2) + pow(eyePos.z, 2) - pow(radius, 2));
	return (delta.calcDelta(coeff));
}

void	Sphere::displayInfo()
{
	vec3f_t pos = this->getPosition();
	vec3f_t rot = this->getRotation();
	Color::color col = this->getColor();

	std::cout << "This object is a Sphere of radius " << this->radius << std::endl;
	std::cout << "Its postion is: X:" << pos.x << "  Y:" << pos.y << "  Z:" << pos.z << std::endl;
	std::cout << "Its rotation is: X:" << rot.x << "  Y:" << rot.y << "  Z:" << rot.z << std::endl;
	std::cout << "Its color is:  R:" << static_cast<int>(col.r) << "  G:" << static_cast<int>(col.g) << "  B:" << static_cast<int>(col.b) << std::endl;
}