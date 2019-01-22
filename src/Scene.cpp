/*
** EPITECH PROJECT, 2019
** C++ Raytracer
** File description:
** Scene impl
*/

#include "Scene.hpp"
#include "DataStruct.hpp"

Scene::Scene()
{
}

Scene::~Scene()
{
}

void	Scene::addObject(std::unique_ptr<AShape>&& obj)
{
	this->objects.push_back(std::move(obj));
}

void	Scene::addLight(std::unique_ptr<Light>&& light)
{
	this->lights.push_back(std::move(light));
}

void	Scene::removeObject(int const objId)
{
	this->objects.erase(std::remove_if(this->objects.begin(), this->objects.end(), [objId](auto&& obj) { return obj->getId() == objId; }), std::end(objects));
}

void	Scene::removeLight(int const lightId)
{
	this->lights.erase(std::remove_if(this->lights.begin(), this->lights.end(), [lightId](auto&& light) { return light->getId() == lightId; }), std::end(lights));
}

void	Scene::displayObjectsInfo()
{
	int size = this->objects.size();

	for (int i = 0; i < size; i++) {
		std::cout << "This is object n°" << this->objects[i]->getId() << std::endl;
		this->objects[i]->displayInfo();
		if (i + 1 != size)
			std::cout << std::endl;
	}
}