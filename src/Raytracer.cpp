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
	Color::color	newColor;
	std::vector<std::unique_ptr<AShape>>	&objs = myScene.getObjects();
	std::vector<std::unique_ptr<Light>>		&lights = myScene.getLights();
	vec3f_t	objPos;
	vec3f_t objRot;
	vec3f_t	objPosRev;
	vec3f_t objRotRev;
	vec3f_t interPoint;
	vec3f_t	lightPos;
	vec3f_t eyePos = myEye.getPosition();
	int		objSize = objs.size();
	int		lightSize = lights.size();
	int		indexSaved = -1;
	double	k = -1;
	double	savedK = -1;

	for (int i = 0; i < objSize; i++)
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
				interPoint.x = eyePos.x + (savedK * dirVector.getDirVector().x);
				interPoint.y = eyePos.y + (savedK * dirVector.getDirVector().y);
				interPoint.z = eyePos.z + (savedK * dirVector.getDirVector().z);
			}
		dirVector.rotate_zyx(objRot);
		myEye.rotate_zyx(objRot);
		myEye.translate(objPos);
	}
	if (indexSaved == -1)
		return (Color::Black);
	newColor = objs[indexSaved]->getColor();
	for (int i = 0; i < lightSize; i++) {
		lightPos.x = lights[i]->getPosition().x;
		lightPos.y = lights[i]->getPosition().y;
		lightPos.z = lights[i]->getPosition().z;
		newColor = objs[indexSaved]->applyLight(myEye, lightPos, interPoint, newColor);
	}
	return (newColor);
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