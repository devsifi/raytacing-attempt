#pragma once

#include "vec3.h"

class ray
{
public:
    ray(const vec3 &origin, const vec3 &direction);
    vec3 point_at_param(float t) const;
    
    vec3 origin;
    vec3 direction;
};
