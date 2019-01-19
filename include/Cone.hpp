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
		~Cone() = default;

//		bool	intersect() const override;

		void	setSemiangle(const double semiangle);
		double	getSemiangle();

	private:
		double	semiangle;
};

#endif /* !CONE_HPP_ */
