/*
** EPITECH PROJECT, 2019
** C++ Raytracer
** File description:
** Director Vector class
*/

#ifndef DIRECTORVECTOR_HPP_
	#define DIRECTORVECTOR_HPP_

#include "ITransformable.hpp"
#include "DataStruct.hpp"

class DirectorVector {
	public:
		DirectorVector(vec3f_t vector);
		~DirectorVector();

		void    setDirVector(vec3f_t vector);
		vec3f_t	getDirVector() const;

		void	rotate_x(float angle);
		void	rotate_y(float angle);
		void	rotate_z(float angle);
		void	rotate_xyz(vec3f_t &angle);
		void	rotate_zyx(vec3f_t &sangle);
		void	translate(vec3f_t &direction);

		vec3f_t	getNormalised() const;

	private:
		vec3f_t		dirVector;
};

#endif /* !DIRECTORVECTOR_HPP_ */
