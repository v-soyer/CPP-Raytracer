/*
** EPITECH PROJECT, 2019
** C++ Raytracer
** File description:
** Sphere Class
*/

#ifndef SPHERE_HPP_
	#define SPHERE_HPP_

#include "AShape.hpp"

class Sphere: public AShape {
	public:
		Sphere(const int id);
		Sphere(int const id, vec3f_t pos, vec3f_t rot, Color::color col);
		~Sphere() = default;

//		bool	intersect() const override;

		void	setRadius(const double radius);
		double	getRadius();

	private:
		double radius;
};

#endif /* !SPHERE_HPP_ */
