#ifndef SPELLCHECKER_SPELLCHECKER_H
#define SPELLCHECKER_SPELLCHECKER_H


#include <string>

class SpellChecker {
public:
    virtual int getEditDistance(std::string $str1, std::string $str2) = 0;
};


#endif //SPELLCHECKER_SPELLCHECKER_H
