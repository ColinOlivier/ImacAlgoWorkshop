#include <sil/sil.hpp>

int main()
{
    sil::Image image{"images/logo.png"};
   
    for (glm::vec3& color : image.pixels())
    {
        color = glm::vec3{1-color.r,1-color.g,1-color.b}; // Peut s'écrire plus simplement: color = 1.f - color;
    }
    image.save("output/negatif.png");
}