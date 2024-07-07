#pragma once

#include <algorithm>  // for std::all_of, std::rotate, std::sort, std::reverse, std::copy_if, std::equal, std::partition_copy, std::ranges::generate
#include <cassert>
#include <cctype>  // for std::tolower, std::isalnum, std::isalpha, std::isdigit
#include <iostream>
#include <iterator>  // for std::back_inserter
#include <numeric>   // for std::iota
#include <regex>
#include <set>            // for std::set
#include <string>         // for std::string, std::toupper
#include <unordered_map>  // for std::unordered_map
#include <unordered_set>  // for std::unordered_set
#include <vector>         // for std::vector

namespace annzy::week03 {

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

}  // namespace annzy::week03
