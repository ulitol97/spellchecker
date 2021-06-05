#ifndef LEVENSHTEIN_UTILS_STRINGUTILS_H
#define LEVENSHTEIN_UTILS_STRINGUTILS_H

class StringUtils {
public:

    static void Ltrim(std::string &str);

    static void Rtrim(std::string &str);

    static void Trim(std::string &str);

    static void ToUpper(std::string &str);

    static void ToLower(std::string &str);

    static unsigned CountWords(std::string &str);

    static char *StringToChars(char *characters, std::string &str);

    static std::string CharsToString(char *characters);

private:
    enum COUNTING_STATES {
        IN, OUT
    };
};

#endif //LEVENSHTEIN_UTILS_STRINGUTILS_H
