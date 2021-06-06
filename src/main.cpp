#include <iostream>
#include <cstring>
#include <csignal>
#include <algorithm>
#include "spellchecker/Interpreter.h"
#include <utils/StringUtils.h>


const std::string programName = "spellchecker";
const std::string defaultDictionaryLocation = "dictionary.txt";
std::string dictionaryLocation = defaultDictionaryLocation;
int nSuggestions = SpellChecker::defaultSuggestions;

void signalHandler(int signum) {
    std::cout << "\nClosing...\n";
    exit(signum);
}

void registerSignals() {
    signal(SIGINT, signalHandler);
    signal(SIGTERM, signalHandler);
    signal(SIGQUIT, signalHandler);
}

void PrintInformation() {
    std::cout <<
              "Spellchecker implementing the Levenshtein Distance algorithm to correct user input." << "\n" <<
              R"(User input is compared against a dictionary located in "dictionary.txt" or a user-defined location (see "-d").)"
              << "\n" <<
              std::endl;
}

void PrintHelp() {
    std::cout <<
              "USAGE: " << programName << " [ARGS]" << "\n" <<
              "OPTIONS:" << "\n" <<
              "\t" << "-h | --help          Show usage instructions" << "\n" <<
              "\t"
              << "-d | --dict          Relative path of the dictionary to be used for spellchecking (default is dictionary.txt)"
              << "\n" <<
              "\t" << "-s | --suggestions   Number of suggestions made by the spellchecker (1-20, default is 5)" << "\n"
              <<
              std::endl;
}

void ParseArguments(int argc, char *argv[]) {
    if (argc == 1) {
        return;
    }
    // Print help and exit
    if (argc == 2 && (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)) {
        PrintInformation();
        PrintHelp();
        exit(EXIT_SUCCESS);
    }
        // Pair args: dictionary, suggestions...
    else if (argc >= 3 && (argc + 1) % 2 == 0) {
        int argIndex = 1;
        while (argIndex + 2 <= argc) {
            // Dictionary
            if (strcmp(argv[argIndex], "-d") == 0 || strcmp(argv[argIndex], "--dict") == 0) {
                dictionaryLocation = argv[argIndex + 1];
                argIndex += 2;
            }
                // Suggestions
            else if (strcmp(argv[argIndex], "-s") == 0 || strcmp(argv[argIndex], "--suggestions") == 0) {
                nSuggestions = std::stoi(argv[argIndex + 1]);
                argIndex += 2;
            } else {
                std::cout << "Bad usage:" << std::endl;
                PrintHelp();
                exit(EXIT_FAILURE);
            }
        }
    }
        // Bad input. Print help and exit
    else {
        std::cout << "Bad usage:" << std::endl;
        PrintHelp();
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {

    // register signal handlers for clean exit   
    registerSignals();
    // parse user arguments (if any)
    ParseArguments(argc, argv);
    // start spellchecker interpreter
    Interpreter interpreter(dictionaryLocation, nSuggestions);
    interpreter.Run();

    return 0;
}









