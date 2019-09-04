/*
** EPITECH PROJECT, 2019
** C++ Raytracer
** File description:
** Shape Abstract Class
*/

#ifndef SHAPE_HPP_
	#define SHAPE_HPP_

#include "IIntersectable.hpp"
#include "Eye.hpp"
#include "DirectorVector.hpp"
#include "DataStruct.hpp"


class AShape: public IIntersectable {
	public:
		AShape(int const id);
		AShape(int const id, vec3f_t const &pos, vec3f_t const &rot, Color::color const &col);

		virtual ~AShape() = default;
		virtual void 	displayInfo() = 0;

		int				getId() const;
		Color::color	getColor() const;
		vec3f_t 		getPosition() const;
		vec3f_t			getRotation() const;
		void			setColor(const Color::color &color);
		void			setPosition(const vec3f_t &pos);
		void			setRotation(const vec3f_t &rot);

		double			getLightCoeff(vec3f_t const &lightVec, vec3f_t const &interPoint);
		Color::color	applyLight(Eye &myEye, vec3f_t const &lightVector, vec3f_t const &interPoint, Color::color newColor) override;

	protected:
		int				id;
		vec3f_t			position;
		vec3f_t			rotation;
		Color::color	color;
};

#endif /* !SHAPE_HPP_ */
