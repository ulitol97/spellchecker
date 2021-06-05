#ifndef SPELLCHECKER_SINGLEROWCHECKER_H
#define SPELLCHECKER_SINGLEROWCHECKER_H

#include "SpellChecker.h"

class SingleRowChecker : public SpellChecker {
public:
    int getEditDistance(std::string $str1, std::string $str2) override;

};


#endif //SPELLCHECKER_SINGLEROWCHECKER_H
