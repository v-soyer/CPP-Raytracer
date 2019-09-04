/*
** EPITECH PROJECT, 2019
** C++ Raytracer
** File description:
** DirectorVector implémentation
*/

#include "DirectorVector.hpp"
#define RAD(angle) ((angle) * M_PI / 180)

DirectorVector::DirectorVector(vec3f_t vector):
dirVector(vector)
{
}

DirectorVector::~DirectorVector()
{
}

void	DirectorVector::rotate_x(float angle)
{
	vec3f_t tmp;

	tmp.x = this->dirVector.x;
	tmp.y = (this->dirVector.y * cos(RAD(angle))) - (this->dirVector.z * sin(RAD(angle)));
	tmp.z = (this->dirVector.y * sin(RAD(angle))) + (this->dirVector.z * cos(RAD(angle)));
	this->dirVector = tmp;
}

void	DirectorVector::rotate_y(float angle)
{
	vec3f_t tmp;

	tmp.x = (this->dirVector.x * cos(RAD(angle))) + (this->dirVector.z * sin(RAD(angle)));
	tmp.y = this->dirVector.y;
	tmp.z = -(this->dirVector.x * sin(RAD(angle))) + (this->dirVector.z * cos(RAD(angle)));
	this->dirVector = tmp;
}

void	DirectorVector::rotate_z(float angle)
{
	vec3f_t tmp;

	tmp.x = (this->dirVector.x * cos(RAD(angle))) - (this->dirVector.y * sin(RAD(angle)));
	tmp.y = (this->dirVector.x * sin(RAD(angle))) + (this->dirVector.y * cos(RAD(angle)));
	tmp.z = this->dirVector.z;
	this->dirVector = tmp;
}
void	DirectorVector::rotate_xyz(vec3f_t &angle)
{
	this->rotate_x(angle.x);
	this->rotate_y(angle.y);
	this->rotate_z(angle.z);
}

void	DirectorVector::rotate_zyx(vec3f_t &angle)
{
	this->rotate_z(angle.z);
	this->rotate_y(angle.y);
	this->rotate_x(angle.x);
}

void    DirectorVector::setDirVector(vec3f_t vector)
{
	this->dirVector.x = vector.x;
	this->dirVector.y = vector.y;
	this->dirVector.z = vector.z;
}

void	DirectorVector::translate(vec3f_t &direction)
{
	this->dirVector.x += direction.x;
	this->dirVector.y += direction.y;
	this->dirVector.z += direction.z;
}

vec3f_t	DirectorVector::getDirVector() const
{
	return (this->dirVector);
}

vec3f_t	DirectorVector::getNormalised() const
{
	double	len;
	vec3f_t	normed;

	len = sqrt(pow(this->dirVector.x, 2) + pow(this->dirVector.y, 2) + pow(this->dirVector.z, 2));
	if (len == 0)
		return (this->dirVector);
	normed.x = this->dirVector.x / len;
	normed.y = this->dirVector.y / len;
	normed.z = this->dirVector.z / len;
	return (normed);
}