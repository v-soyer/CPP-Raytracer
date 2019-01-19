/*
** EPITECH PROJECT, 2019
** C++ Raytracer
** File description:
** Eye impl
*/

#include "Eye.hpp"

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

vec3f_t	Eye::getPosition()
{
    return(this->position);
}

vec3f_t	Eye::getRotation()
{
    return(this->rotation);
}

double	Eye::getDistToScreen()
{
    return(this->distToScreen);
}