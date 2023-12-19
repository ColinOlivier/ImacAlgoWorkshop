#include <sil/sil.hpp>


int main()
{
    sil::Image image{300/*width*/, 200/*height*/};
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            image.pixel(x, y) =  glm::vec3{x / static_cast<float>(image.width())}; // On préférera utiliser static_cast pour faire des conversions d'un type à l'autre
        }
    }
    
    image.save("output/degrade.png");
}