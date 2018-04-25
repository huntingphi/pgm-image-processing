#include "../include/catch.hpp"
#include "../include/Image.h"


TEST_CASE("Test load"){
    Image image_1, image_2;
    image_1.load("assets/Lenna_standard.pgm");
    image_2.load("assets/Lenna_standard.pgm");

    REQUIRE(*image_1.data.get() == *image_2.data.get());
    }
