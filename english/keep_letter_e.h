#ifndef FULSUFFIX_H
#define FULSUFFIX_H

#include "rule.h"

/**
 * @brief The KeepLetterE class
 * Keep «e» if add «-ous» and «-able» to a word with «-ge» or «-ce»
 * Courage + ous = courageous, Change + able = changeable
 */
class KeepLetterE : public Rule
{
public:
    KeepLetterE() = default;

    /**
     * @brief correct does changing of the word according with the rule
     * @param word in-out parameter contains word
     */
    void correct(Word& word) const override;
};

#endif // FULSUFFIX_H
