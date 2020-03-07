#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>

#include <vector>
#include <cmath>
#include <cstdint>
#include <iostream>

#include "ray.h"
#include "vec3.h"

float ray_hit_sphere(const vec3 &center, float radius, const ray &ray);
vec3 ray_color(const ray &r);

int to_int(float f);

int main(int argc, char *argv[])
{
    const int WIDTH = 200;
    const int HEIGHT = 100;
    const int CHANNEL_NUMBER = 3;

    std::vector<std::uint8_t> pixels(WIDTH * HEIGHT * CHANNEL_NUMBER);

    vec3 lower_left_corner{-2.0f, -1.0f, -1.0f};
    vec3 horizontal{4.0f, 0.0f, 0.0f};
    vec3 vertical{0.0f, 2.0f, 0.0f};
    vec3 origin{0.0f, 0.0f, 0.0f};

    int index;
    for (int j = HEIGHT - 1; j >= 0; j--)
    {
        for (int i = 0; i < WIDTH; i++)
        {
            float u = float(i) / float(WIDTH);
            float v = float(j) / float(HEIGHT);
            ray ray{origin, lower_left_corner + u * horizontal + v * vertical};
            vec3 color = ray_color(ray);

            pixels[index++] = to_int(color.x);
            pixels[index++] = to_int(color.y);
            pixels[index++] = to_int(color.z);
        }
    }

    stbi_write_jpg("out/ray.jpg", WIDTH, HEIGHT, CHANNEL_NUMBER, pixels.data(), 100);
    return 0;
}

float ray_hit_sphere(const vec3 &center, float radius, const ray &ray)
{
    vec3 oc = ray.origin - center;
    float a = dot(ray.direction, ray.direction);
    float b = 2.0f * dot(oc, ray.direction);
    float c = dot(oc, oc) - radius * radius;
    float discriminant = b * b - 4.0f * a * c;

    if (discriminant < 0.0f)
    {
        return -1.0f;
    }
    else
    {
        return (-b - std::sqrt(discriminant)) / (2.0f * a);
    }
}

vec3 ray_color(const ray &ray)
{
    float t = ray_hit_sphere({0.0f, 0.0f, -1.0f}, 0.5f, ray);
    if (t > 0.0f)
    {
        vec3 N = normalise(ray.point_at_param(t) - vec3{0.0f, 0.0f, -1.0f});
        return 0.5f * (N + 1);
    }

    vec3 unit_direction = normalise(ray.direction);
    t = 0.5f * (unit_direction.y + 1.0f);

    return (1.0f - t) * vec3{1.0f, 1.0f, 1.0f} + t * vec3{0.5f, 0.7f, 1.0f}; // lerp
}

int to_int(float f)
{
    return int(255.99 * f);
}