#ifndef ENGLISH_H
#define ENGLISH_H

#include "language.h"

class English : public Language
{
public:
    English(ListOfRules rules);
    ListOfRules detect(const String& text);
private:
    ListOfRules rules_;
};

#endif // ENGLISH_H
