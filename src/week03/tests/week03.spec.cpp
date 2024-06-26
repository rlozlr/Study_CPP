#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <src/week03/week03.hpp>

TEST_CASE("identicalFilter") {
    REQUIRE_EQ(identicalFilter({"aaaaaa", "bc", "d", "eeee", "xyz"}),
               std::vector<std::string>({"aaaaaa", "d", "eeee"}));
    REQUIRE_EQ(identicalFilter({"88", "999", "22", "545", "133"}),
               std::vector<std::string>({"88", "999", "22"}));
    REQUIRE_EQ(identicalFilter({"xxxxo", "oxo", "xox", "ooxxoo", "oxo"}),
               std::vector<std::string>({}));
    REQUIRE_EQ(identicalFilter({"1", "2", "3"}), std::vector<std::string>({"1", "2", "3"}));
}

TEST_CASE("shiftL") {
    REQUIRE_EQ(shiftL({1, 2, 3, 4}, 1), std::vector<int>({2, 3, 4, 1}));
    REQUIRE_EQ(shiftL({1, 2, 3, 4, 5}, 3), std::vector<int>({4, 5, 1, 2, 3}));
    REQUIRE_EQ(shiftL({1, 2, 3, 4, 5}, 5), std::vector<int>({1, 2, 3, 4, 5}));
    REQUIRE_EQ(shiftL({1, 2, 3, 4, 5}, 6), std::vector<int>({2, 3, 4, 5, 1}));
    REQUIRE_EQ(shiftL({1, 2, 3, 4, 5}, 1), std::vector<int>({2, 3, 4, 5, 1}));
    REQUIRE_EQ(shiftL({1, 2, 3, 4, 5}, 4), std::vector<int>({5, 1, 2, 3, 4}));
}

TEST_CASE("shiftR") {
    REQUIRE_EQ(shiftR({1, 2, 3, 4, 5}, 1), std::vector<int>({5, 1, 2, 3, 4}));
    REQUIRE_EQ(shiftR({1, 2, 3, 4, 5}, 3), std::vector<int>({3, 4, 5, 1, 2}));
    REQUIRE_EQ(shiftR({1, 2, 3, 4, 5}, 0), std::vector<int>({1, 2, 3, 4, 5}));
    REQUIRE_EQ(shiftR({1, 2, 3, 4, 5}, 15), std::vector<int>({1, 2, 3, 4, 5}));
    REQUIRE_EQ(shiftR({1, 2, 3, 4}, 1), std::vector<int>({4, 1, 2, 3}));
}

TEST_CASE("setFrom") {
    REQUIRE_EQ(setFrom({1, 3, 3, 5, 5}), std::vector<int>({1, 3, 5}));
    REQUIRE_EQ(setFrom({4, 4, 4, 4, 4}), std::vector<int>({4}));
    REQUIRE_EQ(setFrom({5, 7, 8, 9, 10, 15}), std::vector<int>({5, 7, 8, 9, 10, 15}));
    REQUIRE_EQ(setFrom({5, 9, 9}), std::vector<int>({5, 9}));
    REQUIRE_EQ(setFrom({1, 2, 3, 4, 5, 5, 6}), std::vector<int>({1, 2, 3, 4, 5, 6}));
    REQUIRE_EQ(setFrom({1, 1, 2, 2, 2}), std::vector<int>({1, 2}));
}

TEST_CASE("firstAndLast") {
    REQUIRE_EQ(firstAndLast("marmite"), std::vector<std::string>({"aeimmrt", "trmmiea"}));
    REQUIRE_EQ(firstAndLast("bench"), std::vector<std::string>({"bcehn", "nhecb"}));
    REQUIRE_EQ(firstAndLast("scoop"), std::vector<std::string>({"coops", "spooc"}));
    REQUIRE_EQ(firstAndLast("fanatic"), std::vector<std::string>({"aacfint", "tnifcaa"}));
}

TEST_CASE("convertCartesian") {
    REQUIRE_EQ(convertCartesian({1, 1}, {1, 1}), std::vector<std::vector<int>>({{1, 1}, {1, 1}}));
    REQUIRE_EQ(convertCartesian({9, 8, 3}, {1, 1, 1}),
               std::vector<std::vector<int>>({{9, 1}, {8, 1}, {3, 1}}));
    REQUIRE_EQ(convertCartesian({2, 5, 1}, {7, 8, 9}),
               std::vector<std::vector<int>>({{2, 7}, {5, 8}, {1, 9}}));
    REQUIRE_EQ(convertCartesian({3, 2, 2}, {6, 1, 7}),
               std::vector<std::vector<int>>({{3, 6}, {2, 1}, {2, 7}}));
    REQUIRE_EQ(convertCartesian({3, 2, 2, 0}, {6, 1, 7, 1}),
               std::vector<std::vector<int>>({{3, 6}, {2, 1}, {2, 7}, {0, 1}}));
}

TEST_CASE("sortByLenth") {
    REQUIRE_EQ(sortByLength({"a", "ccc", "dddd", "bb"}),
               std::vector<std::string>({"a", "bb", "ccc", "dddd"}));
    REQUIRE_EQ(sortByLength({"apple", "pie", "shortcake"}),
               std::vector<std::string>({"pie", "apple", "shortcake"}));
    REQUIRE_EQ(sortByLength({"may", "april", "september", "august"}),
               std::vector<std::string>({"may", "april", "august", "september"}));
    REQUIRE_EQ(sortByLength({"maybe"}), std::vector<std::string>({"maybe"}));
    REQUIRE_EQ(sortByLength({}), std::vector<std::string>({}));
}

TEST_CASE("countAdverbs") {
    SUBCASE("Basic") {
        REQUIRE_EQ(countAdverbs("She ran hurriedly towards the stadium."), 1);
        REQUIRE_EQ(countAdverbs("She ate the lasagna heartily and noisily."), 2);
        REQUIRE_EQ(countAdverbs("He hates potatoes."), 0);
        REQUIRE_EQ(countAdverbs("He was happily, crazily, foolishly over the "
                                "moon."),
                   3);
        REQUIRE_EQ(countAdverbs("She writes poetry beautifully."), 1);
        REQUIRE_EQ(countAdverbs("There are many fat geese in the park."), 0);
        REQUIRE_EQ(countAdverbs("The horse acted aggressively and stubbornly."), 2);
    }

    SUBCASE("Only count ly as word endings") {
        REQUIRE_EQ(countAdverbs("She forgot where to buy the lysol."), 0);
        REQUIRE_EQ(countAdverbs("Ilya ran to the store."), 0);
    }
}

TEST_CASE("societyName") {
    REQUIRE_EQ(societyName({"Adam", "Sarah", "Malcolm"}), "AMS");
    REQUIRE_EQ(societyName({"Phoebe", "Chandler", "Ross", "Rachel", "Monica", "Joey"}), "CJMPRR");
    REQUIRE_EQ(societyName({"Harry", "Newt", "Luna", "Cho"}), "CHLN");
    REQUIRE_EQ(societyName({"Sherlock", "Irene", "John"}), "IJS");
    REQUIRE_EQ(societyName({"Sheldon", "Amy", "Penny", "Howard", "Raj"}), "AHPRS");
}

TEST_CASE("isPalindrome") {
    REQUIRE_EQ(isPalindrome("A man, a plan, a cat, a ham, a yak, a yam, a hat, "
                            "a canal-Panama!"),
               true);
    REQUIRE_EQ(isPalindrome("Neuquen"), true);
    REQUIRE_EQ(isPalindrome("Not a palindrome"), false);
}

TEST_CASE("countUnique") {
    REQUIRE_EQ(countUnique("apple", "play"), 5);
    REQUIRE_EQ(countUnique("sore", "zebra"), 7);
    REQUIRE_EQ(countUnique("pip", "geeks"), 6);
    REQUIRE_EQ(countUnique("a", "soup"), 5);
    REQUIRE_EQ(countUnique("maniac", "maniac"), 5);
}

TEST_CASE("isValidPhoneNumber") {
    REQUIRE(isValidPhoneNumber("(123) 456-7890"));
    REQUIRE_FALSE(isValidPhoneNumber("(1111)555 2345"));
    REQUIRE_FALSE(isValidPhoneNumber("(098) 123 4567"));
    REQUIRE_FALSE(isValidPhoneNumber("(123)456-7890"));
    REQUIRE_FALSE(isValidPhoneNumber("abc(123)456-7890"));
    REQUIRE_FALSE(isValidPhoneNumber("(123)456-7890abc"));
    REQUIRE_FALSE(isValidPhoneNumber("abc(123)456-7890abc"));
    REQUIRE_FALSE(isValidPhoneNumber("abc(123) 456-7890"));
    REQUIRE_FALSE(isValidPhoneNumber("(123) 456-7890abc"));
    REQUIRE_FALSE(isValidPhoneNumber("abc(123) 456-7890abc"));
    REQUIRE_FALSE(isValidPhoneNumber("(123)-456-7890"));
    REQUIRE_FALSE(isValidPhoneNumber("(123)_456-7890"));
    REQUIRE_FALSE(isValidPhoneNumber("-123) 456-7890"));
    REQUIRE(isValidPhoneNumber("(519) 505-6498"));
}

TEST_CASE("tree") {
    REQUIRE_EQ(tree(1), std::vector<std::string>({"#"}));
    REQUIRE_EQ(tree(2), std::vector<std::string>({" # ", "###"}));
    REQUIRE_EQ(tree(5), std::vector<std::string>(
                            {"    #    ", "   ###   ", "  #####  ", " ####### ", "#########"}));
    REQUIRE_EQ(tree(0), std::vector<std::string>({}));
}

TEST_CASE("accum") {
    REQUIRE_EQ(accum("abcd"), "A-Bb-Ccc-Dddd");
    REQUIRE_EQ(accum("RqaEzty"), "R-Qq-Aaa-Eeee-Zzzzz-Tttttt-Yyyyyyy");
    REQUIRE_EQ(accum("cwAt"), "C-Ww-Aaa-Tttt");
    REQUIRE_EQ(accum("VgyCdnQa"), "V-Gg-Yyy-Cccc-Ddddd-Nnnnnn-Qqqqqqq-Aaaaaaaa");
    REQUIRE_EQ(accum("nRBSdNOsMl"),
               "N-Rr-Bbb-Ssss-Ddddd-Nnnnnn-Ooooooo-Ssssssss-"
               "Mmmmmmmmm-Llllllllll");
    REQUIRE_EQ(accum("nuE"), "N-Uu-Eee");
    REQUIRE_EQ(accum("RlDrhZuQaqsoHEfziByObtMxkFCJVe"),
               "R-Ll-Ddd-Rrrr-Hhhhh-Zzzzzz-Uuuuuuu-Qqqqqqqq-Aaaaaaaaa-"
               "Qqqqqqqqqq-"
               "Sssssssssss-Oooooooooooo-Hhhhhhhhhhhhh-Eeeeeeeeeeeeee-"
               "Fffffffffffffff-Zzzzzzzzzzzzzzzz-Iiiiiiiiiiiiiiiii-"
               "Bbbbbbbbbbbbbbbbbb-Yyyyyyyyyyyyyyyyyyy-Oooooooooooooooooooo-"
               "Bbbbbbbbbbbbbbbbbbbbb-Tttttttttttttttttttttt-"
               "Mmmmmmmmmmmmmmmmmmmmmmm-Xxxxxxxxxxxxxxxxxxxxxxxx-"
               "Kkkkkkkkkkkkkkkkkkkkkkkkk-Ffffffffffffffffffffffffff-"
               "Ccccccccccccccccccccccccccc-Jjjjjjjjjjjjjjjjjjjjjjjjjjjj-"
               "Vvvvvvvvvvvvvvvvvvvvvvvvvvvvv-Eeeeeeeeeeeeeeeeeeeeeeeeeeeeee");
    REQUIRE_EQ(accum("EXpzPFx"), "E-Xx-Ppp-Zzzz-Ppppp-Ffffff-Xxxxxxx");
    REQUIRE_EQ(accum("NU"), "N-Uu");
    REQUIRE_EQ(accum("g"), "G");
}

TEST_CASE("unique") {
    REQUIRE_EQ(unique({3, 3, 3, 7, 3, 3}), 7);
    REQUIRE_EQ(unique({0, 0, 0.77, 0, 0}), 0.77);
    REQUIRE_EQ(unique({0, 1, 1, 1, 1, 1, 1, 1}), 0);
    REQUIRE_EQ(unique({-4, -4, -4, 4}), 4);
    REQUIRE_EQ(unique({8, 8, 8, 8, 8, 8, 8, 0.5}), 0.5);
    REQUIRE_EQ(unique({2, 1, 2, 2, 2, 2, 2, 2}), 1);
}

TEST_CASE("isAnagram") {
    REQUIRE_EQ(isAnagram("cristian", "Cristina"), true);
    REQUIRE_EQ(isAnagram("Dave Barry", "Ray Adverb"), true);
    REQUIRE_EQ(isAnagram("Nope", "Note"), false);
    REQUIRE_EQ(isAnagram("Apple", "Appeal"), false);
}