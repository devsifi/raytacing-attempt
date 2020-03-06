#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>

#include <vector>
#include <cstdint>

int to_int(float f);

int main(int argc, char *argv[])
{
    const int WIDTH = 200;
    const int HEIGHT = 100;
    const int CHANNEL_NUMBER = 3;

    std::vector<std::uint8_t> pixels(WIDTH * HEIGHT * CHANNEL_NUMBER);

    int index;
    for (int j = HEIGHT - 1; j >= 0; j--)
    {
        for (int i = 0; i < WIDTH; i++)
        {
            float r = float(i) / float(WIDTH);
            float g = float(j) / float(HEIGHT);
            float b = 0.2f;

            pixels[index++] = to_int(r);
            pixels[index++] = to_int(g);
            pixels[index++] = to_int(b);
        }
    }

    stbi_write_jpg("out/ray.jpg", WIDTH, HEIGHT, CHANNEL_NUMBER, pixels.data(), 100);
    return 0;
}

int to_int(float f)
{
    return int(255.99 * f);
}