/*
** EPITECH PROJECT, 2019
** C++ raytracer
** File description:
** main fct
*/

#include "Scene.hpp"
#include "Sphere.hpp"
#include "Cylinder.hpp"

int main()
{
    Scene   myScene;

    myScene.addObject(std::move(std::make_unique<Sphere>(1)));
    myScene.displayObjectsInfo();
    std::cout <<"------------------------------------------------" << std::endl;
    myScene.addObject(std::move(std::make_unique<Cylinder>(2)));
    myScene.displayObjectsInfo();
    std::cout <<"------------------------------------------------" << std::endl;
    myScene.removeObject(1);
    myScene.displayObjectsInfo();
    return (0);
}