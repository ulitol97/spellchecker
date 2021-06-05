#pragma clang diagnostic push
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <iostream>
#include <string>
#include <regex>
#include <utils/StringUtils.h>
#include <fstream>
#include <filesystem>
#include "spellchecker/Interpreter.h"
#include "algorithms/RecursiveChecker.h"
#include "algorithms/MatrixChecker.h"
#include "algorithms/SingleRowChecker.h"

// Create and Interpreter object and try to load the words in the dictionary
Interpreter::Interpreter(std::string &dictionaryFile) {
    this->dictionaryFile = dictionaryFile; // File with the dictionary

    this->dictionary = std::vector<std::string>{}; // Dictionary data
    LoadDictionary(dictionary);

}

// Begin the spellchecker "console", constantly asking the user for input until interruption.
void Interpreter::Run() {
    AskAlgorithm();
    AskInput();
}

// Loads all the lines in the Interpreter's dictionary into the specified vector.
void Interpreter::LoadDictionary(std::vector<std::string> &dictionary) {
    std::cout << "Loading words from \"" << dictionaryFile << "\"... ";

    std::string line;
    std::ifstream file(dictionaryFile);

    // Non-existing file
    if (!std::filesystem::exists(dictionaryFile) || !file.is_open()) {
        std::cout << "FAILURE" << std::endl;
        return;
    }

    // Read and store line by line
    while (std::getline(file, line)) {
        dictionary.push_back(line);
    }

    file.close();
    std::cout << "SUCCESS (read " << dictionary.size() << " words)" << std::endl;
}

// Ask the user the algorithm variant he/she wants to use and store it
void Interpreter::AskAlgorithm() {
    std::cout <<
              "The edit distance between words can be computed in 3 ways:" << "\n" <<
              "\t1 -> " << "Levenshtein recursive algorithm (very slow)" << "\n" <<
              "\t2 -> " << "Wagner–Fischer algorithm - full matrix (fast)" << "\n" <<
              "\t3 -> " << "Wagner–Fischer algorithm - single row  (fastest)" << "\n" <<
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
            RecursiveChecker checker;
            this->spellChecker = &checker;
        } else if (option == '2') {
            MatrixChecker checker;
            this->spellChecker = &checker;
        } else {
            SingleRowChecker checker;
            this->spellChecker = &checker;
        }
        break;
    }

}

// Ask the user for a word, sanitize it and pass it to the algorithm
void Interpreter::AskInput() {
    // User input string
    std::string input;

    // Profiling elapsed time
    long startTime;
    long elapsedTime;

    // Endless loop
    while (std::cin.good()) {

        // Ask for input until it is valid
        while (true) {
            std::cout << "Enter a word into the spellchecker (<Ctrl+C> to exit): ";
            getline(std::cin, input);

            Sanitize(input);
            if (ValidateInput(input)) break;
        }

        startTime = clock();
        std::cout << "The word introduced was: " << input << std::endl;
        // TODO: compute distance to the words in the dictionary
        this->spellChecker->getEditDistance(input, "");
        elapsedTime = clock() - startTime;
        std::cout << "Done in " << (float) elapsedTime / CLOCKS_PER_SEC << " seconds" << std::endl;
    }
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
        std::cout << "Invalid input: 1 word only" << std::endl;
        return false;
    }

    if (!std::regex_match(input, std::regex("([a-z]+)"))) {
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