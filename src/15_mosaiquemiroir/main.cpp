// MOSAIQUE INVERSEE

#include <sil/sil.hpp>

int main()
{
    sil::Image image{"images/logo.png"};
    sil::Image mosaique{5 * image.width(), 5 * image.height()}; /*on veut une mosaique de 5x5*/

    for (int x{0}; x < (mosaique.width()); x++)
    {
        for (int y{0}; y < mosaique.height(); y++)
        {
            // Vous pouvez écrire le code plus simplement, avec moins de if et moins de code dupliqué :
            int actual_x;
            int actual_y;
            if (x % (image.width() * 2) < image.width())
            {
                actual_x = x % image.width();
            }
            else
            {
                actual_x = image.width() - 1 - (x % image.width());
            }
            if (y % (image.height() * 2) < image.height())
            {
                actual_y = y % image.height();
            }
            else
            {
                actual_y = image.height() - 1 - (y % image.height());
            }
            mosaique.pixel(x, y) = image.pixel(actual_x, actual_y);
        }
    }
    mosaique.save("output/mosaiquemiroir.png");
}