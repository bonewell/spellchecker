#ifndef RULE_H
#define RULE_H

#include <string>

using Word = std::string;

/**
 * @brief The Rule class is an interface for language rules
 */
class Rule {
public:
    /**
     * @brief correct does changing of the word according with the rule
     * @param word in-out parameter contains word
     */
    virtual void correct(Word& word) = 0;
    virtual ~Rule() = default;
};

#endif // RULE_H
