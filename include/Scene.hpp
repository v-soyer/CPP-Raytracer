/*
** EPITECH PROJECT, 2019
** C++ Raytracer
** File description:
** Shape Class
*/

#ifndef SCENE_HPP_
	#define SCENE_HPP_

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include "AShape.hpp"
#include "Light.hpp"

class Scene {
	public:
		Scene();
		~Scene();


		void	addObject(std::unique_ptr<AShape>&& obj);
		void	addLight(std::unique_ptr<Light>&& light);
		void	removeObject(int const objId);
		void	removeLight(int const lightId);

		void	displayObjectsInfo();

	private:
		std::vector<std::unique_ptr<AShape>>	objects;
		std::vector<std::unique_ptr<Light>>		lights;
};

#endif /* !SCENE_HPP_ */
