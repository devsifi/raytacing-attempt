#pragma once

#include "vec3.h"
#include "ray.h"

struct sphere
{
    vec3 center;
    float radius;
};

bool ray_hit(sphere s, ray r);