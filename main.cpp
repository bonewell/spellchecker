#include <iostream>

#include "language_list.h"

/**
 * @brief correct does changes of the word according with rules
 * @param rules list of rules
 * @param text in-out parameter with the word to check and correct
 */
void correct(const ListOfRules& rules, Word& word) {
    for (auto r: rules) {
        r->correct(word);
    }
}

/**
 * @brief process does processing the word
 * @param text in-out parameter with the word for processing
 */
void process(Word& word) {
    for (const auto& l: GetLanguageList()) {
        auto rules = l->detect(word);
        if (rules.size() != 0) {
            correct(rules, word);
            return;
        }
    }

    std::cout << "Unsupported language!\n";
}

int main(int argc, char* argv[])
{
    if (argc < 2) {
        std::cout << "Use: spellchecker <word>\n";
        return 0;
    }

    Word word{argv[1]};
    process(word);

    std::cout << word << "\n";
    return 0;
}
