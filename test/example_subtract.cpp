
#include "gtest/gtest.h"
#include "Solution.cpp"



TEST(example, subtract) {
    Solution s;
    ASSERT_EQ(true, s.isValid("()"));
    ASSERT_EQ(true, s.isValid("()[]{}"));
    ASSERT_EQ(false, s.isValid("(]"));
     ASSERT_EQ(false, s.isValid("([)]"));
    ASSERT_EQ(true, s.isValid("{[]}"));
}


