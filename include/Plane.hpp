/*
** EPITECH PROJECT, 2019
** C++ Raytracer
** File description:
** Plane Class
*/

#ifndef PLANE_HPP_
	#define PLANE_HPP_

#include "AShape.hpp"

class Plane: public AShape {
	public:
		Plane(const int id);
		~Plane() = default;

//		bool	intersect() const override;
};

#endif /* !PLANE_HPP_ */