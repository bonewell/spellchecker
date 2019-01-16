#include "keep_letter_e.h"

namespace {
Word::size_type FindSuffix(const Word& word) {
    auto pos = word.rfind("able");
    return (pos != Word::npos) ? pos : word.rfind("ous");
}

bool IsMistake(const Word& word, Word::size_type pos) {
    return pos > 2 && (word[pos-1] == 'g' || word[pos-1] == 'c');
}
}  // namespace

void KeepLetterE::correct(Word& word)
{
    /*
     * Keep «e» if add «-ous» and «-able» to a word with «-ge» or «-ce»
     * Courage + ous = courageous, Change + able = changeable
     */
    auto pos = FindSuffix(word);
    if (IsMistake(word, pos)) {
        word.insert(pos, "e");
    }
}
