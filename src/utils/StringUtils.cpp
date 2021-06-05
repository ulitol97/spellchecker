#include <cstring>
#include <algorithm>
#include <iostream>
#include "utils/StringUtils.h"


// Trim string contents from the beginning (in place)
void StringUtils::Ltrim(std::string &str) {
    str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

// Trim string contents from the end (in place)
void StringUtils::Rtrim(std::string &str) {
    str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), str.end());
}

// Trim string contents from both ends (in place)
void StringUtils::Trim(std::string &str) {
    Ltrim(str);
    Rtrim(str);
}

// Return the number of words in a given string
unsigned StringUtils::CountWords(std::string &str) {

    // Create and array with the string characters
    char *chars = StringToChars(new char[str.length() + 1], str);

    // Start counting characters one by one
    int state = COUNTING_STATES::OUT;
    unsigned wordCount = 0; // word count

    while (*chars) {
        // If next character is a separator, state = OUT
        if (*chars == ' ' || *chars == '\n' || *chars == '\t') {
            state = COUNTING_STATES::OUT;
        }

            // If next character is not a separator and state is OUT, then state = IN and increment count
        else if (state == COUNTING_STATES::OUT) {
            state = COUNTING_STATES::IN;
            ++wordCount;
        }

        // Move to next character
        ++chars;
    }

    return wordCount;
}

// Return a string as a char array containing its characters
char *StringUtils::StringToChars(char *characters, std::string &str) {
    strcpy(characters, str.c_str());
    return characters;
}

// Return a char array as a string with all its characters
std::string StringUtils::CharsToString(char *characters) {
    std::string str;
    for (int i = 0; i < sizeof(characters); i++) {
        str += characters[i];
    }
    return str;
}

// Convert a string to lower case
void StringUtils::ToLower(std::string &str) {
    std::for_each(str.begin(), str.end(), [](char &c) {
        c = ::tolower(c);
    });
}

// Convert a string to upper case
void StringUtils::ToUpper(std::string &str) {
    std::for_each(str.begin(), str.end(), [](char &c) {
        c = ::toupper(c);
    });
}
