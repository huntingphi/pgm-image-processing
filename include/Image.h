#ifndef IMAGE_HEADER
#define IMAGE_HEADER
#include <iostream>
#include <memory>
#include <fstream>
#include <vector>
#include <sstream>
// #include "../include/Filter.h"
class Filter;
class Image{
  private:  
    int width, height;

  public:
    std::unique_ptr<unsigned char[]> data;
    friend Filter;
    class iterator
    {
        friend Image;
      private:
        int index;
        unsigned char *ptr;
        // construct only via Image class (begin/end)
        iterator(u_char *p) : ptr(p),index(0) {}
        iterator(u_char *p,int i) : ptr(p), index(i) {}

      public: //copy construct is public
        iterator(const iterator &rhs) : ptr(rhs.ptr),index(rhs.index) {}
        //Destructor
        ~iterator(){}
        // define overloaded ops: *, ++, --, =

        iterator &operator=(const iterator &rhs)
        {}

        unsigned char &operator*() { return *ptr; }
        friend void swap(iterator &lhs, iterator &rhs);
        iterator &operator++(){
            //prefix increment
            ++index;
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
          --index;
          return *this;
        }
        iterator &operator--(int){
          //postfix decrement
          iterator temp(*this);
          operator--();
          return temp;
        }

        bool operator!=(const iterator &rhs) const
        {
          return this->index != rhs.index;
        }
    };
    // other methods for iterator
    // define begin()/end() to get iterator to start and
    // "one-past" end.
    iterator begin(void) const{ return iterator(data.get()); } // etc
    iterator end(void) const{
      unsigned char* this_data = data.get();
      return iterator(&this_data[width * height], this->width * this->height - 1);
      }

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
    bool operator*(const int f); //threshold with f (int) (I1 * f)
    bool operator%(const Image &); //filter with f (int) (I1 * f)

    ///////////////////////////////////////////////////

    /****************IO OPERATOR OVERLOADING***************/
    void operator<<(const std::string file);

    void operator>>(const std::string file);

    /****************RELATIONAL OPERATOR OVERLOADING***************/
    bool operator!=(const Image &other) const;
    bool operator==(const Image &other) const;
    ///////////////////////////////////////////////////

    void load(std::string input_name);
    void save(std::string output_name);
    unsigned char clamp(unsigned char pixel);    
    bool rangeCheck(const Image& other)const;
    



};
#endif
