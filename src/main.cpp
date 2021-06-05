#include <iostream>
#include <cstring>
#include <csignal>
#include <algorithm>
#include "spellchecker/Interpreter.h"
#include <utils/StringUtils.h>


const std::string programName = "spellchecker";
const std::string defaultDictionaryLocation = "dictionary.txt";
std::string dictionaryLocation;

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
              "\t" << "-h | --help        Show usage instructions" << "\n" <<
              "\t" << "-d | --dict        Relative path of the dictionary to be used for spellchecking" << "\n" <<
              std::endl;
}

void ParseArguments(int argc, char *argv[]) {

    // Standard execution: look for a dictionary in default location
    if (argc == 1) {
        dictionaryLocation = defaultDictionaryLocation;
    }
        // Specify custom dictionary
    else if (argc == 3 && (strcmp(argv[1], "-d") == 0 || strcmp(argv[1], "--dict") == 0)) {
        dictionaryLocation = argv[2];
    }
        // Print help and exit
    else if (argc == 2 && (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)) {
        PrintInformation();
        PrintHelp();
        exit(EXIT_SUCCESS);
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
    Interpreter interpreter(dictionaryLocation);
    interpreter.Run();

    return 0;
}









