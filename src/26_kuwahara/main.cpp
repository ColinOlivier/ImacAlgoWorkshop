#include <sil/sil.hpp>
#include <array>
#include <vector>
#include "algorithm"
#include <iostream>

glm::vec3 getKuwaharaFilterValue(sil::Image &image, glm::vec2 position, int coeff);

int main()
{
    sil::Image input_image{"images/photo_blur.jpg"};
    sil::Image output_image{input_image};

    for (size_t x = 0; x < input_image.width(); ++x)
    {
        for (size_t y = 0; y < input_image.height(); ++y)
        {
            output_image.pixel(x, y) = getKuwaharaFilterValue(input_image, glm::vec2{x, y}, 7);
        }
    }

    output_image.save("output/kuwahara.jpg");
    return 0;
}

glm::vec3 getKuwaharaFilterValue(sil::Image &image, glm::vec2 position, int coeff)
{
    std::array<glm::vec2, 4> startPoints{
        glm::vec2{-(coeff / 2), -(coeff / 2)} + position,
        glm::vec2{0, -(coeff / 2)} + position,
        glm::vec2{0, 0} + position,
        glm::vec2{-(coeff / 2), 0} + position};

    std::array<std::vector<glm::vec3>, 4> values_scares{
        std::vector<glm::vec3>{},
        std::vector<glm::vec3>{},
        std::vector<glm::vec3>{},
        std::vector<glm::vec3>{}};

    std::array<glm::vec3, 4> average_scares;
    std::array<glm::vec3, 4> standard_deviation_scares;

    for (size_t i = 0; i < 4; ++i)
    {
        for (size_t x = 0; x < (coeff / 2) + 1; x++)
        {
            for (size_t y = 0; y < (coeff / 2) + 1; y++)
            {
                if (
                    startPoints[i].x + x < 0 ||
                    startPoints[i].x + x >= image.width() ||
                    startPoints[i].y + y < 0 ||
                    startPoints[i].y + y >= image.height())
                {
                    continue;
                }
                values_scares[i].push_back(image.pixel(startPoints[i].x + x, startPoints[i].y + y));
            }
        }

        glm::vec3 sum_scare{0.f};
        for (size_t j = 0; j < values_scares[i].size(); j++)
        {
            sum_scare += values_scares[i][j];
        }

        average_scares[i] = sum_scare / (float)(values_scares[i].size());

        glm::vec3 sum_standard_deviation{0.f};

        for (size_t j = 0; j < values_scares[i].size(); j++)
        {
            sum_standard_deviation += (values_scares[i][j] - average_scares[i]) * (values_scares[i][j] - average_scares[i]);
        }

        standard_deviation_scares[i].r = sqrt((sum_standard_deviation / (float)(values_scares[i].size())).r);
        standard_deviation_scares[i].g = sqrt((sum_standard_deviation / (float)(values_scares[i].size())).g);
        standard_deviation_scares[i].b = sqrt((sum_standard_deviation / (float)(values_scares[i].size())).b);
    }

    glm::vec3 min_standard_deviation{standard_deviation_scares[0]};
    int return_index{0};

    for (size_t i = 1; i < 4; i++)
    {
        if (glm::length(min_standard_deviation) > glm::length(standard_deviation_scares[i]))
        {
            min_standard_deviation = standard_deviation_scares[i];
            return_index = i;
        }
    }
    return average_scares[return_index];
}