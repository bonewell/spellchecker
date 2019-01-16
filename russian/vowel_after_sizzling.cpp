#include "vowel_after_sizzling.h"

#include <regex>
#include <vector>
#include <string>

namespace {
std::vector<std::pair<std::regex, std::string>> replacements = {
    std::make_pair(std::regex{R"(жю)"}, "жу"),
    std::make_pair(std::regex{R"(жы)"}, "жи"),
    std::make_pair(std::regex{R"(жя)"}, "жа"),
    std::make_pair(std::regex{R"(чю)"}, "чу"),
    std::make_pair(std::regex{R"(чы)"}, "чи"),
    std::make_pair(std::regex{R"(чя)"}, "ча"),
    std::make_pair(std::regex{R"(шю)"}, "шу"),
    std::make_pair(std::regex{R"(шы)"}, "ши"),
    std::make_pair(std::regex{R"(шя)"}, "ша"),
    std::make_pair(std::regex{R"(щю)"}, "щу"),
    std::make_pair(std::regex{R"(щы)"}, "щи"),
    std::make_pair(std::regex{R"(щя)"}, "ща")
};
}

void VowelAfterSizzling::correct(Word& word)
{
    for (const auto& bind: replacements) {
        word = std::regex_replace(word, bind.first, bind.second);
    }
}
