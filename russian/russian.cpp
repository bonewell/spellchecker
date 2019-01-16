#include "russian.h"

#include <regex>

namespace {
std::regex pattern{R"([ЙЦУКЕНГШЩЗХЪФЫВАПРОЛДЖЭЁЯЧСМИТЬБЮ
                       йцукенгшщзхъфывапролджэёячсмитьбю !?,.-]+)"};
}

Russian::Russian(ListOfRules rules): rules_{std::move(rules)}
{
}

ListOfRules Russian::detect(const Word& word)
{
    if (std::regex_match(word, pattern)) {
        return rules_;
    }

    return {};
}
