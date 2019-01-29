#include "language_list.h"

#include "english/english.h"
#include "russian/russian.h"

namespace {
std::unique_ptr<Language> make_english()
{
    ListOfRules rules;
    rules.push_back(std::make_unique<KeepLetterE>());

    return std::make_unique<English>(std::move(rules));
}

std::unique_ptr<Language> make_russian()
{
    ListOfRules rules;
    rules.push_back(std::make_unique<VowelAfterSizzling>());

    return std::make_unique<Russian>(std::move(rules));
}
}  // namespace

/**
 * @brief GetLanguageList builds supported languages
 * @return list of languages
 */
ListOfLanguages GetLanguageList()
{
    ListOfLanguages languages;

    languages.push_back(make_english());
    languages.push_back(make_russian());

    return languages;
}
