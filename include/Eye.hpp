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

		void	translate(vec3f_t direction) override;
		void	rotate_x(float angle) override;
		void	rotate_y(float angle) override;
		void	rotate_z(float angle) override;
		void	rotate_xyz(vec3f_t angle) override;
		void	rotate_zyx(vec3f_t angle) override;

		void	setPosition(vec3f_t const &pos);
		void	setRotation(vec3f_t const &rot);
		void	setDistToScreen(double const dist);
		vec3f_t	getPosition() const;
		vec3f_t	getRotation() const;
		double	getDistToScreen() const;

	private:
		vec3f_t	position;
		vec3f_t	rotation;
		double	distToScreen;
};

#endif /* !EYE_HPP_ */
