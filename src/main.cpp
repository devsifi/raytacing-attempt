#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>

#include <string>
#include <vector>
#include <limits>
#include <cstdint>

#include "vec3.h"
#include "sphere.h"

struct camera
{
    vec3 position;
    float fov;
};

vec3 cast_ray(ray r, sphere s);

void write_to_file(std::string path, std::vector<vec3>& framebuffer, int width, int height, int channels);
int to_int(float f);

int main(int argc, char *argv[])
{
    const int WIDTH = 1024;
    const int HEIGHT = 768;
    const float ASPECT_RATIO = float(WIDTH) / float(HEIGHT);
    const int CHANNELS = 3;

    std::vector<vec3> framebuffer(WIDTH * HEIGHT);
    camera cam;
    cam.position = { 0.f, 0.f, 0.f };
    cam.fov = 90.f;

    for (std::size_t j = 0; j < HEIGHT; j++)
    {
        for (std::size_t i = 0; i < WIDTH; i++)
        {
            float x =  (2.f * (i + .5f) / float(WIDTH) - 1) * std::tan(cam.fov / 2.f) * ASPECT_RATIO;
            float y = -(2.f * (j + .5f) / float(HEIGHT) - 1) * std::tan(cam.fov / 2.f);

            ray r;
            r.origin = { 0.f, 0.f, 0.f };
            r.direction =  normalise({x, y, -1.f});

            sphere s;
            s.center = { 0.f, 0.f, 5.f };
            s.radius =  3.f;

            framebuffer[i + j * WIDTH] = cast_ray(r, s);
        }
    }

    // Save Fraembuffer to file
    write_to_file("img/ray.jpg", framebuffer, WIDTH, HEIGHT, CHANNELS);

    return 0;
}

vec3 cast_ray(ray r, sphere s)
{
    float sphere_dist = std::numeric_limits<float>::max();
    if(ray_hit(s, r))
    {
        return { .3f, .7f,0.8f };
    }

    vec3 unit_direction = normalise(r.direction);
    float t = .5f * (unit_direction.y + 1.f);

    return (1.0f - t) * vec3{ 1.f, 1.f, 1.f } + t * vec3{ .5f, .7f, 1.f};
}

void write_to_file(std::string path, std::vector<vec3>& framebuffer, int width, int height, int channels)
{
    std::vector<std::uint8_t> pixels(width * height * channels);

    for (std::size_t i = 0; i < framebuffer.size(); i++)
    {
        pixels[i * 3] =     to_int(framebuffer[i].x);
        pixels[i * 3 + 1] = to_int(framebuffer[i].y);
        pixels[i * 3 + 2] = to_int(framebuffer[i].z);
    }    

    stbi_write_jpg(path.c_str(), width, height, channels, pixels.data(), 100);
}

int to_int(float f)
{
    return int(255.99 * f);
}