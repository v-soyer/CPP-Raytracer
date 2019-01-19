/*
** EPITECH PROJECT, 2019
** C++ Raytracer
** File description:
** Light impl
*/

#include "Light.hpp"

Light::Light(int const id):
id(id)
{
}

int		Light::getId() const
{
	return(this->id);
}

void	Light::setPosition(vec3f_t const &pos)
{
    this->position = pos;
}

vec3f_t	Light::getPosition() const
{
    return(this->position);
}