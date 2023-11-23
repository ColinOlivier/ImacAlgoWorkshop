#include <sil/sil.hpp>
#include "random.hpp"

int main()
{
    sil::Image input_image{"images/logo.png"};
    sil::Image output_image{input_image};

    const glm::vec2 max_size_box{100, 20};

    for (size_t i = 0; i < 200; ++i)
    {
        glm::vec2 input_pos{random_int(0, input_image.width()), random_int(0, input_image.height())};
        glm::vec2 output_pos{random_int(0, input_image.width()), random_int(0, input_image.height())};
        glm::vec2 output_size{random_int(0, max_size_box.x), random_int(0, max_size_box.y)};

        for (size_t x = 0; x < output_size.x; ++x)
        {
            for (size_t y = 0; y < output_size.y; ++y)
            {
                if (
                    output_pos.x + x < output_image.width() &&
                    output_pos.y + y < output_image.height() &&
                    input_pos.x + x < input_image.width() &&
                    input_pos.y + y < input_image.height())
                {
                    output_image.pixel(output_pos.x + x, output_pos.y + y) = input_image.pixel(input_pos.x + x, input_pos.y + y);
                }
            }
        }
    }

    output_image.save("output/pouet.png");
}