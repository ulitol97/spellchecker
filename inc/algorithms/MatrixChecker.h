#ifndef SPELLCHECKER_MATRIXCHECKER_H
#define SPELLCHECKER_MATRIXCHECKER_H

#include "SpellChecker.h"

class MatrixChecker : public SpellChecker {
public:
    int getEditDistance(std::string $str1, std::string $str2) override;

};


#endif //SPELLCHECKER_MATRIXCHECKER_H
