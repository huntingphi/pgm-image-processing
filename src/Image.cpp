
#include "../include/Image.h"


    // /***********************BIG SIX**********************/

Image::Image(){}
Image::~Image(){}
Image::Image(const Image &other){}
Image &Image::operator=(const Image &other){}
Image::Image(Image &&other){}
Image &Image::operator=(Image &&other){}
   //Move assignment operator

    /****************BINARY OPERATOR OVERLOADING***************/
bool Image::operator+(const Image &){} //addition of two images (I1 + I2)
bool Image::operator-(const Image &){} //subtraction of two images (I1 − I2)
bool Image::operator!(){}              //Invert an image (!I2)
bool Image::operator/(const Image &){} //mask I1 with I2 (I1 / I2)
bool Image::operator*(const Image &){} //threshold with f (int) (I1 * f)
bool Image::operator%(const Image &){} //filter with f (int) (I1 * f)

    ///////////////////////////////////////////////////

    /****************IO OPERATOR OVERLOADING***************/
std::ostream &operator<<(std::ostream &output, const Image &I){}

std::istream &operator>>(std::istream &input, Image &I){}

    /****************RELATIONAL OPERATOR OVERLOADING***************/
bool Image::operator==(const Image &other) const{}
bool Image::operator!=(const Image &other) const{}
    ///////////////////////////////////////////////////

void Image::load(std::string input_name) {
    
}
void Image::save(std::string output_name) {

}