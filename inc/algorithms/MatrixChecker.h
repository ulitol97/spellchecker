#ifndef SPELLCHECKER_MATRIXCHECKER_H
#define SPELLCHECKER_MATRIXCHECKER_H

#include <vector>
#include "SpellChecker.h"

class MatrixChecker : public SpellChecker {
public:
    MatrixChecker() : SpellChecker() {};
    
private:
    int getEditDistance(const char *word1, const char *word2) override;
};


#endif //SPELLCHECKER_MATRIXCHECKER_H
