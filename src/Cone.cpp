/*
** EPITECH PROJECT, 2019
** C++ Raytracer
** File description:
** Cone impl
*/

#include <iostream>
#include "Cone.hpp"
#include "DataStruct.hpp"
#include "DeltaHandler.hpp"

Cone::Cone(int const id):
AShape(id), semiangle(50)
{
}

Cone::Cone(int const id, vec3f_t const &pos, vec3f_t const &rot, double semiangle, Color::color const &col):
AShape(id, pos, rot, col), semiangle(semiangle)
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

double	Cone::intersect(vec3f_t const &eyePos, vec3f_t const &dirVector) const
{
	vec3f_t			coeff;
	DeltaHandler	delta;
	double			semiangle = this->semiangle * M_PI / 180;

	if (this->semiangle == 90 || this->semiangle <= 0)
		return (0.0);
	coeff.x = pow(dirVector.x, 2) + pow(dirVector.y, 2) - (pow(dirVector.z, 2) * pow(tan(semiangle), 2));
	coeff.y = (2 * eyePos.x * dirVector.x) + (2 * eyePos.y * dirVector.y) - ((2 * eyePos.z * dirVector.z) * pow(tan(semiangle), 2));
	coeff.z = pow(eyePos.x, 2) + pow(eyePos.y, 2) - (pow(eyePos.z, 2) * pow(tan(semiangle), 2));
	return (delta.calcDelta(coeff));
}

void	Cone::displayInfo()
{
	vec3f_t pos = this->getPosition();
	vec3f_t rot = this->getRotation();
	Color::color col = this->getColor();

	std::cout << "This object is a Cone with a semiangle of " << this->semiangle <<std::endl;
	std::cout << "Its postion is: X:" << pos.x << "  Y:" << pos.y << "  Z:" << pos.z << std::endl;
	std::cout << "Its rotation is: X:" << rot.x << "  Y:" << rot.y << "  Z:" << rot.z << std::endl;
	std::cout << "Its color is:  R:" << static_cast<int>(col.r) << "  G:" << static_cast<int>(col.g) << "  B:" << static_cast<int>(col.b) << std::endl;
}