/*
** EPITECH PROJECT, 2019
** C++ Raytracer
** File description:
** 
*/

#ifndef EYE_HPP_
	#define EYE_HPP_

#include "DataStruct.hpp"
#include "ITransformable.hpp"

class Eye: public ITransformable {
	public:
		void	setPosition(vec3f_t const &pos);
		void	setRotation(vec3f_t const &rot);
		void	setDistToScreen(double const dist);
		vec3f_t	getPosition();
		vec3f_t	getRotation();
		double	getDistToScreen();

	private:
		vec3f_t	position;
		vec3f_t	rotation;
		double	distToScreen;
};

#endif /* !EYE_HPP_ */
