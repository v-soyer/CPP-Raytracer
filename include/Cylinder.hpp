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
		Cylinder(int const id, vec3f_t pos, vec3f_t rot, Color::color col);
		~Cylinder() = default;

		void	displayInfo() override;

		void	setRadius(const double radius);
		double	getRadius();

	private:
		double	radius;
};

#endif /* !CYLINDER_HPP_ */
