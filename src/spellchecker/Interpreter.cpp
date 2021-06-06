#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-pro-type-member-init"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <filesystem>
#include <queue>
#include "utils/Order.h"
#include "utils/StringUtils.h"
#include "spellchecker/Interpreter.h"
#include "algorithms/SpellChecker.h"
#include "algorithms/RecursiveChecker.h"
#include "algorithms/MatrixChecker.h"
#include "algorithms/SingleRowChecker.h"

// Create and Interpreter object and try to load the words in the dictionary
Interpreter::Interpreter(std::string &dictionaryFile, int nSuggestions) {
    this->nSuggestions = std::min(std::max(SpellChecker::minSuggestions, nSuggestions), SpellChecker::maxSuggestions);
    this->dictionaryFile = dictionaryFile; // File with the dictionary
    this->dictionary = std::vector<std::string>{}; // Dictionary data
    LoadDictionary(dictionary);

}

// Begin the spellchecker "console", constantly asking the user for input until interruption.
void Interpreter::Run() {
    this->spellChecker = AskAlgorithm();
    AskInput();
    delete this->spellChecker;
}

// Loads all the lines in the Interpreter's dict into the specified vector.
void Interpreter::LoadDictionary(std::vector<std::string> &dict) {
    std::cout << "Loading words from \"" << dictionaryFile << "\"... " << std::endl;

    std::string line;
    std::ifstream file(dictionaryFile);

    // Non-existing file
    if (!std::filesystem::exists(dictionaryFile) || !file.is_open()) {
        std::cerr << "FAILURE: file \"" << dictionaryFile << "\" not found" << std::endl;
        exit(101);
    }

    // Read and store line by line
    while (std::getline(file, line)) {
        dict.push_back(line);
    }
    file.close();

    if (dict.empty()) {
        std::cerr << "FAILURE: empty dictionary" << std::endl;
        exit(102);
    } else std::cout << "SUCCESS (read " << dict.size() << " words)" << std::endl;
}

// Ask the user the algorithm variant he/she wants to use and store it
SpellChecker *Interpreter::AskAlgorithm() const {
    std::cout <<
              "\nThe edit distance between words can be computed in 3 ways:" << "\n" <<
              "\t1 -> " << "Levenshtein recursive algorithm (very slow - O(n^3))" << "\n" <<
              "\t2 -> " << "Wagner–Fischer algorithm - full matrix (fast - O(n^2))" << "\n" <<
              "\t3 -> " << "Wagner–Fischer algorithm - single row  (fastest - O(n^2))" << "\n" <<
              std::endl;

    std::string input;
    char option;

    while (true) {
        std::cout << "How to compute the levenshtein distance? [1/2/3]: ";
        getline(std::cin, input);
        option = input[0];

        if (input.length() != 1 || (option != '1' && option != '2' && option != '3')) {
            continue;
        }

        if (option == '1') {
            auto *checker = new RecursiveChecker();
            return checker;
        } else if (option == '2') {
            auto *checker = new MatrixChecker();
            return checker;
        } else {
            auto *checker = new SingleRowChecker();
            return checker;
        }
    }

}

// Ask the user for a word, sanitize it and pass it to the algorithm
void Interpreter::AskInput() {
    // User input string
    std::string input;

    // results list
    std::vector<std::string> results;

    // Endless loop
    while (std::cin.good()) {

        // Ask for input until it is valid
        while (true) {
            std::cout << "Enter a word into the spellchecker: ";
            getline(std::cin, input);

            Sanitize(input);
            if (ValidateInput(input)) break;
        }


        ComputeResults(input);
    }
}

// Run the algorithm and eventually print the results.
long Interpreter::ComputeResults(std::string &word) {

    // Profiling elapsed time
    long startTime = clock();

    // Compute results, storing them in a priority queue
    std::priority_queue<Order> queue;
    spellChecker->GetClosestWords(queue, word, dictionary);

    long elapsedTime = clock() - startTime;

    // Print results
    std::cout << "RESULTS (" << (float) elapsedTime / CLOCKS_PER_SEC << " seconds)" << ":\n";
    for (int i = 1; i <= nSuggestions; i++) {
        if (queue.empty()) break;

        Order o = queue.top();
        std::cout << "\t" << i << ". " << dictionary[o.index];
        if (strcmp(word.data(), dictionary[o.index].data()) == 0) std::cout << " <= User input";
        std::cout << "\n";

        queue.pop();
    }
    std::cout << std::endl;

    return elapsedTime;
}

// Validate user input to make sure if conforms to the program needs
bool Interpreter::ValidateInput(std::string &input) {
    // No empty
    if (input.length() == 0) {
        std::cout << "Invalid input: empty word" << std::endl;
        return false;
    }

    // One word only
    if (StringUtils::CountWords(input) != 1) {
        std::cout << "Invalid input: enter only 1 word" << std::endl;
        return false;
    }

    if (!std::regex_match(input, std::regex(
            "^[a-zA-ZÀ-ÿ\\u00f1\\u00d1]+[a-zA-ZÀ-ÿ\\u00f1\\u00d1\\u0302]*+$"))) {
        std::cout << "Invalid input: only letters are allowed" << std::endl;
        return false;
    }
    return true;
}

// For a given user input, sanitize it to make sure if conforms to the program needs
void Interpreter::Sanitize(std::string &str) {
    StringUtils::Trim(str);
    StringUtils::ToLower(str);
}


#pragma clang diagnostic pop