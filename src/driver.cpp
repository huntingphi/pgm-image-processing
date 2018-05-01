#include <iostream>
#include "../include/driver.h"

int main(int argc, char *argv[])
{
    if (argc == 4)
    {
        std::string operation(argv[1]);
        if(operation != "-i"){
            std::cerr << "Usage: imageops <option> <Output Image Name>";
            return 1;
        }
        Image l1;
        l1<<(argv[2]);
        !l1;
        l1>>(argv[3]);
        
        
    }else if(argc == 5&&*argv[1]=='-'){
        char operation(*(argv[1]+1));//Extract the 2nd character of the second argument
        switch(operation){
        case 'a':
        {
            Image image_result;
            image_result<<(argv[2]);
            Image image_to_add;
            image_to_add<<(argv[3]);
            bool result = image_result + image_to_add;
            if (result == false)
            {
                std::cerr << "Images must be same width and height!";
            }
            image_result>>(argv[4]);
            break;
        }
        case 's':
        {
            Image image_result;
            image_result<<(argv[2]);
            Image image_to_subtract;
            image_to_subtract<<(argv[3]);
            bool result = image_result - image_to_subtract;
            if (result == false)
            {
                std::cerr << "Images must be same width and height!";
            }
            image_result>>(argv[4]);
            break;
        }
        case 'l':
        {

            Image image_result;
            image_result<<(argv[2]);
            Image image_mask;
            image_mask<<(argv[3]);
            bool result = image_result / image_mask;
            if(result ==  false){
                std::cerr << "Images must be same width and height!";
            }
            image_result>>(argv[4]);
            break;
        }
        case 't':
            // threshold();
            {
            Image image_result;
            image_result<<(argv[2]);
            float f=std::atof(argv[3]);
            // u_char f = reinterpret_cast<unsigned char>(argv[3]);
            image_result*f;
            image_result>>(argv[4]);
            break;
            }
        case 'g':
            // filter();
            {
                Image image_result;
                image_result << (argv[2]);
                std::string file = std::string(argv[3]);
                // u_char f = reinterpret_cast<unsigned char>(argv[3]);
                image_result %file;
                image_result >> (argv[4]);
                break;
            }
        }

        
    }else{
        std::cerr << "Usage: imageops <option> <Output Image Name>";
        return 1;
    }

    return 0;
}
