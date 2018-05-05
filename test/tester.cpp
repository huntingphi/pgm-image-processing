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
    for(int i = 1;i<25;i++){
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
    unsigned char *expected_buffer = new unsigned char[25];
    for(int i =0 ;i<25;){

        for (int j = 1; j < 5; j++)
        {
            if(i==25)break;
            expected_buffer[i] = u_char(j) + u_char(j);
            i++;
        }
    }

    unsigned char *resulting_buffer = new unsigned char[25];
    for(int i =0 ;i<25;){

        for (int j = 1; j < 5; j++)
        {
            if(i==25)break;
            resulting_buffer[i] = u_char(j);
            i++;
        }
    }
    
    unsigned char *added_buffer = new unsigned char[25];
    for(int i =0 ;i<25;){

        for (int j = 1; j < 5; j++)
        {
            if(i==25)break;
            added_buffer[i] = u_char(j);
            i++;
        }
    }


    Image image_resulting(5,5,resulting_buffer);
    Image image_to_add(5,5,added_buffer);
    image_resulting + image_to_add;
    Image image_expected(5,5,expected_buffer);
    // image_expected<<("TestAdd.pgm");
        REQUIRE(image_resulting == image_expected);
}

TEST_CASE("Test subtract"){
    unsigned char *expected_buffer = new unsigned char[25];
    for (int i = 0; i < 25;)
    {

        for (int j = 1; j < 5; j++)
        {
            if (i == 25)
                break;
            expected_buffer[i] = u_char(j) - u_char(j);
            i++;
        }
    }

    unsigned char *resulting_buffer = new unsigned char[25];
    for (int i = 0; i < 25;)
    {

        for (int j = 1; j < 5; j++)
        {
            if (i == 25)
                break;
            resulting_buffer[i] = u_char(j);
            i++;
        }
    }

    unsigned char *subtracting_buffer = new unsigned char[25];
    for (int i = 0; i < 25;)
    {

        for (int j = 1; j < 5; j++)
        {
            if (i == 25)
                break;
            subtracting_buffer[i] = u_char(j);
            i++;
        }
    }

    Image image_resulting(5, 5, resulting_buffer);
    Image image_to_subtract(5, 5, subtracting_buffer);
    image_resulting - image_to_subtract;
    Image image_expected(5, 5, expected_buffer);
    // image_expected<<("TestAdd.pgm");
    REQUIRE(image_resulting == image_expected);
}

TEST_CASE("Test inverse"){
    unsigned char *expected_buffer = new unsigned char[25];
    for (int i = 0; i < 25;)
    {

        for (int j = 1; j < 5; j++)
        {
            if (i == 25)
                break;
            expected_buffer[i] = 255 - u_char(j);
            i++;
        }
    }

    unsigned char *resulting_buffer = new unsigned char[25];
    for (int i = 0; i < 25;)
    {

        for (int j = 1; j < 5; j++)
        {
            if (i == 25)
                break;
            resulting_buffer[i] = u_char(j);
            i++;
        }
    }



    Image image_resulting(5, 5, resulting_buffer);
    !image_resulting;
    Image image_expected(5, 5, expected_buffer);
    REQUIRE(image_resulting == image_expected);
}

TEST_CASE("Test mask"){
    unsigned char *expected_buffer = new unsigned char[25];
    

    unsigned char *resulting_buffer = new unsigned char[25];
    for (int i = 0; i < 25;)
    {

        for (int j = 1; j < 5; j++)
        {
            if (i == 25)
                break;
            resulting_buffer[i] = u_char(j);
            i++;
        }
    }

    unsigned char *masking_buffer = new unsigned char[25];
    for (int i = 0; i < 25;)
    {

        for (int j = 1; j < 5; j++)
        {
            if (i == 25)
                break;
            masking_buffer[i] = u_char(j);
            i++;
        }

        for (int i = 0; i < 25;)
        {

            for (int j = 1; j < 5; j++)
            {
                if (i == 25)
                    break;
                masking_buffer[i] == 255 ? expected_buffer[i] = resulting_buffer[i] : expected_buffer[i] = u_char(0);
                // expected_buffer[i] = u_char(j) - u_char(j);
                i++;
            }
        }
    }

    Image image_resulting(5, 5, resulting_buffer);
    Image image_to_mask(5, 5, masking_buffer);
    image_resulting / image_to_mask;
    Image image_expected(5, 5, expected_buffer);
    // image_expected<<("TestAdd.pgm");
    REQUIRE(image_resulting == image_expected);
}

TEST_CASE("Test threshold"){
    int t = 2;
    unsigned char *expected_buffer = new unsigned char[25];

    unsigned char *resulting_buffer = new unsigned char[25];
    for (int i = 0; i < 25;)
    {

        for (int j = 1; j < 5; j++)
        {
            if (i == 25)
                break;
            resulting_buffer[i] = u_char(j);
            i++;
        }
    }

        for (int i = 0; i < 25;)
        {

            for (int j = 1; j < 5; j++)
            {
                if (i == 25)
                    break;
                resulting_buffer[i] > u_char(t) ? expected_buffer[i] = u_char(255) : expected_buffer[i] = u_char(0);
                i++;
            }
        }
    

    Image image_resulting(5, 5, resulting_buffer);
    image_resulting*t;
    Image image_expected(5, 5, expected_buffer);
    // image_expected<<("TestAdd.pgm");
    REQUIRE(image_resulting == image_expected);
}

TEST_CASE("Test filter"){
    unsigned char *resulting_buffer = new unsigned char[25];
    for (int i = 0; i < 25;)
    {

        for (int j = 1; j < 5; j++)
        {
            if (i == 25)
                break;
            resulting_buffer[i] = u_char(j);
            i++;
        }
    }
    Image image_resulting(5, 5, resulting_buffer);
    Filter filter(std::string("blur.fir" ),image_resulting);
    REQUIRE(filter.data.size()==5);
    REQUIRE(filter.filter_matrix.size()==5);
    Image image_test;
    image_test<<"Lenna_standard.pgm";
    Filter f(std::string("blur.fir"), image_test);
    Image image_result;
    image_result << "Lenna_standard.pgm";
    image_result.data = std::unique_ptr<unsigned char []>((unsigned char *)f.filter_image());
    // REQUIRE(image_result==image_test);
    image_result>>"tests.pgm";
    // filter.filter_image();
}