#ifndef LEVENSHTEIN_SPELLCHECKER_INTERPRETER_H
#define LEVENSHTEIN_SPELLCHECKER_INTERPRETER_H

#include "algorithms/SpellChecker.h"

class Interpreter {
public:

    explicit Interpreter(std::string &dictionaryFile, int nSuggestions = SpellChecker::defaultSuggestions);

    void Run();

private:

    int nSuggestions;
    std::string dictionaryFile;
    std::vector<std::string> dictionary;
    SpellChecker *spellChecker;

    void LoadDictionary(std::vector<std::string> &dict);

    [[nodiscard]] SpellChecker *AskAlgorithm() const;

    void AskInput();

    void Sanitize(std::string &str);

    bool ValidateInput(std::string &input);

    long ComputeResults(std::string &word);
};

#endif //LEVENSHTEIN_SPELLCHECKER_INTERPRETER_H
