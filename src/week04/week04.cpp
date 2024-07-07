#include "week04.hpp"

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <numeric>
#include <random>
#include <ranges>
#include <regex>
#include <sstream>

namespace annzy::week04 {

    auto alliterationCorrect(std::string const& src) -> bool {
        std::regex pattern(R"(\b(\w)\w{3,}\b)");

        std::vector<std::string> alliterationWords;
        std::sregex_token_iterator it(src.begin(), src.end(), pattern);
        std::sregex_token_iterator end;

        std::ranges::copy(it, end, std::back_inserter(alliterationWords));

        if (alliterationWords.empty()) {
            return false;
        }

        char firstLetter = std::tolower(alliterationWords.front()[0]);
        return std::ranges::all_of(alliterationWords, [firstLetter](const std::string& word) {
            return std::tolower(word[0]) == firstLetter;
        });
    }

    auto seesaw(int num) -> std::string {
        std::string strNum = std::to_string(num);
        int mid = strNum.size() / 2;
        int left = std::accumulate(strNum.begin(), strNum.begin() + mid, 0);
        int right = std::accumulate(strNum.begin() + mid + +(strNum.size() % 2), strNum.end(), 0);
        return left == right ? "balanced" : (left > right ? "left" : "right");
    }

    auto progressDays(std::vector<int> const& src) -> int {
        std::vector<int> differences;
        std::adjacent_difference(src.begin(), src.end(), std::back_inserter(differences));
        return std::count_if(differences.begin() + 1, differences.end(),
                             [](int diff) { return diff > 0; });
    }

    auto wurstIsBetter(std::string const& src) -> std::string {
        std::regex pattern(
            R"(\b(kielbasa|chorizo|moronga|salami|sausage|andouille|name|merguez|gurka|snorkers|pepperoni|naem)\b)",
            std::regex_constants::icase);

        return std::regex_replace(src, pattern, "Wurst");
    }

    auto reverse(std::string const& src) -> std::string {
        std::istringstream iss(src);
        std::ostringstream oss;

        auto reverseFunction = [](const std::string& word) {
            if (word.size() >= 5) {
                std::string reversed = word;
                std::reverse(reversed.begin(), reversed.end());
                return reversed;
            }
            return word;
        };

        std::ranges::transform(std::istream_iterator<std::string>(iss),
                               std::istream_iterator<std::string>(),
                               std::ostream_iterator<std::string>(oss, " "), reverseFunction);

        std::string result = oss.str();
        if (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }

        return result;
    }

    auto bridgeShuffle(std::vector<std::string> const& v0,
                       std::vector<std::string> const& v1) -> std::vector<std::string> {
        std::vector<std::string> result;

        int minLength = std::min(v0.size(), v1.size());

        for (int i = 0; i < minLength; ++i) {
            result.push_back(v0[i]);
            result.push_back(v1[i]);
        }

        std::move(v0.begin() + minLength, v0.end(), std::back_inserter(result));
        std::move(v1.begin() + minLength, v1.end(), std::back_inserter(result));

        return result;
    }

    auto simonSays(std::vector<int> const& v0, std::vector<int> const& v1) -> bool {
        return std::equal(v1.begin() + 1, v1.end(), v0.begin());
    }

    auto lastDigit(int a, int b, int c) -> bool {
        int lastA, lastB, lastC;
        std::tie(lastA, lastB, lastC) = std::make_tuple(a % 10, b % 10, c % 10);
        return (lastA * lastB) % 10 == lastC;
    }

    auto checkPerfect(int n) -> bool {
        auto range = std::views::iota(1, static_cast<int>(std::sqrt(n)) + 1)
                     | std::views::filter([n](int i) { return n % i == 0; });
        int sum = std::accumulate(range.begin(), range.end(), 0, [n](int acc, int i) {
            return acc + i + ((i != 1 && i != n / i) ? n / i : 0);
        });

        return sum == n;
    }

    auto isSubset(std::vector<int> const& sub, std::vector<int> const& sup) -> bool {
        std::vector<int> sortedSub = sub;
        std::vector<int> sortedSup = sup;

        std::ranges::sort(sortedSub);
        std::ranges::sort(sortedSup);

        return std::ranges::includes(sortedSup, sortedSub);
    }

    auto isSmooth(std::string const& src) -> bool {
        std::istringstream iss(src);
        std::vector<std::string> words((std::istream_iterator<std::string>(iss)),
                                       std::istream_iterator<std::string>());

        return std::adjacent_find(words.begin(), words.end(),
                                  [](const std::string& prev, const std::string& next) {
                                      return std::tolower(prev.back())
                                             != std::tolower(next.front());
                                  })
               == words.end();
    }

    auto parseSubtitleLine(std::string const& line)
        -> std::optional<std::pair<std::chrono::milliseconds, std::string>> {
        // \s+: 하나 이상의 공백 문자를 매치
        // (.*\S):
        // .* : 임의의 문자(0개 이상)
        // \S : 공백이 아닌 문자(최소한 한 개) 이 부분은 공백을 제외한 모든 문자열을 매치
        // \s*: 공백 문자 (0개 이상)을 매치
        std::regex rgx(R"((\d{2}):(\d{2}):(\d{2})\.(\d{3})\s+(.*\S)\s*)");
        // std::regex_match 함수를 사용하여 입력 문자열 line이 정규표현식 rgx와 매치되는지 검사
        std::smatch match;
        // 매칭이 되지 않으면 std::nullopt를 반환하여 유효하지 않은 입력을 처리
        if (!std::regex_match(line, match, rgx)) return std::nullopt;

        // std::stoi 함수를 사용하여 문자열을 정수로 변환
        int h = std::stoi(match[1]), m = std::stoi(match[2]), s = std::stoi(match[3]),
            ms = std::stoi(match[4]);

        auto time = std::chrono::milliseconds(((h * 3600 + m * 60 + s) * 1000) + ms);

        return std::make_pair(time, match[5]);
    }

    auto marathon(std::multimap<std::chrono::milliseconds, std::string> const& records,
                  std::chrono::milliseconds min,
                  std::chrono::milliseconds max) -> std::vector<std::string> {
        std::vector<std::string> result;
        // records는 키와 값의 쌍을 저장하는 맵(map)
        auto lower = records.lower_bound(min), upper = records.upper_bound(max);

        std::transform(lower, upper, std::back_inserter(result),
                       [](const auto& pair) { return pair.second; });

        return result;
    }

    using ItemMap = std::unordered_map<std::string, int>;
    auto lootItems(std::vector<std::string> const& monsters,
                   std::unordered_map<std::string, ItemMap> const& loots) -> ItemMap {
        ItemMap items;
        for (const auto& monster : monsters) {
            const auto& loot = loots.at(monster);
            std::for_each(loot.begin(), loot.end(),
                          [&items](const auto& pair) { items[pair.first] += pair.second; });
        }
        for (auto it = items.begin(); it != items.end();)
            it = (it->second == 0) ? items.erase(it) : std::next(it);
        return items;
    }

    // a, b: 적분 구간 [a, b]
    // fn: 적분할 함수, fn(x)는 적분할 함수의 값
    // rng: 무작위 수 생성기, std::mt19937_64 타입으로 초기화된 객체 사용
    // samples: 샘플링할 표본의 개수
    // I = (b - a) * (1/N) * Σ[i=1 to N] f(x_i)
    auto monteCarloIntegration(double a, double b, std::function<double(double)> fn,
                               std::mt19937_64& rng, int samples) -> double {
        // 구간 [a, b]에서 균일하게 분포된 무작위 실수를 생성할 수 있는 분포 객체를 생성
        std::uniform_real_distribution<> dist(a, b);
        double sum = 0;

        // 지정된 표본 개수만큼 반복하고, 무작위로 선택한 x 값에 대해 fn을 계산
        for (int i = 0; i < samples; ++i) sum += fn(dist(rng));

        // (b - a) * (1/N) * Σ[i=1 to N] f(x_i)
        // Σ[i=1 to N] f(x_i): 구간 [a, b]에서 N개의 무작위 샘플 x_i에서 함수 f(x)의 값의 합
        // (1/N): 이는 샘플의 개수 N으로 나누어 평균을 구하는 정규화 상수
        // (1/N) * Σ[i=1 to N] f(x_i)는 모든 샘플에 대해 계산된 함수 f(x)의 값의 평균
        // (1/samples) * Σ[i=1 to samples] f(rng)
        return (b - a) * sum / samples;
    }

}  // namespace annzy::week04
