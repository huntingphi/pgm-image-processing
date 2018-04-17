#include <iostream>
#include <memory>
class Image{
  private:
    int width, height;
    std::unique_ptr<unsigned char[]> data;

  public:
    class iterator
    {
      private:
        unsigned char *ptr;
        // construct only via Image class (begin/end)
        iterator(u_char *p) : ptr(p) {}

      public: //copy construct is public
        iterator(const iterator &rhs) : ptr(rhs.ptr) {}
        // define overloaded ops: *, ++, --, =
        iterator &operator=(const iterator &rhs)
        {}
        // other methods for iterator
    };
    // define begin()/end() to get iterator to start and
    // "one-past" end.
    iterator begin(void) { return iterator(data.get()) } // etc

// /***********************BIG SIX**********************/

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
    ///////////////////////////////////////////////////

/****************IO OPERATOR OVERLOADING***************/
friend std::ostream &operator<<(std::ostream &output, const Image &I);

friend std::istream &operator>>(std::istream &input, Image &I);

/****************RELATIONAL OPERATOR OVERLOADING***************/
bool operator==(const Image &other) const;
bool operator!=(const Image &other) const;
///////////////////////////////////////////////////

void load();
void save();



};