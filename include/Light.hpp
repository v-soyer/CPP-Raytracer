/*
** EPITECH PROJECT, 2019
** C++ Raytracer
** File description:
** Light Class
*/

#ifndef LIGHT_HPP_
	#define LIGHT_HPP_

#include "ITransformable.hpp"
#include "DataStruct.hpp"

class Light {
	public:
		Light(int const id);
		Light(int const id, vec3f_t pos);

		int		getId() const;
		vec3f_t	getPosition() const;
		void	setPosition(vec3f_t const &pos);

	private:
		int		id;
		vec3f_t	position;
};

#endif /* !LIGHT_HPP_ */
