#ifndef LEVENSHTEIN_SPELLCHECKER_INTERPRETER_H
#define LEVENSHTEIN_SPELLCHECKER_INTERPRETER_H

#include "algorithms/SpellChecker.h"

class Interpreter {
public:
    explicit Interpreter(std::string &dictionaryFile);

    void Run();

private:

    std::string dictionaryFile;
    std::vector<std::string> dictionary;
    SpellChecker *spellChecker;

    void LoadDictionary(std::vector<std::string> &dictionary);

    void AskAlgorithm();

    void AskInput();

    void Sanitize(std::string &str);

    bool ValidateInput(std::string &input);
};

#endif //LEVENSHTEIN_SPELLCHECKER_INTERPRETER_H
