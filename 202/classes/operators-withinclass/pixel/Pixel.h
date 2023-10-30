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
    // add +
    // add - (unary)
    // add ==
};

#endif