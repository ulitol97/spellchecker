#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"

#include <cstring>
#include "algorithms/RecursiveChecker.h"

// Recursive version of Levenshtein: computes edit distance between two null terminated C strings.
// Based on Wikipedia: https://en.wikipedia.org/wiki/Levenshtein_distance
int RecursiveChecker::getEditDistance(const char *word1, const char *word2) {

    if (strlen(word1) == 0) return strlen(word2);
    else if (strlen(word2) == 0) return strlen(word1);
    else if (strlen(word1) == strlen(word2)) return getEditDistance(word1 + 1, word2 + 1);

    else
        return 1 + std::min(
                getEditDistance(word1 + 1, word2),
                std::min(
                        getEditDistance(word1, word2 + 1),
                        getEditDistance(word1 + 1, word2 + 1)
                )
        );
}

#pragma clang diagnostic pop