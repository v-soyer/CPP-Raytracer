/*
** EPITECH PROJECT, 2019
** C++ Raytracer
** File description:
** Transformable Interface
*/

#ifndef ITRANSFORMABLE_HPP_
	#define ITRANSFORMABLE_HPP_

#include "DataStruct.hpp"

class ITransformable {
	public:
		virtual ~ITransformable() = default;
		virtual void	translate(vec3f_t &direction) = 0;
		virtual void	rotate_x(float angle) = 0;
		virtual void	rotate_y(float angle) = 0;
		virtual void	rotate_z(float angle) = 0;
		virtual void	rotate_xyz(vec3f_t &angle) = 0;
		virtual void	rotate_zyx(vec3f_t &angle) = 0;
};

#endif /* !TRANSFORMABLE_HPP_ */
