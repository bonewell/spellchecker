#ifndef RUSSIAN_H
#define RUSSIAN_H

#include "language.h"
#include "vowel_after_sizzling.h"

/**
 * @brief The Russian class represents Russian language
 */
class Russian: public Language {
public:
    /**
     * @brief Russian constructor
     * @param rules list of the rules
     */
    Russian(ListOfRules&& rules);

    /**
     * @brief detect checks whether word is written in Russian
     * @param word original word
     * @return list of rules for Russian language
     */
    const ListOfRules &detect(const Word& word) const override;

private:
    ListOfRules rules_;
};

#endif // RUSSIAN_H
