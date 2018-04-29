#include "../include/catch.hpp"
#include "../include/Image.h"

TEST_CASE("Test =="){
    Image image_1;
    image_1.load("assets/Test.pgm");
    Image image_2;
    image_2.load("assets/Test2.pgm");
    REQUIRE(image_1==image_2);
}


TEST_CASE("Test load"){
    Image image_result;
    image_result.load("assets/Test.pgm");
    Image::iterator iter_result = image_result.begin();
    Image::iterator iter_result_end = image_result.end();
    iter_result_end--;
    REQUIRE(*iter_result=='1');
    REQUIRE(*iter_result_end == '1');
}

TEST_CASE("Test save"){
    Image image_result;
    image_result.load("assets/Test.pgm");
    image_result.save("Test");
    Image image_to_add;
    image_to_add.load("saved_pgms/Test.pgm");
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
    image_result.load("assets/Test.pgm");
    Image image_to_add;
    image_to_add.load("assets/Test2.pgm");
    image_result+image_to_add;
    image_result.save("TestAdd");
    Image image_expected;
    image_expected.load("saved_pgms/TestAdd.pgm");
    REQUIRE(image_result == image_expected);
}

TEST_CASE("Test subtract"){
    Image image_result;
    image_result.load("assets/Test.pgm");
    Image image_to_add;
    image_to_add.load("assets/Test2.pgm");
    image_result - image_to_add;
    image_result.save("TestSubtract");
    Image image_expected;
    image_expected.load("saved_pgms/TestSubtract.pgm");
    REQUIRE(image_result == image_expected);
}

TEST_CASE("Test inverse"){
    Image image_result;
    image_result.load("assets/Lenna_standard.pgm");
    // Image image_to_add;
    // image_to_add.load("assets/Test2.pgm");
    !image_result;
    image_result.save("TestInverse");
    // Image image_expected;
    // image_expected.load("saved_pgms/TestInverse.pgm");
    // REQUIRE(image_result == image_expected);
}

TEST_CASE("Test mask"){
    Image image_result;
    image_result.load("assets/shrek_rectangular.pgm");
    Image image_mask;
    image_mask.load("assets/donkey_mask.pgm");
    image_result/image_mask;
    image_result.save("TestMask");
    // Image image_expected;
    // image_expected.load("saved_pgms/TestSubtract.pgm");
}