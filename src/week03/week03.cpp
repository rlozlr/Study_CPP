#include "week03.hpp"

#include <algorithm>

namespace week03 {

    // 21. Create a function that keeps only strings with repeating identical
    // characters (in other words, it has a set size of 1).
    // A string with a single character is trivially counted as a string with
    // repeating identical characters. If there is no string with repeating
    // identical characters, return an empty array(see case #3).
    auto identicalFilter(std::vector<std::string> const& arr) -> std::vector<std::string>;

    // 22. Create two functions: a left-shift function and a right-shift function.
    // Each function will take in an array and a single parameter: the number of
    // shifts.
    auto shiftL(std::vector<int> const& arr, int num) -> std::vector<int>;

    auto shiftR(std::vector<int> const& arr, int num) -> std::vector<int>;

    // 23. A set is a collection of unique items. A set can be formed from an array
    // from removing all duplicate items. Create a function that returns unique
    // elements from an array of integers.
    auto setFrom(std::vector<int> const& arr) -> std::vector<int>;

    // 24. Write a function that returns the lexicographically first and
    // lexicographically last rearrangements of a string.
    auto firstAndLast(std::string const& s) -> std::vector<std::string>;

    // 25. Create a function that converts two arrays of x- and y- coordinates
    // into an array of (x,y) coordinates.
    auto convertCartesian(std::vector<int> const& x,
                          std::vector<int> const& y) -> std::vector<std::vector<int>>;

    // 26. Create a function that returns an array of strings sorted by length in
    // ascending order.
    auto sortByLength(std::vector<std::string> const& arr) -> std::vector<std::string>;

    // 27. Create a function that counts the number of adverbs in a sentence:
    // * An adverb is a word that ends with 'ly'.
    // * Do NOT count words where the 'ly' is in the beginning or the middle
    //   (e.g. Lysol, Illya).
    // * For the purpose of this exercise, ignore the nuances of the English
    //   language (some adjectives also end in 'ly').
    auto countAdverbs(std::string const& s) -> int;

    // 28. A group of friends have decided to start a secret society. The name will
    // be the first letter of each of their names, sorted in alphabetical order.
    // Create a function that takes in an array of names and returns the name of the
    //  secret society. The secret society's name should be entirely uppercased.
    auto societyName(std::vector<std::string> const& friends) -> std::string;

    // 29. A palindrome is a word, phrase, number or other sequence of characters
    // which reads the same backward or forward, such as madam or kayak.
    // Write a function that takes a string and determines whether it's a palindrome
    // or not:
    // * Should be case insensitive.
    // * Special characters (punctuation or spaces) should be ignored.
    auto isPalindrome(std::string const& str) -> bool;

    // 30. Given two strings, create a function that returns the total number of
    // unique characters from the combined string. Each word will contain at least
    // one letter. All words will be lower cased.
    auto countUnique(std::string const& str1, std::string const& str2) -> int;

    // 31. Create a function that accepts a string and returns true if it's in the
    // format of a proper phone number and false if it's not. Assume any number
    // between from 0-9 (in the appropriate spots) will produce a valid phone
    // number. This is what a valid phone number looks like: (123) 456-7890
    auto isValidPhoneNumber(std::string const& str) -> bool;

    // 32. Write a function to create a Christmas tree based on height `h`.
    auto tree(int h) -> std::vector<std::string>;

    // 33. Create a function that takes a string and returns a new string with each
    // new character accumulating by +1. Separate each set with a dash./ Capitalize
    // the first letter of each set. All tests contain valid strings with alphabetic
    // characters (a-z, A-Z).
    auto accum(std::string const& s) -> std::string;

    // 34. Create a function that takes an array of numbers and return the number
    // that's unique. Test cases will always have exactly one unique number while
    // all others are the same.
    auto unique(std::vector<double> const& arr) -> double;

    // 35. Create a function that takes two strings and returns (true or false)
    // whether they're anagrams or not. Should be case insensitive.
    auto isAnagram(std::string const& s1, std::string const& s2) -> bool;

}  // namespace week03