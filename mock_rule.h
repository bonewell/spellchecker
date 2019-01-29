#ifndef MOCK_RULE_H
#define MOCK_RULE_H

#include <gmock/gmock.h>

#include "rule.h"

class MockRule : public Rule {
 public:
  MOCK_CONST_METHOD1(correct,
      void(Word& word));
};

#endif // MOCK_RULE_H
