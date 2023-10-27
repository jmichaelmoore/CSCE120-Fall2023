#ifndef PIXEL_H
#define PIXEL_H

class Pixel {
private: // optional since classes are private by default
    unsigned short red;
    unsigned short green;
    unsigned short blue;
public:
    Pixel(unsigned short red, unsigned short green, unsigned short blue);
    Pixel(const Pixel& p); // copy constructor
    Pixel(); // default constructor

    unsigned short getRed();
    void setRed(unsigned short red);
    unsigned short getGreen();
    void setGreen(unsigned short green);
    unsigned short getBlue();
    void setBlue(unsigned short blue);
};

#endif