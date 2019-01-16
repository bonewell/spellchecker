#include "language_list.h"

#include "english/english.h"
#include "russian/russian.h"

namespace {
std::shared_ptr<Language> make_english()
{
    ListOfRules rules{
            std::shared_ptr<Rule>{new KeepLetterE{}}
    };

    return std::shared_ptr<Language>{new English{rules}};
}

std::shared_ptr<Language> make_russian()
{
    ListOfRules rules{
            std::shared_ptr<Rule>{new VowelAfterSizzling{}}
    };

    return std::shared_ptr<Language>{new Russian{rules}};
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
