#ifndef SPELLCHECKER_SINGLEROWCHECKER_H
#define SPELLCHECKER_SINGLEROWCHECKER_H

#include <vector>
#include "SpellChecker.h"

class SingleRowChecker : public SpellChecker {
public:
    SingleRowChecker() : SpellChecker() {};

private:
    int getEditDistance(const char *word1, const char *word2) override;

};


#endif //SPELLCHECKER_SINGLEROWCHECKER_H
