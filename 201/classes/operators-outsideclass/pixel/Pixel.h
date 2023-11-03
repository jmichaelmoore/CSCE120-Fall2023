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
    unsigned short getRed() const;
    void setGreen(unsigned short green);
    unsigned short getGreen() const;
    void setBlue(unsigned short blue);
    unsigned short getBlue() const;
    // add =
    Pixel& operator=(const Pixel& rhs);
     // add +
    Pixel operator+(const Pixel& rhs) const;
    // add - (unary)
    Pixel& operator-();
    // add ==
    bool operator==(const Pixel& rhs) const;
};

std::ostream& operator<<(std::ostream& os, const Pixel& p);

#endif