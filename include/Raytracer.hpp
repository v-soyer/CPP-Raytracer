/*
** EPITECH PROJECT, 2019
** C++ Raytracer
** File description:
** Ratracer class
*/

#ifndef RAYTRACER_HPP_
	#define RAYTRACER_HPP_

#include <vector>
#include "Scene.hpp"
#include "Eye.hpp"
#include "DataStruct.hpp"
#include "DirectorVector.hpp"

class Raytracer {
	public:
		Raytracer(Scene &scene, Eye &eye);
		~Raytracer() = default;

		std::vector<Color::color>	raytraceScene();
		Color::color				launchRay(DirectorVector &dirVector);
		vec3f_t						calcDirVector(double dist, int screenWidth, int screenHeight, int x, int y);

	private:
		Scene		&myScene;
		Eye			&myEye;
};

#endif /* !RAYTRACER_HPP_ */
