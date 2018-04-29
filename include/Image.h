#ifndef IMAGE_HEADER
#define IMAGE_HEADER
#include <iostream>
#include <memory>
#include <fstream>
#include <vector>
#include <sstream>
class Image{
  private:  
    int width, height;

  public:
    std::unique_ptr<unsigned char[]> data;
    class iterator
    {
        friend Image;
      private:
        unsigned char *ptr;
        // construct only via Image class (begin/end)
        iterator(u_char *p) : ptr(p) {}

      public: //copy construct is public
        iterator(const iterator &rhs) : ptr(rhs.ptr) {}
        //Destructor
        ~iterator(){}
        // define overloaded ops: *, ++, --, =

        iterator &operator=(const iterator &rhs)
        {}

        unsigned char &operator*() { return *ptr; }
        friend void swap(iterator &lhs, iterator &rhs);
        iterator &operator++(){
            //prefix increment
            ++ptr;
            return *this;

        } iterator &
        operator++(int)
        {
          //postfix increment
          iterator temp(*this);
          operator++();
          return temp;
        }
        iterator &operator--(){
          //prefix decrement
          --ptr;
          return *this;
        }
        iterator &operator--(int){
          //postfix decrement
          iterator temp(*this);
          operator--();
          return temp;
        }


    };
    // other methods for iterator
    // define begin()/end() to get iterator to start and
    // "one-past" end.
    iterator begin(void) const{ return iterator(data.get()); } // etc
    iterator end(void) const{
      unsigned char* this_data = data.get();
      // std::cout << "Width: " << width << " Height: " << height << '\n';
      // std::cout << " Begining address "<< long(data.get())<<" End address "<<long(&this_data[width*height]) << '\n';

      return iterator(&this_data[width*height]);
      } // etc

    // /***********************BIG SIX**********************/
    Image(int w, int h, unsigned char *d);
    Image();
    ~Image();

    Image(const Image &other);

    Image &operator=(const Image &other);

    Image(Image &&other);

    Image &operator=(Image &&other);
    //Move assignment operator

    /****************BINARY OPERATOR OVERLOADING***************/
    bool operator+(const Image &); //addition of two images (I1 + I2)
    bool operator-(const Image &); //subtraction of two images (I1 − I2)
    bool operator!();              //Invert an image (!I2)
    bool operator/(const Image &); //mask I1 with I2 (I1 / I2)
    bool operator*(const Image &); //threshold with f (int) (I1 * f)
    bool operator%(const Image &); //filter with f (int) (I1 * f)

    ///////////////////////////////////////////////////

    /****************IO OPERATOR OVERLOADING***************/
    friend std::ostream &operator<<(std::ostream &output, const Image &I);

    friend std::istream &operator>>(std::istream &input, Image &I);

    /****************RELATIONAL OPERATOR OVERLOADING***************/
    bool operator!=(const Image &other) const;
    bool operator==(const Image &other) const;
    ///////////////////////////////////////////////////

    void load(std::string input_name);
    void save(std::string output_name);



};
#endif
