#ifndef SPELLCHECKER_SPELLCHECKER_H
#define SPELLCHECKER_SPELLCHECKER_H

#include <vector>
#include <string>
#include <queue>
#include "utils/Order.h"

class SpellChecker {
public:
    SpellChecker() = default;

    inline static const int defaultSuggestions = 5;
    inline static const int minSuggestions = 1;
    inline static const int maxSuggestions = 20;

    virtual ~SpellChecker() = default;

    void GetClosestWords(std::priority_queue<Order> &results, const std::string &word,
                         const std::vector<std::string> &dictionary);

private:
    virtual int getEditDistance(const char *$word1, const char *$word2) = 0;
};


#endif //SPELLCHECKER_SPELLCHECKER_H
