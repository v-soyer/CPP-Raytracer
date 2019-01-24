/*
** EPITECH PROJECT, 2019
** C++ Raytracer
** File description:
** Cone Class
*/

#ifndef CONE_HPP_
	#define CONE_HPP_

#include "AShape.hpp"

class Cone: public AShape {
	public:
		Cone(const int id);
		Cone(int const id, vec3f_t const &pos, vec3f_t const &rot, double semiangle, Color::color const &col);
		~Cone() = default;

		void	displayInfo() override;

		double	intersect(vec3f_t const &eyePos, vec3f_t const &dirVector) const override;

		void	setSemiangle(const double semiangle);
		double	getSemiangle();

	private:
		double	semiangle;
};

#endif /* !CONE_HPP_ */
