#ifndef SPELLCHECKER_RECURSIVECHECKER_H
#define SPELLCHECKER_RECURSIVECHECKER_H

#include <vector>
#include "SpellChecker.h"

class RecursiveChecker : public SpellChecker {
public:
    RecursiveChecker() : SpellChecker() {};

private:
    int getEditDistance(const char *word1, const char *word2) override;
};


#endif //SPELLCHECKER_RECURSIVECHECKER_H
