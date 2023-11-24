// normalisation

#include <sil/sil.hpp>


int main()
{
    sil::Image input_image{"images/photo.jpg"};
    sil::Image output_image{input_image};

    for (size_t x = 0; x < input_image.width(); x++)
    {
        for (size_t y = 0; y < input_image.height(); y++)
        {
            
        }
    }
    output_image.save("output/normalisation.png");
}



