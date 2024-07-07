#pragma once

#include <algorithm>
#include <cmath>
#include <iterator>
#include <numeric>
#include <ranges>
#include <string>
#include <vector>

namespace annzy::week02 {

    auto findIndex(std::vector<std::string> const& src, std::string const& tgt) -> int;
    auto divisible(std::vector<int> const& src) -> bool;
    auto factorChain(std::vector<int> const& src) -> bool;
    auto concat(std::vector<int> const& ls, std::vector<int> const& rs) -> std::vector<int>;
    auto isIdentical(std::string const& src) -> bool;
    auto hammingDistance(std::string const& src0, std::string const& src1) -> int;
    auto charCount(char ch, std::string const& src) -> int;
    auto mean(int n) -> int;
    auto doubleLetters(std::string const& src) -> bool;
    auto minimumRemovals(std::vector<int> const& src) -> int;
    auto mauriceWins(std::vector<int> const& m, std::vector<int> const& s) -> bool;
    auto indexShuffle(std::string const& src) -> std::string;
    auto spelling(std::string const& src) -> std::vector<std::string>;
    auto factorize(int n) -> std::vector<int>;
    auto missingNum(std::vector<int> const& src) -> int;

}  // namespace annzy::week02
