/*
** EPITECH PROJECT, 2019
** C++ Raytracer
** File description:
** Shape Abstract Class
*/

#ifndef SHAPE_HPP_
	#define SHAPE_HPP_

#include "IIntersectable.hpp"
#include "DataStruct.hpp"


class AShape: public IIntersectable {
	public:
		AShape(int const id);
		AShape(int const id, ShapeType type, vec3f_t pos, vec3f_t rot, Color::color col);

		virtual ~AShape() = default;

		int				getId() const;
		ShapeType		getType() const;
		std::string		getTypeName() const;
		Color::color	getColor() const;
		vec3f_t 		getPosition() const;
		vec3f_t			getRotation() const;
		void			setColor(const Color::color &color);
		void			setPosition(const vec3f_t &pos);
		void			setRotation(const vec3f_t &rot);

	protected:
		int				id;
		ShapeType		type;
		vec3f_t			position;
		vec3f_t			rotation;
		Color::color	color;
};

#endif /* !SHAPE_HPP_ */
