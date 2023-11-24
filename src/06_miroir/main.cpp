// MIROIR

#include <sil/sil.hpp>

int main()
{
    sil::Image image{"images/logo.png"};
    sil::Image copie{image};/*on crée une copie de l'image pour garder les pixels d'origines!!*/
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
           image.pixel(x, y)=copie.pixel(image.width()-1-x, y);
        }
    }
    image.save("output/miroir.png");
}

//LOUPE CAAC
// int main()
// {
//     sil::Image image{"images/logo.png"};
//     for (int x{0}; x < image.width(); x++)
//     {
//         for (int y{0}; y < image.height(); y++)
//         {
//            image.pixel(x, y)=image.pixel(image.width()-1-x, y);
//         }
//     }
//     image.save("output/miroircaac.png");
// }