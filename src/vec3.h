#pragma once

#include <stdexcept>
#include <cmath>

struct vec3
{
    union 
    {
        struct
        {
            float x;
            float y;
            float z;
        };
        struct
        {
            float array[3];
        };
    };

    float length() const;
    float length_squared() const;
};

float dot(const vec3 &, const vec3 &);
float length(const vec3 &);
float length_squared(const vec3 &);

vec3 normalise(const vec3 &);
vec3 cross(const vec3 &, const vec3 &);

vec3 operator+(const vec3 &, const vec3 &);
vec3 operator-(const vec3 &, const vec3 &);
vec3 operator*(const vec3 &, const vec3 &);
vec3 operator/(const vec3 &, const vec3 &);

vec3 operator+(const vec3 &, float);
vec3 operator-(const vec3 &, float);
vec3 operator*(const vec3 &, float);
vec3 operator/(const vec3 &, float);

vec3 operator+(float, const vec3 &);
vec3 operator-(float, const vec3 &);
vec3 operator*(float, const vec3 &);
vec3 operator/(float, const vec3 &);

vec3& operator+=(vec3 &, const vec3 &);
vec3& operator-=(vec3 &, const vec3 &);
vec3& operator*=(vec3 &, const vec3 &);
vec3& operator/=(vec3 &, const vec3 &);

vec3& operator+=(vec3 &, float);
vec3& operator-=(vec3 &, float);
vec3& operator*=(vec3 &, float);
vec3& operator/=(vec3 &, float);