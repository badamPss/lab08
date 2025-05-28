#include "formatter.h"
#include "formatter_ex.h"
#include "solver.h"

#include <fstream>
#include <gtest/gtest.h>
#include <sstream>
#include <stdexcept>

TEST(Formatter, BasicFormatting) {
    std::string input = "hello";
    std::string expected = "-------------------------\nhello\n-------------------------\n";
    EXPECT_EQ(formatter(input), expected);
}

TEST(FormatterEx, StreamOutput) {
    std::stringstream ss;
    std::string message = "test message";
    std::string expected = "-------------------------\ntest message\n-------------------------\n";
    formatter(ss, message);
    EXPECT_EQ(ss.str(), expected);
}

TEST(Solver, QuadraticEquation) {
    float x1, x2;
    solve(1, -5, 6, x1, x2);
    EXPECT_TRUE((x1 == 2.0f && x2 == 3.0f) || (x1 == 3.0f && x2 == 2.0f));
    EXPECT_THROW(solve(1, 0, 1, x1, x2), std::logic_error);
}
