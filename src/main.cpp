/*
** EPITECH PROJECT, 2019
** C++ raytracer
** File description:
** main fct
*/

#include <fstream>
#include "include/bitmap_image.hpp"
#include "DataStruct.hpp"
#include "Scene.hpp"
#include "Eye.hpp"
#include "Sphere.hpp"
#include "Cylinder.hpp"
#include "Plane.hpp"
#include "Cone.hpp"
#include "Raytracer.hpp"

int main()
{
	bitmap_image				img(WIDTH, HEIGHT);
	Scene						myScene;
	Eye							myEye(vec3f_t(-200,0,0), vec3f_t(0,0,0), 500);
	std::vector<Color::color>	pixels;
	int 						i = 0;
	myScene.addObject(std::move(std::make_unique<Sphere>(1, vec3f_t(0,0,0), vec3f_t(0,0,0), 50, Color::Red)));
	myScene.addObject(std::move(std::make_unique<Plane>(2, vec3f_t(0,0,-30), vec3f_t(0,0,0), Color::Blue)));
	myScene.addObject(std::move(std::make_unique<Cylinder>(3, vec3f_t(0,80,0), vec3f_t(20,20,20), 25, Color::Yellow)));
	myScene.addObject(std::move(std::make_unique<Cone>(4, vec3f_t(-95,-105,0), vec3f_t(0,0,0), 30, Color::Green)));
	myScene.addObject(std::move(std::make_unique<Plane>(5, vec3f_t(0,0,45), vec3f_t(0,0,0), Color::Blue)));
	myScene.addLight(std::move(std::make_unique<Light>(1, vec3f_t(-100, 0, 0))));

	Raytracer	rt(myScene, myEye);
	pixels = rt.raytraceScene();
	for (int y = 0; y < HEIGHT; y++)
		for (int x = 0; x < WIDTH; x++) {
			img.set_pixel(x, y, pixels[i].r, pixels[i].g, pixels[i].b);
			i += 1;
		}
	img.save_image("rt.bmp");
	return (0);
}

