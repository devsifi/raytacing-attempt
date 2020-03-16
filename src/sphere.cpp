#include "sphere.h"

#include <cmath>

bool ray_hit(sphere s, ray r)
{
    float t = dot(s.center - r.origin, r.direction);
    float y = length(s.center - point_at(r, t));
    float x = std::sqrt(s.radius * s.radius - y * y);

    if(x > s.radius) 
        return false;

    float t1 = t - x;
    float t2 = t + x;

    if(t1 < 0.f) t1 = t2;

    return (t1 < 0.f);
}