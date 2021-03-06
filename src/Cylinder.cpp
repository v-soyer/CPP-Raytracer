/*
** EPITECH PROJECT, 2019
** C++ Raytracer
** File description:
** Cylinder impl
*/

#include <iostream>
#include "Cylinder.hpp"
#include "DataStruct.hpp"
#include "DeltaHandler.hpp"

Cylinder::Cylinder(int const id):
AShape(id),radius(50)
{
}

Cylinder::Cylinder(int const id, vec3f_t const &pos, vec3f_t const &rot, double radius, Color::color const &col):
AShape(id, pos, rot, col), radius(radius)
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

double	Cylinder::intersect(vec3f_t const &eyePos, vec3f_t const &dirVector) const
{
	vec3f_t			coeff;
	DeltaHandler	delta;

	coeff.x = pow(dirVector.x, 2) + pow(dirVector.y, 2);
	coeff.y = (2 * eyePos.x * dirVector.x) + (2 * eyePos.y * dirVector.y);
	coeff.z = pow(eyePos.x, 2) + pow(eyePos.y, 2) - pow(this->radius, 2);
	return (delta.calcDelta(coeff));
}

vec3f_t	Cylinder::getNormal(vec3f_t const &intersectPoint, vec3f_t) const
{
	vec3f_t	tmp;

	tmp.x = intersectPoint.x;
	tmp.y = intersectPoint.y;
	tmp.z = 0;
	return (tmp);
}

void	Cylinder::displayInfo()
{
	vec3f_t pos = this->getPosition();
	vec3f_t rot = this->getRotation();
	Color::color col = this->getColor();

	std::cout << "This object is a Cylinder of radius " << this->radius << std::endl;
	std::cout << "Its postion is: X:" << pos.x << "  Y:" << pos.y << "  Z:" << pos.z << std::endl;
	std::cout << "Its rotation is: X:" << rot.x << "  Y:" << rot.y << "  Z:" << rot.z << std::endl;
	std::cout << "Its color is:  R:" << static_cast<int>(col.r) << "  G:" << static_cast<int>(col.g) << "  B:" << static_cast<int>(col.b) << std::endl;
}