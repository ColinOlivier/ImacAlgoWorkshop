//ROSACE

#include <sil/sil.hpp>

void createCircle(sil::Image &image, float rayon, float epaisseur, int x, int y, int xCenter, int yCenter) // TRÈS IMPORTANT: Ne passez par & que les variables qui ont besoin d'être changées !!! Pour les autres, utilisez const& ou juste rien (aka passage par copie). Pour les petits objets (int, float, double bool, etc.) on préférera la copie, et pour les gros objets (std::vector, std::string, etc.) la const&
{
    float const distance { glm::distance(
                glm::vec2{x, y},            /*position d'1 pt random*/
                glm::vec2{xCenter,yCenter}  /*position du centre*/
            )};
            if (distance>rayon-epaisseur && distance<rayon){
            image.pixel(x,y)=glm::vec3{1.f};
            }
}

int main()
{
    sil::Image image{500/*width*/, 500/*height*/};
    float rayon{100};
    float epaisseur{9};
    int xCenter{image.width()/2};
    int yCenter{image.height()/2};
    for (int x{0}; x < (image.width()); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            createCircle(image, rayon, epaisseur, x, y, xCenter, yCenter);
            for(int i{1}; i<=6; i++)
            {
                int newCenterx(xCenter+rayon*cos((3.14)/3*i));
                int newCentery(yCenter+rayon*sin((3.14)/3*i));
                createCircle(image, rayon, epaisseur, x, y, newCenterx, newCentery); // J'apprécie beaucoup que vous ayez fait une fonction helper createCircle() ! Ca évite d'avoir du code dupliqué.
            }
        }
    }
    image.save("output/rosace.png");
}
