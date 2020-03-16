#include "ray.h"

vec3 point_at(ray r, float t)
{
    return r.origin + r.direction * t;
}