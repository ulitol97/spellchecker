#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"

#include <iostream>
#include <cstring>
#include "algorithms/SingleRowChecker.h"
#include "utils/Matrix.h"

// Compute Levenshtein using 1 row. Based on:
// https://rosettacode.org/wiki/Levenshtein_distance#C.2B.2B
int SingleRowChecker::getEditDistance(const char *word1, const char *word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);

    if (len1 == 0) return len2;
    else if (len2 == 0) return len1;

    int *prevRow = new int[len1 + 1];

    // Initialize first row
    for (int i = 0; i <= len1; i++) {
        prevRow[i] = i;
    }

    for (int y = 0; y < len2; y++) {

        // Init the start of the row and corner value
        prevRow[0] = y + 1;
        int corner = y;

        for (int x = 0; x < len1; x++) {

            // Record [x+1] before it is redefined
            int upper = prevRow[x + 1];

            if (word1[x] == word2[y]) prevRow[x + 1] = corner;
            else
                prevRow[x + 1] = std::min(
                        upper, // Insertion
                        std::min(
                                corner, // Substitution
                                prevRow[x] // Deletion
                        )
                ) + 1;

            corner = upper;

        }

    }

    // The final distance is at the end of the row
    return prevRow[len1];
}

#pragma clang diagnostic pop