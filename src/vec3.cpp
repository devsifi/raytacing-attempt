#include "vec3.h"

#include <cmath>

#pragma region  MEMBER FUNCTIONS

float vec3::length() const 
{
    return std::sqrt(
        x * x +
        y * y +
        z * z
    );
}


float vec3::length_squared() const 
{
    return  x * x +
            y * y +
            z * z;
}

#pragma endregion

#pragma region  NON-MEMBER FUNCTIONS

float dot(const vec3 &a, const vec3 &b)
{
    return  a.x * b.x +
            a.y * b.y +
            a.z * b.z;
}

vec3 normalise(const vec3 &vec)
{
    return vec / vec.length();
}

vec3 cross(const vec3 &a, const vec3 &b)
{
    return { 
        a.y  * b.z - a.z * b.y,
        a.z  * b.x - a.x * b.z,
        a.x  * b.y - a.y * b.x,
    };
}

#pragma endregion

#pragma region  OPERATOR OVERLOADING FUNCTIONS

vec3 operator+(const vec3 &a, const vec3 &b)
{
    return {
        a.x + b.x, 
        a.y + b.y, 
        a.z + b.z
    };
}

vec3 operator-(const vec3 &a, const vec3 &b)
{
    return {
        a.x - b.x, 
        a.y - b.y, 
        a.z - b.z
    };
}

vec3 operator*(const vec3 &a, const vec3 &b)
{
    return {
        a.x * b.x,
        a.y * b.y,
        a.z * b.z
    };
}

vec3 operator/(const vec3 &a, const vec3 &b)
{
    return {
        a.x / b.x,
        a.y / b.y,
        a.z / b.z
    };
}

vec3& operator+=(vec3 &a, const vec3 &b)
{
    
    a.x += b.x;
    a.y += b.y; 
    a.z += b.z;

    return a;
}

vec3& operator-=(vec3 &a, const vec3 &b)
{
    a.x -= b.x;
    a.y -= b.y; 
    a.z -= b.z;

    return a;
}

vec3& operator*=(vec3 &a, const vec3 &b)
{
    a.x *= b.x;
    a.y *= b.y; 
    a.z *= b.z;

    return a;
}

vec3& operator/=(vec3 &a, const vec3 &b)
{
    a.x /= b.x;
    a.y /= b.y; 
    a.z /= b.z;

    return a;
}

vec3& operator+=(vec3 &a, float f)
{
    
    a.x += f;
    a.y += f;
    a.z += f;

    return a;
}

vec3& operator-=(vec3 &a, float f)
{
    a.x -= f;
    a.y -= f;
    a.z -= f;

    return a;
}

vec3& operator*=(vec3 &a, float f)
{
    a.x *= f;
    a.y *= f;
    a.z *= f;

    return a;
}

vec3& operator/=(vec3 &a, float f)
{
    a.x /= f;
    a.y /= f;
    a.z /= f;

    return a;
}

vec3 operator+(const vec3 &vec, const float f)
{
    return {
        vec.x + f, 
        vec.y + f, 
        vec.z + f
    };
}

vec3 operator-(const vec3 &vec, const float f)
{
    return {
        vec.x - f,
        vec.y - f,
        vec.z - f
    };
}

vec3 operator*(const vec3 &vec, const float f)
{
    return {
        vec.x * f,
        vec.y * f, 
        vec.z * f
    };
}

vec3 operator/(const vec3 &vec, const float f)
{
    return {
        vec.x / f, 
        vec.y / f, 
        vec.z / f
    };
}

vec3 operator+(const float f, const vec3 &vec)
{
    return {
        vec.x + f, 
        vec.y + f, 
        vec.z + f
    };
}

vec3 operator-(const float f, const vec3 &vec)
{
    return {
        vec.x - f, 
        vec.y - f, 
        vec.z - f
    };
}

vec3 operator*(const float f, const vec3 &vec)
{
    return {
        vec.x * f,
        vec.y * f,
        vec.z * f
    };
}

vec3 operator/(const float f, const vec3 &vec)
{
    return {
        vec.x / f, 
        vec.y / f, 
        vec.z / f
    };
}


#pragma endregion