#include <iostream>
#include <fstream>

using namespace std;

struct Pixel {
    int r;
    int g;
    int b;
};

void mySwap(int a, int b) {
}

int getMedian(int a, int b, int c) {
    // sort local copies
    // return middle value
    return b;
}

Pixel** makeImage(int width, int height) {
    return nullptr;
}

// (ifstream, image, width, height)
// we'll assume good input
void loadImage(ifstream& ifs, Pixel** img, int width, int height) {
    // get preamble data including width and height
    // allocate memory for the iamge based on width and height
}

// (ofstream, image, width, height)
void outputImage(ofstream& ofs, const Pixel*const* img, int width, int height) {
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
            cout << "Unable to open input files" << endl;
            return 1;
        }

        Pixel** img1 = nullptr;
        Pixel** img2 = nullptr;
        Pixel** img3 = nullptr;
        Pixel** result = nullptr;
        int width = -1;
        int height = -1;
        int loadWidth = -1;
        int loadHeight = -1;

        // Load & create 2D arrays

        // Make result image

        // Process that pesky tourist

        // output result image
        outputImage(outFile, result, width, height);

        // delete images to avoid memory leaks

    }
    catch (...) {
        cout << "Encountered an unexpected error!" <<endl;
    }
}