#include <sil/sil.hpp>


int main()
{
    sil::Image input_image{"images/photo.jpg"};
    sil::Image output_image{input_image};
    const int bayer_n = 4;
    float bayer_matrix_4x4[][bayer_n] = {
        {    -0.5,       0,  -0.375,   0.125 },
        {    0.25,   -0.25,   0.375, - 0.125 },
        { -0.3125,  0.1875, -0.4375,  0.0625 },
        {  0.4375, -0.0625,  0.3125, -0.1875 },
    };

    for (size_t x = 0; x < input_image.width(); x++)
    {
        for (size_t y = 0; y < input_image.height(); y++)
        {
            glm::vec3 color = input_image.pixel(x, y); /*définition color*/
            glm::vec3 color_result =  glm::vec3{0.f};  /*définition color_result*/
            
            /*passer l'image en n&b*/
            float const niveau_de_gris{(color.r+color.b+color.g)/3};
            output_image.pixel(x,y)= glm::vec3{niveau_de_gris, niveau_de_gris, niveau_de_gris}; 
            
            /*creation de la matrice de bayer et calcul de l'output color*/
            float bayer_value = bayer_matrix_4x4[y % bayer_n][x % bayer_n];
            float output_color = glm::length(output_image.pixel(x,y)) + (3 * bayer_value);  

            /*condition pour être en blanc*/
            if (output_color > (1.f / 2.f)) {
                color_result =  glm::vec3{1.f};
            }
            
            output_image.pixel(x,y) = color_result;
        }
    }
    output_image.save("output/tramage.png");
}



