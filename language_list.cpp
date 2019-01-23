#include "language_list.h"

#include "english/english.h"
#include "russian/russian.h"

namespace {
std::unique_ptr<Language> make_english()
{
    ListOfRules rules{
        std::make_shared<KeepLetterE>()
    };

    return std::make_unique<English>(rules);
}

std::unique_ptr<Language> make_russian()
{
    ListOfRules rules{
        std::make_shared<VowelAfterSizzling>()
    };

    return std::make_unique<Russian>(rules);
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
