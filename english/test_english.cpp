#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "english/english.h"
#include "english/keep_letter_e.h"
#include "mock_rule.h"

using namespace ::testing;

TEST(EnglishTest, TextIsEnglish) {
    English eng{ListOfRules{std::shared_ptr<Rule>{new MockRule{}}}};
    auto rules = eng.detect("english text");

    ASSERT_THAT(rules.size(), Eq(1));
}

TEST(EnglishTest, TextIsNotEnglish) {
    English eng{ListOfRules{std::shared_ptr<Rule>{new MockRule{}}}};
    auto rules = eng.detect("русский текст");

    ASSERT_THAT(rules.size(), Eq(0));
}

TEST(KeepLetterETest, AddEBeforeAble) {
    KeepLetterE rule;
    Word text = "changable";
    rule.correct(text);

    ASSERT_THAT(text, Eq(Word{"changeable"}));
}

TEST(KeepLetterETest, AddEBeforeOus) {
    KeepLetterE rule;
    Word text = "couragous";
    rule.correct(text);

    ASSERT_THAT(text, Eq(Word{"courageous"}));
}

TEST(KeepLetterETest, CorrectSpelling) {
    KeepLetterE rule;
    Word text = "courageous";
    rule.correct(text);

    ASSERT_THAT(text, Eq(Word{"courageous"}));
}
