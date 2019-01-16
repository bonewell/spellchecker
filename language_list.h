#ifndef LANGUAGE_LIST_H
#define LANGUAGE_LIST_H

#include <memory>
#include <vector>

#include "language.h"

using ListOfLanguages = std::vector<std::shared_ptr<Language>>;

/**
 * @brief GetLanguageList provides list of languages
 * @return list of langugages
 */
ListOfLanguages GetLanguageList();

#endif // LANGUAGE_LIST_H
