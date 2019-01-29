#include "russian.h"

#include <regex>

namespace {
std::regex kPattern{R"([ЙЦУКЕНГШЩЗХЪФЫВАПРОЛДЖЭЁЯЧСМИТЬБЮ
                       йцукенгшщзхъфывапролджэёячсмитьбю !?,.-]+)"};

ListOfRules kEmpty;
}

Russian::Russian(ListOfRules&& rules): rules_{std::move(rules)}
{
}

const ListOfRules& Russian::detect(const Word& word) const
{
    if (std::regex_match(word, kPattern)) {
        return rules_;
    }

    return kEmpty;
}
