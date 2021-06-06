#ifndef SPELLCHECKER_MATRIXCHECKER_H
#define SPELLCHECKER_MATRIXCHECKER_H

#include <vector>
#include "SpellChecker.h"

class MatrixChecker : public SpellChecker {
public:
    MatrixChecker() = default;

    explicit MatrixChecker(int nWords) : SpellChecker(nWords) {};;
    
private:
    int getEditDistance(const char *$word1, const char *$word2) override;
};


#endif //SPELLCHECKER_MATRIXCHECKER_H
