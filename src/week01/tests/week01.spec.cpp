#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <src/week01/week01.hpp>

using namespace annzy::week01;
// 1. Typing Game
TEST_CASE("week01::Testing correctStream") {
    REQUIRE_EQ(correctStream({"it", "is", "find"}, {"it", "is", "fine"}),
               std::vector<int>{1, 1, -1});
    REQUIRE_EQ(correctStream({"april", "showrs", "bring", "may", "floFwers"},
                             {"april", "showers", "bring", "may", "flowers"}),
               std::vector<int>{1, -1, 1, 1, 1});
    REQUIRE_EQ(correctStream({"weird", "indicr", "moment"}, {"weird", "indict", "moment"}),
               std::vector<int>{1, -1, 1});
    REQUIRE_EQ(correctStream({"starry", "wind", "skies"}, {"starry", "wind", "skies"}),
               std::vector<int>{1, 1, 1});
}

// 2. Negate the List
TEST_CASE("week01::Testing negate") {
    REQUIRE_EQ(negate({1, 2, 3, 4}), std::vector<int>{-1, -2, -3, -4});
    REQUIRE_EQ(negate({-1, -2, -3, -4}), std::vector<int>{1, 2, 3, 4});
    REQUIRE_EQ(negate({}), std::vector<int>{});
}

// 3. Exists a Number Higher?
TEST_CASE("week01::Testing existsHigher") {
    REQUIRE(existsHigher({5, 3, 15, 22, 4}, 10));
    REQUIRE(existsHigher({5, 3, 15, 22, 4}, 20));
    REQUIRE_FALSE(existsHigher({4, 3, 3, 3, 2, 2, 2}, 4));
    REQUIRE_FALSE(existsHigher({1, 2, 3, 4, 5}, 8));
    REQUIRE_FALSE(existsHigher({}, 5));
}

// 4. Word Endings
TEST_CASE("week01::Testing addEnding") {
    REQUIRE_EQ(addEnding({"clever", "meek", "hurried", "nice"}, "ly"),
               std::vector<std::string>{"cleverly", "meekly", "hurriedly", "nicely"});
    REQUIRE_EQ(addEnding({"new", "pander", "scoop"}, "er"),
               std::vector<std::string>{"newer", "panderer", "scooper"});
    REQUIRE_EQ(addEnding({"bend", "sharpen", "mean"}, "ing"),
               std::vector<std::string>{"bending", "sharpening", "meaning"});
    REQUIRE_EQ(addEnding({"bend", "tooth", "mint"}, "y"),
               std::vector<std::string>{"bendy", "toothy", "minty"});
    REQUIRE_EQ(addEnding({"bend", "tooth", "mint"}, "ier"),
               std::vector<std::string>{"bendier", "toothier", "mintier"});
}

// 5. Difference of Max and Min Numbers in Array
TEST_CASE("week01::Testing differenceMaxMin") {
    REQUIRE_EQ(differenceMaxMin({10, 4, 1, 2, 8, 91}), 90);
    REQUIRE_EQ(differenceMaxMin({-70, 43, 34, 54, 22}), 124);
    REQUIRE_EQ(differenceMaxMin({1}), 0);
}
