#pragma once

#include <string>
#include <vector>

auto identicalFilter(std::vector<std::string> const& arr) -> std::vector<std::string>;
auto shiftL(std::vector<int> const& arr, int num) -> std::vector<int>;
auto shiftR(std::vector<int> const& arr, int num) -> std::vector<int>;
auto setFrom(std::vector<int> const& arr) -> std::vector<int>;
auto firstAndLast(std::string const& s) -> std::vector<std::string>;
auto convertCartesian(std::vector<int> const& x,
                      std::vector<int> const& y) -> std::vector<std::vector<int>>;
auto sortByLength(std::vector<std::string> const& arr) -> std::vector<std::string>;
auto countAdverbs(std::string const& s) -> int;
auto societyName(std::vector<std::string> const& friends) -> std::string;
auto isPalindrome(std::string const& str) -> bool;
auto countUnique(std::string const& str1, std::string const& str2) -> int;
auto isValidPhoneNumber(std::string const& str) -> bool;
auto tree(int h) -> std::vector<std::string>;
auto accum(std::string const& s) -> std::string;
auto unique(std::vector<double> const& arr) -> double;
auto isAnagram(std::string const& s1, std::string const& s2) -> bool;