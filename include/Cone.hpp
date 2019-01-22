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
		Cone(int const id, vec3f_t pos, vec3f_t rot, double semiangle, Color::color col);
		~Cone() = default;

		void	displayInfo() override;

		double	intersect(vec3f_t eyePos, vec3f_t dir_vector) const override;

		void	setSemiangle(const double semiangle);
		double	getSemiangle();

	private:
		double	semiangle;
};

#endif /* !CONE_HPP_ */
