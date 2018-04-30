#include "../include/catch.hpp"
#include "../include/Image.h"

TEST_CASE("Test =="){
    Image image_1;
    image_1<<("Test.pgm");
    Image image_2;
    image_2<<("Test2.pgm");
    REQUIRE(image_1==image_2);
}


TEST_CASE("Test load"){
    Image image_result;
    image_result<<("Test.pgm");
    Image::iterator iter_result = image_result.begin();
    Image::iterator iter_result_end = image_result.end();
    iter_result_end--;
    REQUIRE(*iter_result=='1');
    REQUIRE(*iter_result_end == '1');
}

TEST_CASE("Test save"){
    Image image_result;
    image_result<<("Test.pgm");
    image_result>>("Test.pgm");
    Image image_to_add;
    image_to_add<<("Test.pgm");
    Image::iterator iter_result = image_result.begin();
    Image::iterator iter_result_end = image_result.end();
    iter_result_end--;
    Image::iterator iter_to_add = image_to_add.begin();
    Image::iterator iter_to_add_end = image_to_add.end();
    iter_to_add_end--;
    REQUIRE(*iter_result == *iter_to_add);
    REQUIRE(*iter_result_end == *iter_to_add_end);
}

TEST_CASE("Test add"){
    Image image_result;
    image_result<<("Test.pgm");
    Image image_to_add;
    image_to_add<<("Test2.pgm");
    image_result+image_to_add;
    image_result>>("TestAdd.pgm");
    Image image_expected;
    image_expected<<("TestAdd.pgm");
    // REQUIRE(image_result == image_expected);
}

TEST_CASE("Test subtract"){
    Image image_result;
    image_result<<("Test.pgm");
    Image image_to_add;
    image_to_add<<("Test2.pgm");
    image_result - image_to_add;
    image_result>>("TestSubtract.pgm");
    Image image_expected;
    image_expected<<("TestSubtract.pgm");
    // REQUIRE(image_result == image_expected);
}

TEST_CASE("Test inverse"){
    Image image_result;
    image_result<<("Lenna_standard.pgm");
    // Image image_to_add;
    // image_to_add<<("assets/Test2.pgm");
    !image_result;
    image_result>>("TestInverse.pgm");
    // Image image_expected;
    // image_expected<<("saved_pgms/TestInverse.pgm");
    // REQUIRE(image_result == image_expected);
}

TEST_CASE("Test mask"){
    Image image_result;
    image_result<<("shrek_rectangular.pgm");
    Image image_mask;
    image_mask<<("donkey_mask.pgm");
    image_result/image_mask;
    image_result>>("TestMask.pgm");
    // Image image_expected;
    // image_expected<<("saved_pgms/TestSubtract.pgm");
}

TEST_CASE("Test threshold"){
    Image image_result;
    image_result<<("shrek_rectangular.pgm");
    // Image image_mask;
    // image_mask<<("assets/donkey_mask.pgm");
    image_result*u_char(255);
    image_result>>("TestThreshold.pgm");
    // Image image_expected;
    // image_expected<<("saved_pgms/TestSubtract.pgm");
}

TEST_CASE("Test filter"){

}