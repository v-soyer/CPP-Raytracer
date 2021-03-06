/*
** EPITECH PROJECT, 2019
** C++ Raytracer
** File description:
** Eye impl
*/

#include "Eye.hpp"

#define RAD(angle) ((angle) * M_PI / 180)

Eye::Eye():
position(-100,0,0), rotation(0,0,0), distToScreen(50)
{
}

Eye::Eye(vec3f_t position, vec3f_t rotation, double dist):
position(position), rotation(rotation), distToScreen(dist)
{
}

void	Eye::setPosition(vec3f_t const &pos)
{
	this->position = pos;
}

void	Eye::setRotation(vec3f_t const &rot)
{
	this->rotation = rot;
}

void	Eye::setDistToScreen(double const dist)
{
	this->distToScreen = dist;
}

vec3f_t	Eye::getPosition() const
{
	return(this->position);
}

vec3f_t	Eye::getRotation() const
{
	return(this->rotation);
}

double	Eye::getDistToScreen() const
{
	return(this->distToScreen);
}

void	Eye::translate(vec3f_t &direction)
{
	this->position.x += direction.x;
	this->position.y += direction.y;
	this->position.z += direction.z;
}

void	Eye::rotate_x(float angle)
{
	vec3f_t tmp;

	tmp.x = this->rotation.x;
	tmp.y = (this->rotation.y * cos(RAD(angle))) - (this->rotation.z * sin(RAD(angle)));
	tmp.z = (this->rotation.y * sin(RAD(angle))) + (this->rotation.z * cos(RAD(angle)));
	this->rotation = tmp;
}

void	Eye::rotate_y(float angle)
{
	vec3f_t tmp;

	tmp.x = (this->rotation.x * cos(RAD(angle))) + (this->rotation.z * sin(RAD(angle)));
	tmp.y = this->rotation.y;
	tmp.z = -(this->rotation.x * sin(RAD(angle))) + (this->rotation.z * cos(RAD(angle)));
	this->rotation = tmp;
}

void	Eye::rotate_z(float angle)
{
	vec3f_t tmp;

	tmp.x = (this->rotation.x * cos(RAD(angle))) - (this->rotation.y * sin(RAD(angle)));
	tmp.y = (this->rotation.x * sin(RAD(angle))) + (this->rotation.y * cos(RAD(angle)));
	tmp.z = this->rotation.z;
	this->rotation = tmp;
}

void	Eye::rotate_xyz(vec3f_t &angle)
{
	this->rotate_x(angle.x);
	this->rotate_y(angle.y);
	this->rotate_z(angle.z);
}

void	Eye::rotate_zyx(vec3f_t &angle)
{
	this->rotate_z(angle.z);
	this->rotate_y(angle.y);
	this->rotate_x(angle.x);
}

