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
	this->dirVector.y = (this->dirVector.y * cos(RAD(angle))) - (this->dirVector.z * sin(RAD(angle)));
	this->dirVector.z = (this->dirVector.y * sin(RAD(angle))) + (this->dirVector.z * cos(RAD(angle)));
}

void	DirectorVector::rotate_y(float angle)
{
	this->dirVector.x = (this->dirVector.x * cos(RAD(angle))) + (this->dirVector.z * sin(RAD(angle)));
	this->dirVector.z = -(this->dirVector.x * sin(RAD(angle))) + (this->dirVector.z * cos(RAD(angle)));
}

void	DirectorVector::rotate_z(float angle)
{
	this->dirVector.x = (this->dirVector.x * cos(RAD(angle))) - (this->dirVector.y * sin(RAD(angle)));
	this->dirVector.y = (this->dirVector.x * sin(RAD(angle))) + (this->dirVector.y * cos(RAD(angle)));
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

vec3f_t	DirectorVector::getDirVector() const
{
	return (this->dirVector);
}