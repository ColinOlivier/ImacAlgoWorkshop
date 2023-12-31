#include <sil/sil.hpp>
#include <vector>
#include <algorithm>
#include <string>
#include "random.hpp"

int main()
{
    sil::Image image{"images/logo.png"};
    const size_t image_size{image.pixels().size()};

    size_t last_modif{0};

    while (last_modif < image_size)
    {
        int sort_size = random_int(1, 20);
        if (last_modif + sort_size > image_size)
        {
            sort_size = image_size - last_modif;
        }

        std::sort(
            image.pixels().begin() + last_modif,
            image.pixels().begin() + last_modif + sort_size,
            [](glm::vec3 const &color1, glm::vec3 const &color2)
            {
                return color1.r + color1.g + color1.b > color2.r + color2.g + color2.b;
            });

        last_modif += sort_size;
    }
    image.save("output/triPixels.png");
}