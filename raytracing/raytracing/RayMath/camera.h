#pragma once

#include "ray.h"

class Camera {
public:
	vec3 lowerLeftCorner;
	vec3 horizontal;
	vec3 vertical;
	vec3 origin;

	Camera() {
		lowerLeftCorner = vec3(-2.0, -1.0, -1.0);
		horizontal = vec3(4.0, 0.0, 0.0);
		vertical = vec3(0.0, 2.0, 0.0);
		origin = vec3(0.0, 0.0, 0.0);
	}

	Ray GetRay(float u, float v) {
		return Ray(origin, lowerLeftCorner + u * horizontal + v * vertical - origin);
	}
};