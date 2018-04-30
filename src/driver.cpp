#include <iostream>
#include "../include/driver.h"

int main(int argc, char *argv[])
{
    if (argc == 3)
    {
        std::string operation(argv[1]);
        if(operation != "-i"){
            std::cerr << "Usage: imageops <option> <Output Image Name>";
            return 1;
        }
        Image l1;
        l1.load(argv[2]);
        !l1;
        l1.save(argv[2]);
        
        
    }else if(argc == 4&&*argv[1]=='-'){
        char operation(*(argv[1]+1));//Extract the 2nd character of the second argument
        switch(operation){
        case 'a':
        {
            Image image_result;
            image_result<<(argv[2]);
            Image image_to_add;
            image_to_add<<(argv[3]);
            image_result + image_to_add;
            image_result>>(argv[2]);
            break;
        }
        case 's':
        {
            Image image_result;
            image_result<<(argv[2]);
            Image image_to_subtract;
            image_to_subtract<<(argv[3]);
            image_result - image_to_subtract;
            image_result<<(argv[2]);
            break;
        }
        case 'l':
        {
            Image image_result;
            image_result.load(argv[2]);
            Image image_mask;
            image_mask.load(argv[2]);
            image_result / image_mask;
            image_result.save(argv[2]);
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
            image_result>>(argv[2]);
            break;
            }
        }

        
    }else{
        std::cerr << "Usage: imageops <option> <Output Image Name>";
        return 1;
    }

    return 0;
}
