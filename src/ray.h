#pragma once

#include "vec3.h"

struct ray
{
    vec3 origin;
    vec3 direction;
};

vec3 point_at(ray r, float t);