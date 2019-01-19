/*
** EPITECH PROJECT, 2019
** C++ Raytracer
** File description:
** AShape impl
*/

#include <array>
#include "AShape.hpp"
#include "DataStruct.hpp"

AShape::AShape(int const id):
id(id), position(0, 0, 0), rotation(0, 0, 0), color(Color::White)
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


