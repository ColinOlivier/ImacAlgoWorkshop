#include <sil/sil.hpp>
#include <glm/gtx/matrix_transform_2d.hpp>

glm::vec2 rotated(glm::vec2 point, glm::vec2 center_of_rotation, float angle);

int main()
{
    sil::Image input_image{"images/logo.png"};
    sil::Image output_image{input_image.width() * 2, input_image.height() * 2};

    glm::vec2 image_center{input_image.width() / 2, input_image.height() / 2};

    for (size_t x = 0; x < input_image.width(); ++x)
    {
        for (size_t y = 0; y < input_image.height(); ++y)
        {
            glm::vec2 currentPos{x, y};
            glm::vec2 rotated_output{rotated(currentPos, image_center, glm::length(currentPos - image_center) * 0.05f) * 2.f};
            if (
                rotated_output.x > 0 &&
                rotated_output.y > 0 &&
                rotated_output.x < output_image.width() &&
                rotated_output.y < output_image.height())
            {
                output_image.pixel(rotated_output.x, rotated_output.y) = input_image.pixel(x, y);
            }
        }
    }

    output_image.save("output/vortex.png");
}

glm::vec2 rotated(glm::vec2 point, glm::vec2 center_of_rotation, float angle)
{
    return glm::vec2{glm::rotate(glm::mat3{1.f}, angle) * glm::vec3{point - center_of_rotation, 0.f}} + center_of_rotation;
}
