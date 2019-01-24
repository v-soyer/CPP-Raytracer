/*
** EPITECH PROJECT, 2019
** C++ Raytracer
** File description:
** DeltaHandler
*/

#ifndef DELTAHANDLER_HPP_
	#define DELTAHANDLER_HPP_

#include "DataStruct.hpp"

class DeltaHandler {
	public:
		DeltaHandler() = default;
		~DeltaHandler() = default;

		double calcDelta(vec3f_t &coeff) const;
		double equalZero(vec3f_t &coeff) const;
		double superiorZero(double delta, vec3f_t &coeff) const;
};

#endif /* !DELTAHANDLER_HPP_ */
