#include <sil/sil.hpp>


int main()
{
    sil::Image image{300/*width*/, 200/*height*/};
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            image.pixel(x, y) =  glm::vec3{x / (float)(image.width())};
        }
    }
    
    image.save("output/degrade.png");
}