#ifndef PIXEL_H
#define PIXEL_H

#include <string>

class Pixel {
private: // optional here since classes are private by default
    unsigned short red;
    unsigned short green;
    unsigned short blue;
public:
    Pixel (unsigned short red, unsigned short green, unsigned short blue);
    Pixel(const Pixel& p); // copy constructor
    Pixel(); // default constructor
    void setRed(unsigned short red);
    unsigned short getRed();
    void setGreen(unsigned short green);
    unsigned short getGreen();
    void setBlue(unsigned short blue);
    unsigned short getBlue();
    // add =
    Pixel& operator=(const Pixel& rhs);
     // add +
    Pixel operator+(const Pixel& rhs);
    // add - (unary)
    Pixel& operator-();
    // add ==
    bool operator==(const Pixel& rhs);
};

#endif