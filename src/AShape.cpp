/*
** EPITECH PROJECT, 2019
** C++ Raytracer
** File description:
** AShape impl
*/

#include <iostream>
#include <array>
#include "AShape.hpp"
#include "DataStruct.hpp"

AShape::AShape(int const id):
id(id), position(0, 0, 0), rotation(0, 0, 0), color(Color::White)
{
}

AShape::AShape(int const id, vec3f_t const &pos, vec3f_t const &rot, Color::color const &col):
id(id), position(pos.x, pos.y, pos.z), rotation(rot.x, rot.y, rot.z), color({col.r, col.g, col.b})
{
}

int	AShape::getId() const
{
	return(this->id);
}

Color::color AShape::getColor() const
{
	return(this->color);
}

vec3f_t AShape::getPosition() const
{
	return(this->position);
}

vec3f_t AShape::getRotation() const
{
	return(this->rotation);
}

void	AShape::setColor(const Color::color &color)
{
	this->color = color;
}

void	AShape::setPosition(const vec3f_t &pos)
{
	this->position = pos;
}

void	AShape::setRotation(const vec3f_t &rot)
{
	this->rotation = rot;
}

double	AShape::getLightCoeff(vec3f_t const &lightVec, vec3f_t const &normal)
{
	vec3f_t tmp;
	double	coeff;

	tmp.x = normal.x * lightVec.x;
	tmp.y = normal.y * lightVec.y;
	tmp.z = normal.z * lightVec.z;
	coeff = tmp.x + tmp.y + tmp.z;
	if (coeff < 0)
		return (0.0);
	else if (coeff > 1)
		return (1);
	else
		return (coeff);
}

Color::color	AShape::applyLight(Eye &myEye,vec3f_t const &lightVector, vec3f_t const &interPoint, Color::color newColor)
{
	vec3f_t			objPos = this->getPosition();
	vec3f_t			objRot = this->getRotation();
	vec3f_t			objPosRev = -objPos;
	vec3f_t			objRotRev = -objRot;
	vec3f_t	tmp;
	DirectorVector	myLight(lightVector);
	DirectorVector	normal(this->getNormal(interPoint, myEye.getPosition()));
	double			coeff;

	myEye.translate(objPosRev);
	myEye.rotate_xyz(objRotRev);
	myLight.translate(objPosRev);
	myLight.rotate_xyz(objRotRev);
	tmp.x = myLight.getDirVector().x - interPoint.x;
	tmp.y = myLight.getDirVector().y - interPoint.y;
	tmp.z = myLight.getDirVector().z - interPoint.z;
	DirectorVector	lightVec(tmp);
	coeff = this->getLightCoeff(lightVec.getNormalised(), normal.getNormalised());
//	std::cout << coeff << std::endl;
	newColor.r = newColor.r * coeff;
	newColor.g = newColor.g * coeff;
	newColor.b = newColor.b * coeff;
	myLight.rotate_zyx(objRot);
	myLight.translate(objPos);
	myEye.rotate_zyx(objRot);
	myEye.translate(objPos);
	return (newColor);
}


