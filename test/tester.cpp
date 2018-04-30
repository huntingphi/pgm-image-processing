#include "../include/catch.hpp"
#include "../include/Image.h"
#include "../include/Filter.h"

TEST_CASE("Test move assignment"){
    Image image_1;
    image_1 << ("shrek_rectangular.pgm");
    Image image_3;
    image_3 << ("shrek_rectangular.pgm");
    Image image_2(std::move(image_1));
    REQUIRE(image_2 == image_3);
    REQUIRE_FALSE(image_1==image_2);
}

TEST_CASE("Test move constructor"){
    Image image_1;
    image_1 << ("shrek_rectangular.pgm");
    Image image_3;
    image_3 << ("shrek_rectangular.pgm");
    Image image_2 = std::move(image_1);
    REQUIRE(image_2 == image_3);
    REQUIRE_FALSE(image_1 == image_2);
}

TEST_CASE("Test copy assignment"){
    Image image_1;
    image_1 << ("shrek_rectangular.pgm");
    Image image_2 = image_1;
    REQUIRE(image_1 == image_2);
}
TEST_CASE("Test copy constructor"){
    Image image_1;
    image_1 << ("shrek_rectangular.pgm");
    Image image_2(image_1);
    REQUIRE(image_1 == image_2);
}

TEST_CASE("Test iterator ++ -- begin end and equality operators"){
    Image image_result;
    image_result << ("Test.pgm");
    Image::iterator iter_result = image_result.begin();
    REQUIRE(*iter_result == '1');
    iter_result++;
    REQUIRE(*iter_result == '2');
    iter_result--;
    REQUIRE(*iter_result == '1');
    Image::iterator iter_result_end = image_result.end();
    iter_result_end--;//Decrement as the iterator returns the element at 1-past-end
    REQUIRE(*iter_result_end == '1');
    iter_result_end++;
    REQUIRE(iter_result!=iter_result_end);
    for(int i = 0;i<25;i++){
        iter_result++;
    }
    REQUIRE_FALSE(iter_result != iter_result_end);
}


TEST_CASE("Test == "){
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
    unsigned char *buffer = {u_char()};
    image_expected.data = std::unique_ptr<unsigned char[]>(buffer);
        REQUIRE(image_result == image_expected);
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
    // Filter(std::string("blur.fir"));
}