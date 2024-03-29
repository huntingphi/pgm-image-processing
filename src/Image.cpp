#include "../include/Image.h"
    // /***********************BIG SIX**********************/
    Image::Image(int w, int h, unsigned char* d):width(w),height(h) {
        data = std::unique_ptr<unsigned char []>(d);
    }
    Image::Image():width(0),height(0) {
        // data = {u_char(0)};
    }
    Image::~Image() {
        this->width = 0;
        this->height = 0;
        this->data.~unique_ptr();
    }
    Image::Image(const Image &other) {
        // Image();
        this->width = other.width;
        this->height = other.height;
        unsigned char* buffer = new unsigned char[width*height];
        data = std::unique_ptr<unsigned char []>(buffer);
        
        Image::iterator beg = this->begin(), end = this->end();
        Image::iterator inStart = other.begin(), inEnd = other.end();
        while (beg != end)
        {
            *beg = *inStart;
            ++beg;
            ++inStart;
        }
    }
    Image &Image::operator=(const Image &other) {
        this->width = other.width;
        this->height = other.height;
        unsigned char *buffer = new unsigned char[width * height];
        data = std::unique_ptr<unsigned char[]>(buffer);
        Image::iterator beg = this->begin(), end = this->end();
        Image::iterator inStart = other.begin(), inEnd = other.end();
        while (beg != end)
        {
            *beg = *inStart;
            ++beg;
            ++inStart;
        }
        return *this;
    }
    Image::Image(Image &&other):width(0),height(0) {
        this->data = nullptr;
        this->width = other.width;
        this->height = other.height;
        unsigned char *buffer = new unsigned char[width * height];
        data = std::unique_ptr<unsigned char[]>(buffer);
        this->data = std::move(other.data);
        
        other.width =0;
        other.height =0;
        other.data = nullptr;
    }
    Image &Image::operator=(Image &&other) {
    //Move assignment operator
        if(this==&other){
        }else{
            this->width = 0;
            this->height = 0;
            this->data = nullptr;
            this->width = other.width;
            this->height = other.height;
            unsigned char *buffer = new unsigned char[width * height];
            data = std::unique_ptr<unsigned char[]>(buffer);
            this->data = std::move(other.data);

            other.width = 0;
            other.height = 0;
            other.data = nullptr;
            return *this;
        }
    }

    /****************BINARY OPERATOR OVERLOADING***************/
bool Image::operator+(const Image &other){
    //addition of two images (I1 + I2)
    if(rangeCheck(other)==false)return false;
    
    iterator iter_to_add = other.begin();
    for (iterator iter_result = this->begin(); iter_result != this->end(); ++iter_result)
    {
        u_char value;
        value = *iter_result + *iter_to_add;
        *iter_result = clamp(value);
         iter_to_add++;
    }

} 
bool Image::operator-(const Image &other){
//subtraction of two images (I1 − I2)
    if(rangeCheck(other)==false)return false;

iterator iter_to_subtract = other.begin();

for (iterator iter_result = this->begin(); iter_result != this->end(); ++iter_result)
{
    u_char value;
    value = *iter_to_subtract - *iter_result;
    *iter_result = clamp(value);
        iter_to_subtract++;
}
} 
bool Image::operator!(){
//Invert an image (!I2)
for (iterator iter_result = this->begin(); iter_result!=this->end(); ++iter_result)
{
    *iter_result = 255-*iter_result;
}
}   
bool Image::operator/(const Image &other){
//mask I1 with I2 (I1 / I2)
    if(rangeCheck(other)==false)return false;

iterator iter_to_mask = other.begin();
for (iterator iter_result = this->begin(); iter_result != this->end(); ++iter_result)
{
    *iter_to_mask == u_char(255)? :*iter_result = u_char(0);
    iter_to_mask++;
}
} 
bool Image::operator*(const int f){
//threshold with f (int) (I1 * f)

for (iterator iter_result = this->begin(); iter_result != this->end(); ++iter_result)
{
    *iter_result > u_char(f) ? *iter_result=255:*iter_result=0;
}
} 
bool Image::operator%(const std::string file){
 //filter with % (filter) (I1 % filter)
 Filter f(file, *this);
 this->data = std::unique_ptr<unsigned char[]>((unsigned char *)f.filter_image());
 
}

    ///////////////////////////////////////////////////

    /****************IO OPERATOR OVERLOADING***************/
void Image::operator<<(const std::string file) {
    load(file);
}

void Image::operator>>(const std::string file) {
    save(file);
}

/****************RELATIONAL OPERATOR OVERLOADING***************/
bool Image::operator==(const Image &other) const{
    if(width==other.width && height == other.height){
        int size_of_data = other.width*other.height;
        unsigned char* this_buffer = data.get();
        unsigned char* other_buffer = other.data.get();
        for(int i = 0; i<size_of_data-1;i++){
            if(this_buffer[i]!=other_buffer[i]){
                std::cout << int(this_buffer[i]) << " vs " << int(other_buffer[i])<<" i: "<<i;

                return false;
            }
        }
        return true;
    }
    return false;
}
bool Image::operator!=(const Image &other) const{}
    ///////////////////////////////////////////////////

void Image::load(std::string input_name) {
    std::ifstream file("assets/"+input_name,std::ios::in|std::ios::binary);
    if (!file.is_open())
    {
        std::cerr << "There was a problem opening the input file" << std::endl;
    }
    std::vector<std::string> lines;
    std::string line;
    int i = 0;
    std::getline(file, line, '\n');
    do
    {
        if (line[0]!='#'){
            i++;
            lines.push_back(line);
            }
            
        if (i>2) break;
    } while (std::getline(file, line, '\n'));
        std::stringstream height_width(lines[1]);
    height_width>>height>>width;
    int length_of_data = width*height;
    char *buffer = new char[length_of_data];
    file.read(buffer, length_of_data);
    data = std::unique_ptr<unsigned char []>((unsigned char *) buffer);
    file.close();
}
void Image::save(std::string output_name) {
        std::string filepath = "saved_pgms/" +output_name;//+".pgm";
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

    unsigned char Image::clamp(unsigned char pixel){
        if (pixel<u_char(0)){
            std::cout<<"CLAMPED"<<std::endl;
            return u_char(0);
        }else if(pixel>u_char(255)){
            std::cout << "CLAMPED" << std::endl;
            return u_char(255);
        }
        return pixel;
    }

    bool Image::rangeCheck(const Image& other)const{
        return (this->width==other.width&&this->height==other.height);
    }


