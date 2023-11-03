#include<stdexcept>
#include<sstream>
#include "Pixel.h"

Pixel::Pixel (unsigned short red, unsigned short green, unsigned short blue) : 
    red(red), green(green), blue(blue) {
        if (red>255 || green>255 || blue>255) {
            throw std::invalid_argument("Color values must be 255 or less.");
        }
    }

Pixel::Pixel(const Pixel& p) : red(p.red), green(p.green), blue(p.blue) {} // copy constructor

Pixel::Pixel() : red(0), green(0), blue(0) {} // default constructor

unsigned short Pixel::getRed() {
    return red;
}

void Pixel::setRed(unsigned short red) {
    if (red>255) {
        throw std::invalid_argument("Color values must be 255 or less.");
    }
    this->red = red;
}

unsigned short Pixel::getGreen() {
    return green;
}

void Pixel::setGreen(unsigned short green) {
    if (green>255) {
        throw std::invalid_argument("Color values must be 255 or less.");
    }
    this->green = green;
}

unsigned short Pixel::getBlue() {
    return blue;
}

void Pixel::setBlue(unsigned short blue) {
    if (blue>255) {
        throw std::invalid_argument("Color values must be 255 or less.");
    }
    this->blue = blue;
}

    // add =
    Pixel& Pixel::operator=(const Pixel& rhs) {
        this->red = rhs.red;
        green = rhs.green;
        this->blue = rhs.blue;
        return *this;
    }

     // add +
    Pixel Pixel::operator+(const Pixel& rhs) {
        Pixel r;
        r.red = (this->red + rhs.red) / 2;
        r.green = (this->green + rhs.green) / 2;
        r.blue = (this->blue + rhs.blue) / 2;
        return r;
    }

    // add - (unary)
    Pixel& Pixel::operator-(){
        this->red = 255 - this->red;
        this->green = 255 - this->green;
        this->blue = 255 - this->blue;
        return *this;
    }

    // add ==
    bool Pixel::operator==(const Pixel& rhs) {
        return (this->red == rhs.red) &&
              (this->green == rhs.green) &&
              (this->blue == rhs.blue);
    }
