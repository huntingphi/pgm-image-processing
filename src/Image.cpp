
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
    std::ifstream file(input_name,std::ios::in|std::ios::binary);
    if (!file.is_open())
    {
        std::cerr << "There was a problem opening the input file" << std::endl;
    }
    std::vector<std::string> lines;
    std::string line;
    std::cout << "Begin reading" << std::endl;
    // file>>line;
    // std::cout << line << std::endl;
    int i = 0;
    std::getline(file, line, '\n');
    do
    {
        if (line[0]!='#'){
            i++;
            lines.push_back(line);
            std::cout << line << std::endl;
            }
            
        if (i>2) break;
    } while (std::getline(file, line, '\n'));
    // file.seekg(53);
    std::stringstream height_width(lines[1]);
    height_width>>height>>width;
    int length_of_data = width*height;
    char *buffer = new char[length_of_data];
    file.read(buffer, length_of_data);
    data = std::unique_ptr<unsigned char []>((unsigned char *) buffer);
}
void Image::save(std::string output_name) {

}