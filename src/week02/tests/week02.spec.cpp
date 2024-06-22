#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <src/week02/week02.hpp>

// 6. Find the Index
// Create a function that takes a vector of strings and a string as arguments
// and returns the index of the string.
TEST_CASE("findIndex") {
    REQUIRE(findIndex({"abc", "ghj", "banana", "grape"}, "grape") == 3);
    REQUIRE(findIndex({"a", "b", "c", "d", "e", "f"}, "f") == 5);
    REQUIRE(findIndex({"hi", "edabit.com", "testcase", "validstring"}, "edabit.com") == 1);
}
// 7. Product Divisible By Sum?
// Write a function that, given a vector of integers, returns true if the
// product of the vector is divisible by the sum of that same vector.
TEST_CASE("divisible") {
    REQUIRE(divisible({4, 4, 4, 4}));
    REQUIRE(divisible({4, 2, 6}));
    REQUIRE(divisible({10, 5, 10}));
    REQUIRE_FALSE(divisible({3, 2, 4, 1}));
    REQUIRE_FALSE(divisible({1, 1, 1, 1, 10}));
    REQUIRE_FALSE(divisible({3, 5, 1}));
}

// 8. Factor Chain
// A factor chain is a vector of integers where each previous element is a
// factor of the next consecutive element. The following is a factor chain:
//
// [3,6,12,36]
// : 3 is a factor of 6
// 6 is a factor of 12
// 12 is a factor of 36
//
// Create a function that checks whether or not a vector is a factor chain.
TEST_CASE("factorChain") {
    REQUIRE(factorChain({1, 2, 4, 8, 16, 32}));
    REQUIRE(factorChain({1, 1, 1, 1, 1, 1}));
    REQUIRE(factorChain({10, 20, 40}));
    REQUIRE(factorChain({1, 1, 1, 1, 7, 49}));
    REQUIRE_FALSE(factorChain({2, 4, 6, 7, 12}));
    REQUIRE_FALSE(factorChain({10, 1}));
    REQUIRE_FALSE(factorChain({10, 20, 30, 40}));
}

// 9. Concatenating two integer vectors
// Create a function to concatenate two vectors of integers.
TEST_CASE("concat") {
    REQUIRE(concat({7, 8}, {10, 9, 1, 1, 2}) == std::vector<int>({7, 8, 10, 9, 1, 1, 2}));
    REQUIRE(concat({4, 5, 1}, {3, 3, 3, 3, 3}) == std::vector<int>({4, 5, 1, 3, 3, 3, 3, 3}));
}

// 10. Check if a String Contains only Identical Characters
// Write a function that returns true if all characters in a string are
// identical and false otherwise.
TEST_CASE("isIdentical") {
    REQUIRE(isIdentical("kkkkk"));
    REQUIRE(isIdentical("ccc"));
    REQUIRE(isIdentical("bbbbbb"));
    REQUIRE_FALSE(isIdentical("ckkkk"));
    REQUIRE_FALSE(isIdentical("kkkkck"));
    REQUIRE_FALSE(isIdentical("aabc"));
    REQUIRE_FALSE(isIdentical("aabbbb"));
}

// 11. Hamming Distance
// Hamming Distance is the number of characters that differ between two
// strings:
//
// "abcbba"
// "abcbda"
// ^
// -> Hamming Distance is 1 because 'b' vs 'd' is the only difference.
//
// Create a function that computes the hamming distance between two strings.
TEST_CASE("hammingDistance") {
    REQUIRE(hammingDistance("abcde", "bcdef") == 5);
    REQUIRE(hammingDistance("abcde", "abcde") == 0);
    REQUIRE(hammingDistance("strong", "strung") == 1);
}

// 12. Count Instances of a Characters in a String
// Create a function that takes two strings as arguments and returns the
// number of times the first string is found in the second string.
// Your output must be case-sensitive (see assertion #4).
TEST_CASE("charCount") {
    REQUIRE(charCount('a', "edabit") == 1);
    REQUIRE(charCount('b', "big fat bubble") == 4);
    REQUIRE(charCount('f',
                      "frank and his friends have offered five foxes for "
                      "sale")
            == 7);
    REQUIRE(charCount('c', "Chamber of secrets") == 1);
    REQUIRE(charCount('a', "Adam and Eve bit the apple and found a snake") == 6);
    REQUIRE(charCount('7', "10795426697") == 2);
    REQUIRE(charCount('s', "sssssssssssssssssssssssss") == 25);
    REQUIRE(charCount('x', "edabit") == 0);
}

// 13. Mean of All Digits
// Create a function that returns the mean of all digits.
// The mean will always be a integer.
TEST_CASE("mean") {
    REQUIRE(mean(666) == 6);
    REQUIRE(mean(80) == 4);
    REQUIRE(mean(-13) == 2);
}

// 14. Double Letters
// Create a function that takes a word and returns true if the word has
// two consecutive identical letters.
TEST_CASE("doubleLetters") {
    REQUIRE(doubleLetters("loop"));
    REQUIRE(doubleLetters("meeting"));
    REQUIRE(doubleLetters("yummy"));
    REQUIRE(doubleLetters("moo"));
    REQUIRE(doubleLetters("toodles"));
    REQUIRE(doubleLetters("droop"));
    REQUIRE(doubleLetters("loot"));
    REQUIRE_FALSE(doubleLetters("munchkin"));
    REQUIRE_FALSE(doubleLetters("forestry"));
    REQUIRE_FALSE(doubleLetters("raindrops"));
    REQUIRE_FALSE(doubleLetters("gold"));
    REQUIRE_FALSE(doubleLetters("paradise"));
}

// 15. Minimum Removals to Make Sum Even
// Create a function that returns the minimum number of removals to make
// the sum of all elements in a vector even.
// If the sum is already even, return 0 (see assertion #2, #6 and #8).
TEST_CASE("minimumRemovals") {
    REQUIRE(minimumRemovals({1, 2, 3, 4, 5}) == 1);
    REQUIRE(minimumRemovals({1, 2, 3, 4}) == 0);
    REQUIRE(minimumRemovals({5, 8, 8, 8}) == 1);
    REQUIRE(minimumRemovals({1, 8, 8, 8, 9, 9}) == 1);
    REQUIRE(minimumRemovals({2, 1, 8, 8, 8, 9, 9}) == 2);
    REQUIRE(minimumRemovals({8, 8, 9, 9}) == 0);
    REQUIRE(minimumRemovals({2, 1, 8, 8, 9, 9}) == 2);
    REQUIRE(minimumRemovals({9, 9, 8}) == 0);
    REQUIRE(minimumRemovals({7, 2}) == 1);
}

// 16. Snail Race
// Steve and Maurice are racing snails.
// They each have 3, a slow (s), medium (m) and fast (f) one.
// Although Steve's snails are all a bit stronger than Maurice's,
// Maurice has a trick up his sleeve. His plan is (written [Maurice, Steve]):
//
// Round 1: [s, f] Sacrifice his slowest snail against Steve's fastest.
// Round 2: [m, s] Use his middle snail against Steve's slowest.
// Round 3: [f, m] Use his fastest snail against Steve's middle.
//
// Create a function that determines whether Maurice's plan will work by
// outputting true if Maurice wins 2/3 games.
//
// The function inputs:
//
// Array 1: [s, m, f] for Maurice.
// Array 2: [s, m, f] for Steve.
//
// Maurice wins if his competing snail's speed strictly exceeds
// Steve's competing snail's speed.
// Steve will always play in this order: [f, s, m].
TEST_CASE("mauriceWins") {
    REQUIRE(mauriceWins({3, 5, 10}, {4, 7, 11}));
    REQUIRE(mauriceWins({1, 8, 20}, {2, 9, 100}));
    REQUIRE(mauriceWins({2, 4, 10}, {3, 9, 11}));
    REQUIRE(mauriceWins({3, 8, 13}, {5, 11, 15}));
    REQUIRE_FALSE(mauriceWins({6, 8, 9}, {7, 12, 14}));
    REQUIRE_FALSE(mauriceWins({1, 2, 3}, {2, 3, 4}));
}
// 17. Index Shuffle
// Create a function that takes all even-indexed characters and odd-indexed
// characters from a string and concatenates them together.
TEST_CASE("indexShuffle") {
    REQUIRE(indexShuffle("abcdef") == "acebdf");
    REQUIRE(indexShuffle("abababab") == "aaaabbbb");
    REQUIRE(indexShuffle("it was a beautiful day") == "i a  euiu atwsabatfldy");
    REQUIRE(indexShuffle("maybe") == "myeab");
    REQUIRE(indexShuffle("holiday") == "hldyoia");
}
// 18. Spelling it Out
// Create a function which takes in a word and spells it out,
// by consecutively adding letters until the full word is completed.
TEST_CASE("spelling") {
    REQUIRE(spelling("bee") == std::vector<std::string>({"b", "be", "bee"}));
    REQUIRE(spelling("cake") == std::vector<std::string>({"c", "ca", "cak", "cake"}));
    REQUIRE(spelling("happy") == std::vector<std::string>({"h", "ha", "hap", "happ", "happy"}));
    REQUIRE(spelling("eagerly")
            == std::vector<std::string>({"e", "ea", "eag", "eage", "eager", "eagerl", "eagerly"}));
    REQUIRE(spelling("believe")
            == std::vector<std::string>({"b", "be", "bel", "beli", "belie", "believ", "believe"}));
}
// 19. Factorize a Number
// Create a function that takes a number as its argument and returns a
// vector of all its factors.
// The input integer will be positive.
// A factor is a number that evenly divides into another number without
// leaving a remainder.
TEST_CASE("factorize") {
    REQUIRE(factorize(12) == std::vector<int>({1, 2, 3, 4, 6, 12}));
    REQUIRE(factorize(4) == std::vector<int>({1, 2, 4}));
    REQUIRE(factorize(17) == std::vector<int>({1, 17}));
    REQUIRE(factorize(24) == std::vector<int>({1, 2, 3, 4, 6, 8, 12, 24}));
    REQUIRE(factorize(1) == std::vector<int>({1}));
}
// 20. Find the Missing Number
// Create a function that takes a vector of integers between 1 and 10
// (excluding one number) and returns the missing number.
// The vector of numbers will be unsorted (not in order).
// Only one number will be missing.
TEST_CASE("missingNum") {
    REQUIRE(missingNum({1, 2, 3, 4, 6, 7, 8, 9, 10}) == 5);
    REQUIRE(missingNum({7, 2, 3, 6, 5, 9, 1, 4, 8}) == 10);
    REQUIRE(missingNum({7, 2, 3, 9, 4, 5, 6, 8, 10}) == 1);
    REQUIRE(missingNum({10, 5, 1, 2, 4, 6, 8, 3, 9}) == 7);
    REQUIRE(missingNum({1, 7, 2, 4, 8, 10, 5, 6, 9}) == 3);
}