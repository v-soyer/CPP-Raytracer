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
		Plane(int const id, vec3f_t const &pos, vec3f_t const &rot, Color::color const &col);
		~Plane() = default;

		void	displayInfo() override;

		double	intersect(vec3f_t const &eyePos, vec3f_t const &dirVector) const override;
};

#endif /* !PLANE_HPP_ */
