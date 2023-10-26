#include <stdexcept>
class Pixel {
private: // optional here since classes are private by default
    unsigned short red;
    unsigned short green;
    unsigned short blue;
public:
    Pixel (unsigned short red, unsigned short green, unsigned short blue) : 
        red(red), green(green), blue(blue) {
            if (red>255 || green>255 || blue>255) {
                throw std::invalid_argument("Color values must be 255 or less.");
            }
        };
    Pixel(const Pixel& p) : red(p.red), green(p.green), blue(p.blue) {} // copy constructor
    Pixel() : red(0), green(0), blue(0) {} // default constructor
};