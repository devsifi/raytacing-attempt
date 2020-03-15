#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>

#include <string>
#include <vector>
#include <cstdint>

#include "vec3.h"

void write_to_file(std::string path, std::vector<vec3>& framebuffer, int width, int height, int channels);
int to_int(float f);

int main(int argc, char *argv[])
{
    const int WIDTH = 1024;
    const int HEIGHT = 768;
    const int CHANNELS = 3;

    std::vector<vec3> framebuffer(WIDTH * HEIGHT);

    for (std::size_t j = 0; j < HEIGHT; j++)
    {
        for (std::size_t i = 0; i < WIDTH; i++)
        {
            float u = float(i / float(WIDTH));
            float v = float(j / float(HEIGHT));
            framebuffer[i + j * WIDTH] = { u, v, 0 };
        }
    }

    // Save Fraembuffer to file
    write_to_file("out/ray.jpg", framebuffer, WIDTH, HEIGHT, CHANNELS);

    return 0;
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