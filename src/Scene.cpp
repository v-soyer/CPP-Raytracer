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
		vec3f_t pos = this->objects[i]->getPosition();
		vec3f_t rot = this->objects[i]->getRotation();
		Color::color col = this->objects[i]->getColor();

		std::cout << "This is object n°" << this->objects[i]->getId() << std::endl;
		std::cout << "Its postion is: X:" << pos.x << "  Y:" << pos.y << "  Z:" << pos.z << std::endl;
		std::cout << "Its rotation is: X:" << rot.x << "  Y:" << rot.y << "  Z:" << rot.z << std::endl;
		std::cout << "Its color is:  R:" << static_cast<int>(col.r) << "  G:" << static_cast<int>(col.g) << "  B:" << static_cast<int>(col.b) << std::endl;
	}
}