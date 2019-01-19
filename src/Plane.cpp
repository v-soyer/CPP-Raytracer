/*
** EPITECH PROJECT, 2019
** C++ Raytracer
** File description:
** Plane instance
*/

#include "Plane.hpp"
#include "DataStruct.hpp"

Plane::Plane(const int id):
AShape(id)
{
}

Plane::Plane(int const id, vec3f_t pos, vec3f_t rot, Color::color col):
AShape(id, PLANE, pos, rot, col)
{
}