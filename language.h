#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <vector>
#include <string>

using Rule = int;
using ListOfRules = std::vector<Rule>;
using String = std::string;

class Language {
public:
    virtual ListOfRules detect(const String& text) = 0;
    ~Language() = default;
};

#endif // LANGUAGE_H
