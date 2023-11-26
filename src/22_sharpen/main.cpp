#include <sil/sil.hpp>

glm::vec3 getPixelSharpen(sil::Image &image, glm::ivec2 pixelPosition);
glm::vec3 multiplyPixelMatrix(sil::Image &image, const glm::ivec2 pixelPos, const glm::mat3 matrix);

int main()
{
    sil::Image input_image{"images/logo.png"};
    sil::Image output_image{input_image};

    for (size_t x = 0; x < input_image.width(); x++)
    {
        for (size_t y = 0; y < input_image.height(); y++)
        {
            output_image.pixel(x, y) = getPixelSharpen(input_image, glm::ivec2{x, y});
        }
    }

    output_image.save("output/sharpen.png");
}

glm::vec3 getPixelSharpen(sil::Image &image, glm::ivec2 pixelPosition)
{
    glm::mat3 kernel{
        0.f, -1.f, 0.f,
        -1.f, 5.f, -1.f,
        0.f, -1.f, 0.f};
    return multiplyPixelMatrix(image, pixelPosition, kernel);
}

glm::vec3 multiplyPixelMatrix(sil::Image &image, const glm::ivec2 pixelPos, const glm::mat3 matrix)
{
    glm::vec3 sum_color{0.f};

    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            if (
                pixelPos.x + i - 1 < 0 ||
                pixelPos.y + j - 1 < 0 ||
                pixelPos.x + i - 1 >= image.width() ||
                pixelPos.y + j - 1 >= image.height())
            {
                continue;
            }
            sum_color += image.pixel(pixelPos.x + i - 1, pixelPos.y + j - 1) * (float)(matrix[i][j]);
        }
    }
    return sum_color;
}
