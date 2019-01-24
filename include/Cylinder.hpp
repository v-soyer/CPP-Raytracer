/*
** EPITECH PROJECT, 2019
** C++ Raytracer
** File description:
** Cylinder Class
*/

#ifndef CYLINDER_HPP_
	#define CYLINDER_HPP_

#include "AShape.hpp"

class Cylinder: public AShape {
	public:
		Cylinder(const int id);
		Cylinder(int const id, vec3f_t const &pos, vec3f_t const &rot, double radius, Color::color const &col);
		~Cylinder() = default;

		void	displayInfo() override;

		double	intersect(vec3f_t const &eyePos, vec3f_t const &dirVector) const override;

		void	setRadius(const double radius);
		double	getRadius();

	private:
		double	radius;
};

#endif /* !CYLINDER_HPP_ */
