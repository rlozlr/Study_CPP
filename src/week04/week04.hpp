#pragma once

#include <chrono>
#include <functional>
#include <map>
#include <optional>
#include <random>
#include <string>
#include <unordered_map>
#include <vector>

namespace annzy::week04 {

    auto alliterationCorrect(std::string const& src) -> bool;
    auto seesaw(int num) -> std::string;
    auto progressDays(std::vector<int> const& src) -> int;
    auto wurstIsBetter(std::string const& src) -> std::string;
    auto reverse(std::string const& src) -> std::string;
    auto bridgeShuffle(std::vector<std::string> const& v0,
                       std::vector<std::string> const& v1) -> std::vector<std::string>;
    auto simonSays(std::vector<int> const& v0, std::vector<int> const& v1) -> bool;
    auto lastDigit(int a, int b, int c) -> bool;
    auto checkPerfect(int n) -> bool;
    auto isSubset(std::vector<int> const& sub, std::vector<int> const& sup) -> bool;
    auto isSmooth(std::string const& src) -> bool;
    auto parseSubtitleLine(std::string const& line)
        -> std::optional<std::pair<std::chrono::milliseconds, std::string>>;
    auto marathon(std::multimap<std::chrono::milliseconds, std::string> const& records,
                  std::chrono::milliseconds min,
                  std::chrono::milliseconds max) -> std::vector<std::string>;
    using ItemMap = std::unordered_map<std::string, int>;
    auto lootItems(std::vector<std::string> const& monsters,
                   std::unordered_map<std::string, ItemMap> const& loots) -> ItemMap;
    auto monteCarloIntegration(double a, double b, std::function<double(double)> fn,
                               std::mt19937_64& rng, int samples) -> double;

}  // namespace annzy::week04