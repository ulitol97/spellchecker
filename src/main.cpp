#include <iostream>
#include <csignal>
#include <algorithm>
#include "spellchecker/interpreter.h"

void LoadDictionary();

void signalHandler(int signum) {
    std::cout << "\nClosing... (signal " << signum << " received).\n";

    // cleanup and close up stuff here  
    // terminate program  

    exit(signum);
}

int main() {

    // register signal handlers
    signal(SIGINT, signalHandler);
    signal(SIGQUIT, signalHandler);

    LoadDictionary();

    Interpreter interpreter;
    interpreter.Run();

    return 0;
}


void LoadDictionary() {
    std::cout << "The dictionary file loaded successfully" << std::endl;
    // TODO
}




