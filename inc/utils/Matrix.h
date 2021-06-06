#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-nodiscard"
#ifndef SPELLCHECKER_MATRIX_H
#define SPELLCHECKER_MATRIX_H

// Used by the non-recursive algorithms to store cached data
struct Matrix {
    // Elements
    int *data;

    // Dimensions
    int width, height;

    // Create 00s matrix
    Matrix(int width, int height) {
        this->width = width;
        this->height = height;
        data = new int[width * height];
        Reset();
    }

    ~Matrix() {
        delete[] data;
    }

    // Zero all data
    void Reset() const {
        for (int i = 0; i < width * height; i++) data[i] = 0;
    }

    // Get a value
    int Get(int x, int y) const {
        return data[x + (y * width)];
    }

    // Set a value
    void Set(int x, int y, int n) const {
        data[x + (y * width)] = n;
    }
};

#endif //SPELLCHECKER_MATRIX_H

#pragma clang diagnostic pop