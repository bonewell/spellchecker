#ifndef ENGLISH_H
#define ENGLISH_H

#include "language.h"
#include "keep_letter_e.h"

/**
 * @brief The Russian class represents English language
 */
class English : public Language
{
public:
    /**
     * @brief English constructor
     * @param rules list of the rules
     */
    English(ListOfRules rules);

    /**
     * @brief detect checks whether text is written in English
     * @param word original word
     * @return list of rules for English language
     */
    ListOfRules detect(const Word& word) override;

private:
    ListOfRules rules_;
};

#endif // ENGLISH_H
