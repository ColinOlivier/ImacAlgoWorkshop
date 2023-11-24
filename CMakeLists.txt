cmake_minimum_required(VERSION 3.20)

# You can set the name of your project here
project(ImageEditor)
# Download the sil library
include(FetchContent)
FetchContent_Declare(
    sil
    GIT_REPOSITORY https://github.com/JulesFouchy/Simple-Image-Lib
    GIT_TAG 89bd175cd55fb6daa9e99b218e869c3d516043f4
)
FetchContent_MakeAvailable(sil)
function(add_exercise FOLDER)
    add_executable(${FOLDER})

    # Choose your C++ version
    target_compile_features(${FOLDER} PRIVATE cxx_std_17)

    # Prevents compiler-specific extensions to C++ because they might allow code to compile on your machine but not on other people's machine
    set_target_properties(${FOLDER} PROPERTIES
        CXX_EXTENSIONS OFF)

    # Add all the source files
    file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/${FOLDER}/* lib/*)
    target_sources(${FOLDER} PRIVATE ${SOURCES})
    target_include_directories(${FOLDER} PRIVATE src/${FOLDER} lib)


    # Link sil into the project
    target_link_libraries(${FOLDER} PRIVATE sil)

endfunction(add_exercise)

add_exercise(01_gardervert)
add_exercise(02_echangercanaux)
add_exercise(03_nNb)
add_exercise(04_negatif)
add_exercise(05_degrade)
add_exercise(06_miroir)
add_exercise(07_bruit)
add_exercise(08_rotation90)
add_exercise(09_rgbsplit)
add_exercise(10_luminosite)
add_exercise(11_disque)
add_exercise(12_cercle)
add_exercise(13_rosace)
add_exercise(14_mosaique)
add_exercise(15_mosaiquemiroir)
add_exercise(16_glitch)
add_exercise(17_fractale)
add_exercise(18_vortex)
add_exercise(19_tramage)
add_exercise(21_convolution)
add_exercise(22_sharpen)
add_exercise(25_triPixels)
add_exercise(26_kuwahara)