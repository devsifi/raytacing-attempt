#pragma once

#include <stdexcept>
#include <cmath>

struct vec3
{
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;

    float length() const;
    float length_squared() const;
};

float dot(const vec3 &, const vec3 &);

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