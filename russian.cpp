#include "russian.h"

#include <regex>

Russian::Russian(ListOfRules rules): rules_{std::move(rules)}
{
}

ListOfRules Russian::detect(const String& text)
{
//    std::regex pattern{R"([А-яа-я !?,.-]+)"};
    std::regex pattern{R"([ЙЦУКЕНГШЩЗХЪФЫВАПРОЛДЖЭЁЯЧСМИТЬБЮ
                       йцукенгшщзхъфывапролджэёячсмитьбю !?,.-]+)"};
    if (std::regex_match(text, pattern)) {
        return rules_;
    }

    return {};
}
