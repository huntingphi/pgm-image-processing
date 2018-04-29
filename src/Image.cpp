
#include "../include/Image.h"


    // /***********************BIG SIX**********************/
    Image::Image(int w, int h, unsigned char* d):width(w),height(h) {
        data = std::unique_ptr<unsigned char []>(d);
    }

    Image::Image() {}
    Image::~Image() {}
    Image::Image(const Image &other) {}
    Image &Image::operator=(const Image &other) {}
    Image::Image(Image &&other) {}
    Image &Image::operator=(Image &&other) {}
    //Move assignment operator

    /****************BINARY OPERATOR OVERLOADING***************/
bool Image::operator+(const Image &other){
    iterator iter_to_add = other.begin();
    for (iterator iter_result = begin(); *iter_result != *end(); iter_result++)
    {
        std::cout << "===================================================" << std::endl;
        std::cout << *iter_result << std::endl;
        std::cout << *iter_to_add << std::endl;
        *iter_result = *iter_result + *iter_to_add;
        std::cout << *iter_result << std::endl;
        std::cout << "===================================================" << std::endl;
        iter_to_add++;
    }
    //addition of two images (I1 + I2)

} 
bool Image::operator-(const Image &other){
//subtraction of two images (I1 − I2)
iterator iter_to_subtract = other.begin();
for (iterator iter_result = begin(); *iter_result != *end(); iter_result++)
{
    std::cout << "===================================================" << std::endl;
    std::cout << *iter_result << std::endl;
    std::cout << *iter_to_subtract << std::endl;
    *iter_result = *iter_result - *iter_to_subtract;
    std::cout << *iter_result << std::endl;
    std::cout << "===================================================" << std::endl;
    iter_to_subtract++;
}
} 
bool Image::operator!(){
//Invert an image (!I2)
for (iterator iter_result = begin(); *iter_result != *end(); iter_result++)
{
    std::cout << "===================================================" << std::endl;
    std::cout << *iter_result << std::endl;
    *iter_result = 255-*iter_result;
    std::cout << *iter_result << std::endl;
    std::cout << "===================================================" << std::endl;
}
}   
bool Image::operator/(const Image &){} //mask I1 with I2 (I1 / I2)
bool Image::operator*(const Image &){} //threshold with f (int) (I1 * f)
bool Image::operator%(const Image &){} //filter with f (int) (I1 * f)

    ///////////////////////////////////////////////////

    /****************IO OPERATOR OVERLOADING***************/
std::ostream &operator<<(std::ostream &output, const Image &I){}

std::istream &operator>>(std::istream &input, Image &I){}

    /****************RELATIONAL OPERATOR OVERLOADING***************/
bool Image::operator==(const Image &other) const{
    if(width==other.width && height == other.height){
        int size_of_data = other.width*other.height;
        unsigned char* this_buffer = data.get();
        unsigned char* other_buffer = other.data.get();
        for(int i = 0; i<size_of_data;i++){
            if(this_buffer[i]!=other_buffer[i])return false;
        }
        return true;
    }
    return false;
}
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
    // file.seekg(53    );

        std::stringstream height_width(lines[1]);
    height_width>>height>>width;
    int length_of_data = width*height;
    char *buffer = new char[length_of_data];
    file.read(buffer, length_of_data);
    data = std::unique_ptr<unsigned char []>((unsigned char *) buffer);
}
void Image::save(std::string output_name) {
        std::string filepath = "saved_pgms/" +output_name+".pgm";
        std::ofstream raw_image(filepath, std::ios::binary);
        raw_image<<("P5\n");
        raw_image<<height<<" "<<width<<"\n";
        raw_image<<255<<"\n";
        std::string data_block(reinterpret_cast<char *>(data.get()),width*height);
        raw_image<<data_block;

        if (!raw_image)
            throw std::runtime_error("Could not open file: " + filepath);
        raw_image.close();
    }
