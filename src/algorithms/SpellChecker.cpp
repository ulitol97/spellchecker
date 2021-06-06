#include <iostream>
#include "algorithms/SpellChecker.h"
#include <queue>
#include "utils/Order.h"

// Get the "n" closest words in "dictionary" to "word" and store them in "results"
void SpellChecker::GetClosestWords(std::priority_queue<Order> &results, const std::string &word,
                                   const std::vector<std::string> &dictionary) {

    for (int i = 0; i < dictionary.size(); ++i) {
//        std::cout << "Computing distance between: \"" << word << "\" and \"" << dictionary[i] << "\"..." << std::endl;
        int distance = getEditDistance(word.data(), dictionary[i].data());
        results.push(Order(i, distance));
    }

}
