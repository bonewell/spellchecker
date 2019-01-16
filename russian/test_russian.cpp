#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "russian/russian.h"
#include "mock_rule.h"

using namespace ::testing;

TEST(RussianTest, TextIsRussian) {
    Russian rus{ListOfRules{std::shared_ptr<Rule>{new MockRule{}}}};
    auto rules = rus.detect("русский текст");

    ASSERT_THAT(rules.size(), Eq(1));
}

TEST(RussianTest, TextIsNotRussian) {
    Russian rus{ListOfRules{std::shared_ptr<Rule>{new MockRule{}}}};
    auto rules = rus.detect("english text");

    ASSERT_THAT(rules.size(), Eq(0));
}

TEST(VowelAfterSizzlingTest, ChangeYu) {
    VowelAfterSizzling rule;
    Word text = "жюк";
    rule.correct(text);

    ASSERT_THAT(text, Eq(Word{"жук"}));
}

TEST(VowelAfterSizzlingTest, ChangeY) {
    VowelAfterSizzling rule;
    Word text = "шыть";
    rule.correct(text);

    ASSERT_THAT(text, Eq(Word{"шить"}));
}
