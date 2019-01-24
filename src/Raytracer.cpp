/*
** EPITECH PROJECT, 2019
** C++ Raytracer
** File description:
** Raytracer Implémentation
*/

#include "Raytracer.hpp"

Raytracer::Raytracer(Scene &scene, Eye &eye):
myScene(scene), myEye(eye)
{
}

vec3f_t	Raytracer::calcDirVector(double dist, int screenWidth, int screenHeight, int x, int y)
{
	vec3f_t	coeff;

	coeff.x = dist;
	coeff.y = (screenWidth / 2) - x;
	coeff.z = (screenHeight / 2) - y;
	return (coeff);
}

Color::color	Raytracer::launchRay(DirectorVector &dirVector)
{
	std::vector<std::unique_ptr<AShape>>	&objs = myScene.getObjects();
	vec3f_t	objPos;
	vec3f_t objRot;
	vec3f_t	objPosRev;
	vec3f_t objRotRev;
	int		size = objs.size();
	int		indexSaved = -1;
	double	k = -1;
	double	savedK = -1;

	for (int i = 0; i < size; i++)
	{
		objPos = objs[i]->getPosition();
		objRot = objs[i]->getRotation();
		objPosRev = -objPos;
		objRotRev = -objRot;
		myEye.translate(objPosRev);
		myEye.rotate_xyz(objRotRev);
		dirVector.rotate_xyz(objRotRev);
		k = objs[i]->intersect(myEye.getPosition(), dirVector.getDirVector());
		if (k > 0)
			if (savedK < 0 || savedK > k) {
				savedK = k;
				indexSaved = i;
			}
		dirVector.rotate_xyz(objRot);
		myEye.rotate_xyz(objRot);
		myEye.translate(objPos);
	}
	if (indexSaved == -1)
		return (Color::Black);
	return (objs[indexSaved]->getColor());
}

std::vector<Color::color>	Raytracer::raytraceScene()
{
	DirectorVector dirVector(this->calcDirVector(this->myEye.getDistToScreen(), WIDTH, HEIGHT, 0, 0));
	std::vector<Color::color> pixels;

	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			dirVector.setDirVector(this->calcDirVector(this->myEye.getDistToScreen(), WIDTH, HEIGHT, x, y));
			pixels.push_back(this->launchRay(dirVector));
		}
	}
	return (pixels);
}