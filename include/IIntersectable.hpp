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
//		virtual bool intersect() const = 0;
};

#endif /* !INTERSECTABLE_HPP_ */
