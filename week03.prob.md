---
marp: true
theme: gaia
class:
  - invert
paginate: true
---

### Problems

```c++
// 21. Create a function that keeps only strings with repeating identical
// characters (in other words, it has a set size of 1).
// A string with a single character is trivially counted as a string with
// repeating identical characters. If there is no string with repeating
// identical characters, return an empty array(see case #3).
auto identicalFilter(std::vector<std::string> const & arr)
    -> std::vector<std::string>;

REQUIRE_EQ(identicalFilter({"aaaaaa", "bc", "d", "eeee", "xyz"}),
            std::vector<std::string>({"aaaaaa", "d", "eeee"}));
REQUIRE_EQ(identicalFilter({"88", "999", "22", "545", "133"}),
            std::vector<std::string>({"88", "999", "22"}));
REQUIRE_EQ(identicalFilter({"xxxxo", "oxo", "xox", "ooxxoo", "oxo"}),
            std::vector<std::string>({}));
REQUIRE_EQ(identicalFilter({"1", "2", "3"}),
            std::vector<std::string>({"1", "2", "3"}));
```

---

### Problems

```c++
// 22. Create two functions: a left-shift function and a right-shift function.
// Each function will take in an array and a single parameter: the number of
// shifts.
auto shiftL(std::vector<int> const & arr, int num) -> std::vector<int>;
auto shiftR(std::vector<int> const & arr, int num) -> std::vector<int>;

REQUIRE_EQ(shiftL({1, 2, 3, 4}, 1), std::vector<int>({2, 3, 4, 1}));
REQUIRE_EQ(shiftL({1, 2, 3, 4, 5}, 3), std::vector<int>({4, 5, 1, 2, 3}));
REQUIRE_EQ(shiftL({1, 2, 3, 4, 5}, 5), std::vector<int>({1, 2, 3, 4, 5}));
REQUIRE_EQ(shiftL({1, 2, 3, 4, 5}, 6), std::vector<int>({2, 3, 4, 5, 1}));
REQUIRE_EQ(shiftL({1, 2, 3, 4, 5}, 1), std::vector<int>({2, 3, 4, 5, 1}));
REQUIRE_EQ(shiftL({1, 2, 3, 4, 5}, 4), std::vector<int>({5, 1, 2, 3, 4}));
REQUIRE_EQ(shiftR({1, 2, 3, 4, 5}, 1), std::vector<int>({5, 1, 2, 3, 4}));
REQUIRE_EQ(shiftR({1, 2, 3, 4, 5}, 3), std::vector<int>({3, 4, 5, 1, 2}));
REQUIRE_EQ(shiftR({1, 2, 3, 4, 5}, 0), std::vector<int>({1, 2, 3, 4, 5}));
REQUIRE_EQ(shiftR({1, 2, 3, 4, 5}, 15), std::vector<int>({1, 2, 3, 4, 5}));
REQUIRE_EQ(shiftR({1, 2, 3, 4}, 1), std::vector<int>({4, 1, 2, 3}));
```

---

### Problems

```c++
// 23. A set is a collection of unique items. A set can be formed from an array
// from removing all duplicate items. Create a function that returns unique
// elements from an array of integers.
auto setFrom(std::vector<int> const & arr) -> std::vector<int>;

REQUIRE_EQ(setFrom({1, 3, 3, 5, 5}), std::vector<int>({1, 3, 5}));
REQUIRE_EQ(setFrom({4, 4, 4, 4, 4}), std::vector<int>({4}));
REQUIRE_EQ(setFrom({5, 7, 8, 9, 10, 15}),
            std::vector<int>({5, 7, 8, 9, 10, 15}));
REQUIRE_EQ(setFrom({5, 9, 9}), std::vector<int>({5, 9}));
REQUIRE_EQ(setFrom({1, 2, 3, 4, 5, 5, 6}),
            std::vector<int>({1, 2, 3, 4, 5, 6}));
REQUIRE_EQ(setFrom({1, 1, 2, 2, 2}), std::vector<int>({1, 2}));
```

---

### Problems

```c++
// 24. Write a function that returns the lexicographically first and
// lexicographically last rearrangements of a string.
auto firstAndLast(std::string const & s) -> std::vector<std::string>;

REQUIRE_EQ(firstAndLast("marmite"),
            std::vector<std::string>({"aeimmrt", "trmmiea"}));
REQUIRE_EQ(firstAndLast("bench"),
            std::vector<std::string>({"bcehn", "nhecb"}));
REQUIRE_EQ(firstAndLast("scoop"),
            std::vector<std::string>({"coops", "spooc"}));
REQUIRE_EQ(firstAndLast("fanatic"),
            std::vector<std::string>({"aacfint", "tnifcaa"}));
```

---

### Problems

```c++
// 25. Create a function that converts two arrays of x- and y- coordinates
// into an array of (x,y) coordinates.
auto convertCartesian(std::vector<int> const & x, std::vector<int> const & y)
    -> std::vector<std::vector<int>>;

REQUIRE_EQ(convertCartesian({1, 1}, {1, 1}),
            std::vector<std::vector<int>>({{1, 1}, {1, 1}}));
REQUIRE_EQ(convertCartesian({9, 8, 3}, {1, 1, 1}),
            std::vector<std::vector<int>>({{9, 1}, {8, 1}, {3, 1}}));
REQUIRE_EQ(convertCartesian({2, 5, 1}, {7, 8, 9}),
            std::vector<std::vector<int>>({{2, 7}, {5, 8}, {1, 9}}));
REQUIRE_EQ(convertCartesian({3, 2, 2}, {6, 1, 7}),
            std::vector<std::vector<int>>({{3, 6}, {2, 1}, {2, 7}}));
REQUIRE_EQ(convertCartesian({3, 2, 2, 0}, {6, 1, 7, 1}),
            std::vector<std::vector<int>>({{3, 6}, {2, 1}, {2, 7}, {0, 1}}));
```

---

### Problems

```c++
// 26. Create a function that returns an array of strings sorted by length in
// ascending order.
auto sortByLength(std::vector<std::string> const & arr)
    -> std::vector<std::string>;

REQUIRE_EQ(sortByLength({"a", "ccc", "dddd", "bb"}),
            std::vector<std::string>({"a", "bb", "ccc", "dddd"}));
REQUIRE_EQ(sortByLength({"apple", "pie", "shortcake"}),
            std::vector<std::string>({"pie", "apple", "shortcake"}));
REQUIRE_EQ(sortByLength({"may", "april", "september", "august"}),
            std::vector<std::string>(
                {"may", "april", "august", "september"}));
REQUIRE_EQ(sortByLength({"maybe"}), std::vector<std::string>({"maybe"}));
REQUIRE_EQ(sortByLength({}), std::vector<std::string>({}));
```

---

### Problems

```c++
// 27. Create a function that counts the number of adverbs in a sentence:
// * An adverb is a word that ends with 'ly'.
// * Do NOT count words where the 'ly' is in the beginning or the middle
//   (e.g. Lysol, Illya).
// * For the purpose of this exercise, ignore the nuances of the English
//   language (some adjectives also end in 'ly').
auto countAdverbs(std::string const & s) -> int;

SUBCASE("Basic")
{
    REQUIRE_EQ(countAdverbs("She ran hurriedly towards the stadium."), 1);
    REQUIRE_EQ(countAdverbs("She ate the lasagna heartily and noisily."),
                2);
    REQUIRE_EQ(countAdverbs("He hates potatoes."), 0);
    REQUIRE_EQ(countAdverbs("He was happily, crazily, foolishly over the "
                            "moon."),
                3);
    REQUIRE_EQ(countAdverbs("She writes poetry beautifully."), 1);
    REQUIRE_EQ(countAdverbs("There are many fat geese in the park."), 0);
    REQUIRE_EQ(countAdverbs("The horse acted aggressively and stubbornly."),
                2);
}

SUBCASE("Only count ly as word endings")
{
    REQUIRE_EQ(countAdverbs("She forgot where to buy the lysol."), 0);
    REQUIRE_EQ(countAdverbs("Ilya ran to the store."), 0);
}
```

---

### Problems

```c++
// 28. A group of friends have decided to start a secret society. The name will
// be the first letter of each of their names, sorted in alphabetical order.
// Create a function that takes in an array of names and returns the name of the
//  secret society. The secret society's name should be entirely uppercased.
auto societyName(std::vector<std::string> const & friends) -> std::string;

REQUIRE_EQ(societyName({"Adam", "Sarah", "Malcolm"}), "AMS");
REQUIRE_EQ(societyName(
                {"Phoebe", "Chandler", "Ross", "Rachel", "Monica", "Joey"}),
            "CJMPRR");
REQUIRE_EQ(societyName({"Harry", "Newt", "Luna", "Cho"}), "CHLN");
REQUIRE_EQ(societyName({"Sherlock", "Irene", "John"}), "IJS");
REQUIRE_EQ(societyName({"Sheldon", "Amy", "Penny", "Howard", "Raj"}),
            "AHPRS");
```

---

### Problems

```c++
// 29. A palindrome is a word, phrase, number or other sequence of characters
// which reads the same backward or forward, such as madam or kayak.
// Write a function that takes a string and determines whether it's a palindrome
// or not:
// * Should be case insensitive.
// * Special characters (punctuation or spaces) should be ignored.
auto isPalindrome(std::string const & str) -> bool;

REQUIRE_EQ(isPalindrome("A man, a plan, a cat, a ham, a yak, a yam, a hat, "
                        "a canal-Panama!"),
            true);
REQUIRE_EQ(isPalindrome("Neuquen"), true);
REQUIRE_EQ(isPalindrome("Not a palindrome"), false);
```

---

### Problems

```c++
// 30. Given two strings, create a function that returns the total number of
// unique characters from the combined string. Each word will contain at least
// one letter. All words will be lower cased.
auto countUnique(std::string const & str1, std::string const & str2) -> int;

REQUIRE_EQ(countUnique("apple", "play"), 5);
REQUIRE_EQ(countUnique("sore", "zebra"), 7);
REQUIRE_EQ(countUnique("pip", "geeks"), 6);
REQUIRE_EQ(countUnique("a", "soup"), 5);
REQUIRE_EQ(countUnique("maniac", "maniac"), 5);
```

---

### Problems

```c++
// 31. Create a function that accepts a string and returns true if it's in the
// format of a proper phone number and false if it's not. Assume any number
// between from 0-9 (in the appropriate spots) will produce a valid phone
// number. This is what a valid phone number looks like: (123) 456-7890
auto isValidPhoneNumber(std::string const & str) -> bool;

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
```

---

### Problems

```c++
// 32. Write a function to create a Christmas tree based on height `h`.
auto tree(int h) -> std::vector<std::string>;

REQUIRE_EQ(tree(1), std::vector<std::string>({"#"}));
REQUIRE_EQ(tree(2), std::vector<std::string>({" # ",
                                              "###"}));
REQUIRE_EQ(tree(5), std::vector<std::string>({"    #    ",
                                              "   ###   ",
                                              "  #####  ",
                                              " ####### ",
                                              "#########"}));
REQUIRE_EQ(tree(0), std::vector<std::string>({}));
```

---

### Problems

```c++
// 33. Create a function that takes a string and returns a new string with each
// new character accumulating by +1. Separate each set with a dash./ Capitalize
// the first letter of each set. All tests contain valid strings with alphabetic
// characters (a-z, A-Z).
auto accum(std::string const & s) -> std::string;

REQUIRE_EQ(accum("abcd"), "A-Bb-Ccc-Dddd");
REQUIRE_EQ(accum("RqaEzty"), "R-Qq-Aaa-Eeee-Zzzzz-Tttttt-Yyyyyyy");
REQUIRE_EQ(accum("cwAt"), "C-Ww-Aaa-Tttt");
REQUIRE_EQ(accum("VgyCdnQa"),
            "V-Gg-Yyy-Cccc-Ddddd-Nnnnnn-Qqqqqqq-Aaaaaaaa");
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
```

---

### Problems

```c++
// 34. Create a function that takes an array of numbers and return the number
// that's unique. Test cases will always have exactly one unique number while
// all others are the same.
auto unique(std::vector<double> const & arr) -> double;

REQUIRE_EQ(unique({3, 3, 3, 7, 3, 3}), 7);
REQUIRE_EQ(unique({0, 0, 0.77, 0, 0}), 0.77);
REQUIRE_EQ(unique({0, 1, 1, 1, 1, 1, 1, 1}), 0);
REQUIRE_EQ(unique({-4, -4, -4, 4}), 4);
REQUIRE_EQ(unique({8, 8, 8, 8, 8, 8, 8, 0.5}), 0.5);
REQUIRE_EQ(unique({2, 1, 2, 2, 2, 2, 2, 2}), 1);
```

---

### Problems

```c++
// 35. Create a function that takes two strings and returns (true or false)
// whether they're anagrams or not. Should be case insensitive.
auto isAnagram(std::string const & s1, std::string const & s2) -> bool;

REQUIRE_EQ(isAnagram("cristian", "Cristina"), true);
REQUIRE_EQ(isAnagram("Dave Barry", "Ray Adverb"), true);
REQUIRE_EQ(isAnagram("Nope", "Note"), false);
REQUIRE_EQ(isAnagram("Apple", "Appeal"), false);
```