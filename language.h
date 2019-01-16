#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <memory>
#include <vector>

#include "rule.h"

using ListOfRules = std::vector<std::shared_ptr<Rule>>;

/**
 * @brief The Language class is an interface for a language
 */
class Language {
public:
    /**
     * @brief detect checks whether word is written in correspondent language
     * @param word original word
     * @return list of rules for correspondent language
     */
    virtual ListOfRules detect(const Word& word) = 0;
    virtual ~Language() = default;
};

#endif // LANGUAGE_H
