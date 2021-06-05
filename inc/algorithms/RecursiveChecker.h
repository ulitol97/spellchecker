#ifndef SPELLCHECKER_RECURSIVECHECKER_H
#define SPELLCHECKER_RECURSIVECHECKER_H

#include "SpellChecker.h"

class RecursiveChecker : public SpellChecker {
public:
    int getEditDistance(std::string $str1, std::string $str2) override;

};


#endif //SPELLCHECKER_RECURSIVECHECKER_H
