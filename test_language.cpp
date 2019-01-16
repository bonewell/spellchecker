#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "english.h"
#include "russian.h"

using namespace ::testing;

TEST(LanguageTest, English) {
    English eng{ListOfRules{1}};
    auto rules = eng.detect("english text");

    ASSERT_THAT(rules.size(), Eq(1));
}

TEST(LanguageTest, NotEnglish) {
    English eng{ListOfRules{1}};
    auto rules = eng.detect("русский текст");

    ASSERT_THAT(rules.size(), Eq(0));
}

TEST(LanguageTest, Russian) {
    Russian rus{ListOfRules{1}};
    auto rules = rus.detect("русский текст");

    ASSERT_THAT(rules.size(), Eq(1));
}

TEST(LanguageTest, NotRussian) {
    Russian rus{ListOfRules{1}};
    auto rules = rus.detect("english text");

    ASSERT_THAT(rules.size(), Eq(0));
}
