/*
** EPITECH PROJECT, 2019
** C++ Raytracer
** File description:
** Intersectable Interface
*/

#ifndef IINTERSECTABLE_HPP_
	#define IINTERSECTABLE_HPP_

#include "DataStruct.hpp"

class IIntersectable {
	public:
		virtual ~IIntersectable() = default;
		virtual double intersect(vec3f_t eyePos, vec3f_t dir_vector) const = 0;
};

#endif /* !INTERSECTABLE_HPP_ */
