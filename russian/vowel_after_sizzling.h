#ifndef VOWELAFTERSIZZLING_H
#define VOWELAFTERSIZZLING_H

#include "rule.h"

/**
 * @brief The VowelAfterSizzling class
 * After ж, ч, ш, щ are not written ю, я, ы but written у, а, и
 */
class VowelAfterSizzling : public Rule
{
public:
    VowelAfterSizzling() = default;

    /**
     * @brief correct does changing of the word according with the rule
     * @param word in-out parameter contains word
     */
    void correct(Word& word) const override;
};

#endif // VOWELAFTERSIZZLING_H
