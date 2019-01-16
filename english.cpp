#include "english.h"

#include <array>

namespace {
bool IsEnglishLetter(char letter)
{
    constexpr int kA{'A'};
    constexpr int kZ{'Z'};
    constexpr int ka{'a'};
    constexpr int kz{'z'};
    constexpr std::array<int, 6> punctuation{int(' '), int('.'),
                int('-'), int('?'), int('!'), int(',')};

    int code{letter};
    return (kA <= code && code <= kZ) ||
           (ka <= code && code <= kz) ||
           std::find(std::begin(punctuation),
                     std::end(punctuation), code) != std::end(punctuation);
}
}  // namespace

English::English(ListOfRules rules): rules_{std::move(rules)}
{
}

ListOfRules English::detect(const String& text)
{
    for (auto c: text) {
        if (!IsEnglishLetter(c)) {
            return {};
        }
    }

    return rules_;
}
