#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>

#include <vector>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <limits>

#include "random.h"
#include "ray.h"
#include "camera.h"
#include "hittable_list.h"
#include "shapes/sphere.h"

float ray_hit_sphere(const vec3 &center, float radius, const ray &ray);
vec3 ray_color(const ray &ray, hittable *world);

vec3 random_in_unit_sphere();

int to_int(float f);

int main(int argc, char *argv[])
{
    const int WIDTH = 200;
    const int HEIGHT = 100;
    const int SAMPLE_COUNT = 100;
    const int CHANNEL_NUMBER = 3;

    std::vector<std::uint8_t> pixels(WIDTH * HEIGHT * CHANNEL_NUMBER);

    hittable *list[2];
    list[0] = new sphere(vec3{0.0f,0.0f,-1.0f}, 0.5f);
    list[1] = new sphere(vec3{0.0f,-100.5f,-1.0f}, 100.0f);
    hittable *world = new hittable_list(list,2);
    camera cam;

    int index;
    for (int j = HEIGHT - 1; j >= 0; j--)
    {
        for (int i = 0; i < WIDTH; i++)
        {
            vec3 color;
            for (int s = 0; s < SAMPLE_COUNT; s++) 
            {
                float u = float(i + random_double()) / float(WIDTH);
                float v = float(j + random_double()) / float(HEIGHT);
                ray r = cam.get_ray(u, v);

                color += ray_color(r, world);
            }

            color /= float(SAMPLE_COUNT);
            color = vec3{ std::sqrt(color.x), std::sqrt(color.y), std::sqrt(color.z) };

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

vec3 ray_color(const ray &r, hittable *world)
{
    hit_record rec;
    if (world->hit(r, 0.0, std::numeric_limits<float>::max(), rec)) 
    {
        vec3 target = rec.p + rec.normal + random_in_unit_sphere();
        return 0.5 * ray_color(ray{rec.p, target - rec.p}, world);
    } else 
    {
        vec3 unit_direction = normalise(r.direction);
        float t = 0.5f * (unit_direction.y + 1.0f);
        
        return (1.0f - t) * vec3{1.0f, 1.0f, 1.0f} + t * vec3{0.5f, 0.7f, 1.0f}; // lerp
    }

}

int to_int(float f)
{
    return int(255.99 * f);
}

vec3 random_in_unit_sphere()
{
    vec3 p;
    do 
    {
        p = 2.0f  * vec3 {float(random_double()), float(random_double()),float(random_double())} - vec3{1.0f, 1.0f, 1.0f};
    } while (p.length_squared() >= 1.0f);
    return p;
}