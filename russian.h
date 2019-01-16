#ifndef RUSSIAN_H
#define RUSSIAN_H

#include "language.h"

class Russian {
public:
    Russian(ListOfRules rules);
    ListOfRules detect(const String& text);
private:
    ListOfRules rules_;
};

#endif // RUSSIAN_H
