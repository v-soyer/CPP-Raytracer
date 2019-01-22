/*
** EPITECH PROJECT, 2019
** C++ raytracer
** File description:
** main fct
*/

#include "DataStruct.hpp"
#include "Scene.hpp"
#include "Sphere.hpp"
#include "Cylinder.hpp"
#include "Plane.hpp"
#include "Cone.hpp"

int main()
{
    Scene   myScene;

    myScene.addObject(std::move(std::make_unique<Sphere>(1)));
    myScene.addObject(std::move(std::make_unique<Cylinder>(2, vec3f_t(100,100,100), vec3f_t(0,90,0), 30, Color::Yellow)));
    myScene.addObject(std::move(std::make_unique<Cone>(3, vec3f_t(75,150,45), vec3f_t(45,45,45), 45, Color::Green)));
    myScene.addObject(std::move(std::make_unique<Plane>(4, vec3f_t(0,0,-30), vec3f_t(0,0,0), Color::Blue)));
    myScene.displayObjectsInfo();
    return (0);
}