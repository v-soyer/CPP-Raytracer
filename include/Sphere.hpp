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
		Sphere(int const id, vec3f_t const &pos, vec3f_t const  &rot, double radius, Color::color const &col);
		~Sphere() = default;

		void	displayInfo() override;

		double	intersect(vec3f_t const &eyePos, vec3f_t const &dirVector) const override;
		vec3f_t getNormal(vec3f_t const &intersectPoint, vec3f_t) const override;

		void	setRadius(const double radius);
		double	getRadius();

	private:
		double radius;
};

#endif /* !SPHERE_HPP_ */
