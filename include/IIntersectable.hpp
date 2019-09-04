/*
** EPITECH PROJECT, 2019
** C++ Raytracer
** File description:
** Intersectable Interface
*/

#ifndef IINTERSECTABLE_HPP_
	#define IINTERSECTABLE_HPP_

#include "DataStruct.hpp"
#include "Eye.hpp"

class IIntersectable {
	public:
		virtual ~IIntersectable() = default;
		virtual double intersect(vec3f_t const &eyePos, vec3f_t const &dirVector) const = 0;
		virtual vec3f_t getNormal(vec3f_t const &intersectPoint, vec3f_t) const = 0;
		virtual Color::color applyLight(Eye &myEye, vec3f_t const &lightVector, vec3f_t const &interPoint, Color::color newColor) = 0;
};

#endif /* !INTERSECTABLE_HPP_ */
