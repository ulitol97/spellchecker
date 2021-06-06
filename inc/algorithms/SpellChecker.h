#ifndef SPELLCHECKER_SPELLCHECKER_H
#define SPELLCHECKER_SPELLCHECKER_H

#include <vector>
#include <string>
#include <queue>
#include "utils/Order.h"

class SpellChecker {
public:
    SpellChecker() = default;

    static const int defaultSuggestions = 5;

    explicit SpellChecker(int nSuggestions) {
        this->nSuggestions = std::min(std::max(1, nSuggestions), maxSuggestions);
    };

    virtual ~SpellChecker() = default;

    void GetClosestWords(std::priority_queue<Order> &results, const std::string &word,
                         const std::vector<std::string> &dictionary);

protected:
    const int maxSuggestions = 20;
    int nSuggestions = defaultSuggestions;

private:
    virtual int getEditDistance(const char *$word1, const char *$word2) = 0;
};


#endif //SPELLCHECKER_SPELLCHECKER_H
