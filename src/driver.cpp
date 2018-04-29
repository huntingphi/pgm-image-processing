#include <iostream>
#include "../include/driver.h"

int main(int argc, char *argv[])
{
    // STUB(invertImage);

    if (argc == 4)
    {
        std::string operation(argv[1]);
        // std::cout<<operation<<std::endl;
        if(operation != "-i"){
            std::cerr << "Usage: imageops <option> <Output Image Name>";
            return 1;
        }
        invertImage();
        
        
    }else if(argc == 5&&*argv[1]=='-'){
        char operation(*(argv[1]+1));//Extract the 2nd character of the second argument
        // std::cout << operation << std::endl;
        switch(operation){
        case 'a':
            add();
            break;
        case 's':
            subtract();
            break;
        case 'l':
            mask();
            break;
        case 't':
            threshold();
            break;
        }

        
    }else{
        std::cerr << "Usage: imageops <option> <Output Image Name>";
        return 1;
    }

    return 0;
}
