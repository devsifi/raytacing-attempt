#include "ray.h"

ray::ray(const vec3 &origin, const vec3 &direction)
    :   origin(origin),
        direction(direction)
{
}

vec3 ray::point_at_param(float t) const
{
    return origin + (t * direction);
}

// vec3 raycast(const vec3 &position, const vec3 &direction, float t)
// {
//     return position + (t * direction);
// };