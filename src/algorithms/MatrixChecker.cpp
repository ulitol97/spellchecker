#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"

#include <cstring>
#include "algorithms/MatrixChecker.h"
#include "utils/Matrix.h"

// Computes edit distance using a 2D matrix.
// Based on Wikipedia: https://en.wikipedia.org/wiki/Levenshtein_distance
int MatrixChecker::getEditDistance(const char *word1, const char *word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);

    if (len1 == 0) return len2;
    else if (len2 == 0) return len1;

    Matrix matrix = Matrix(len1 + 1, len2 + 1);

    // Set the first row known data (0, 1, 2, 3...)
    for (int i = 0; i <= len1; i++) matrix.Set(i, 0, i);
    // Set the first column known data (0, 1, 2, 3...)
    for (int i = 0; i <= len2; i++) matrix.Set(0, i, i);

    // Fill the matrix
    for (int y = 1; y <= len2; y++) {
        for (int x = 1; x <= len1; x++) {

            // Assume substitution cost is 1
            int substitutionCost = 1;

            // If the two elements are equal, substitution cost is 0
            if (word1[x - 1] == word2[y - 1])
                substitutionCost = 0;

            // Set current element to the lowest of the three possibilities
            matrix.Set(x, y, std::min(
                    matrix.Get(x - 1, y) + 1,
                    std::min(
                            matrix.Get(x, y - 1) + 1,
                            matrix.Get(x - 1, y - 1) + substitutionCost
                    )

            ));
        }
    }

    // The final distance is at the end of the matrix
    return matrix.Get(len1, len2);
}

#pragma clang diagnostic pop