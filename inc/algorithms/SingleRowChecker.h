#ifndef SPELLCHECKER_SINGLEROWCHECKER_H
#define SPELLCHECKER_SINGLEROWCHECKER_H

#include <vector>
#include "SpellChecker.h"

class SingleRowChecker : public SpellChecker {
public:
    SingleRowChecker() = default;

    explicit SingleRowChecker(int nWords) : SpellChecker(nWords) {};

private:
    int getEditDistance(const char *$word1, const char *$word2) override;

};


#endif //SPELLCHECKER_SINGLEROWCHECKER_H
