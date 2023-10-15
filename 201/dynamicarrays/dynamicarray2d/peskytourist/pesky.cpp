#include <iostream>
#include <fstream>

using namespace std;

struct Pixel {
    unsigned int r;
    unsigned int g;
    unsigned int b;
};

void mySwap(unsigned int a, unsigned int b) {
}

unsigned int getMedian(unsigned int a, unsigned int b, unsigned int c) {
    // sort local copies
    // return middle value
    return b;
}

Pixel** makeImage(unsigned int width, unsigned int height) {
    // throw exception if we fail to allocate memory for the image.
    return nullptr;
}

// (ifstream, image, width, height) allow images and width and height to be updated
// we'll assume good input
void loadImage() {
    // get preamble data including width and height
    // allocate memory for the iamge based on width and height
}

// (ofstream, image, width, height) // prevent changing array
void outputImage() {
    ofs << "P3" << endl;
    ofs << width << " " << height << endl;
    ofs << 255 << endl;
    for (int row=0; row<height; ++row) {
        for (int col=0; col<width; ++col) {
            ofs << img[col][row].r << " ";
            ofs << img[col][row].g << " ";
            ofs << img[col][row].b << " ";
        }
        ofs << endl;
    }
}

// (image, what else?)
void deleteImage() {
}

int main() {
    try {
        ifstream file1("first.ppm");
        ifstream file2("second.ppm");
        ifstream file3("third.ppm");
        ofstream outFile("result.ppm");
        if (!file1.is_open() || !file2.is_open() || !file3.is_open() || !outFile.is_open()) {
            cout << "Unable to open files" << endl;
            return 1;
        }

        Pixel** img1 = nullptr;
        Pixel** img2 = nullptr;
        Pixel** img3 = nullptr;
        Pixel** result = nullptr;
        unsigned int width = 0;
        unsigned int height = 0;
        unsigned int loadWidth = 0; // set to parameters of first image and ensure other images match
        unsigned int loadHeight = 0;

        // Load & create 2D arrays

        // Make result image

        // Process out that pesky tourist

        // output result image
        outputImage(outFile, result, width, height);

        // delete images to avoid memory leaks

    }
    catch (...) {
        cout << "Encountered an unexpected error!" <<endl;
    }
}