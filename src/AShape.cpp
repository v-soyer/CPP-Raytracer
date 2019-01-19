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
id(id), type(SPHERE), position(0, 0, 0), rotation(0, 0, 0), color(Color::White)
{
}

AShape::AShape(int const id, ShapeType type, vec3f_t pos, vec3f_t rot, Color::color col):
id(id), type(type), position(pos.x, pos.y, pos.z), rotation(rot.x, rot.y, rot.z), color({col.r, col.g, col.b})
{
}

int	AShape::getId() const
{
	return(this->id);
}

ShapeType	AShape::getType() const
{
	return (this->type);
}

std::string	AShape::getTypeName() const
{
	switch (this->type) {
	case 1:	return ("PLANE");
	case 2: return ("SPHERE");
	case 3: return ("CYLINDER");
	case 4: return ("CONE");
	default: return ("UNKNOWN");
	}
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



