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

class Light: public ITransformable {
	public:
		Light(int const id);

		int		getId() const;
		vec3f_t	getPosition() const;
		void	setPosition(vec3f_t const &pos);

	private:
		int		id;
		vec3f_t	position;
};

#endif /* !LIGHT_HPP_ */
