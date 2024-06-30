#include "week03.hpp"

// 21. 문자열 벡터에서 각 문자가 동일한 문자열을 필터링하는 함수
// 주어진 문자열 벡터에서 모든 문자가 동일한 문자열을 필터링
auto identicalFilter(std::vector<std::string> const& arr) -> std::vector<std::string> {
    std::vector<std::string> result;
    // std::copy_if: 조건을 만족하는 요소만을 result에 복사
    std::copy_if(arr.begin(), arr.end(), std::back_inserter(result), [](const std::string& str) {
        return std::all_of(str.begin(), str.end(), [&](char c) { return c == str[0]; });
    });
    return result;
}

// 22. 벡터의 요소를 왼쪽으로 시프트하는 함수
// 주어진 벡터의 요소들을 왼쪽으로 num만큼 시프트
auto shiftL(std::vector<int> const& arr, int num) -> std::vector<int> {
    std::vector<int> result = arr;
    int n = arr.size();
    num = num % n;
    // std::rotate: 벡터의 요소들을 왼쪽으로 시프트
    std::rotate(result.begin(), result.begin() + num, result.end());
    return result;
}

// 23. 벡터의 요소를 오른쪽으로 시프트하는 함수
// 주어진 벡터의 요소들을 오른쪽으로 num만큼 시프트
auto shiftR(std::vector<int> const& arr, int num) -> std::vector<int> {
    std::vector<int> result = arr;
    int n = arr.size();
    num = num % n;
    // std::rotate: 벡터의 요소들을 오른쪽으로 시프트
    std::rotate(result.rbegin(), result.rbegin() + num, result.rend());
    return result;
}

// 24. 벡터에서 중복된 요소를 제거하는 함수
// 주어진 벡터에서 중복된 요소들을 제거하여 반환
auto setFrom(std::vector<int> const& arr) -> std::vector<int> {
    std::set<int> uniqueSet(arr.begin(), arr.end());
    return std::vector<int>(uniqueSet.begin(), uniqueSet.end());
}

// 25. 문자열을 사전 순서와 역순으로 정렬하는 함수
// 주어진 문자열을 사전 순서와 역순으로 정렬하여 반환
auto firstAndLast(std::string const& s) -> std::vector<std::string> {
    std::string sorted = s;
    // std::sort: 문자열을 사전 순서로 정렬
    std::sort(sorted.begin(), sorted.end());
    std::string reverseSorted = sorted;
    // std::reverse: 문자열을 역순으로 정렬
    std::reverse(reverseSorted.begin(), reverseSorted.end());
    return {sorted, reverseSorted};
}

// 26. 두 벡터의 카르테시안 곱을 계산하는 함수
// 주어진 두 벡터의 카르테시안 곱을 계산하여 반환
auto convertCartesian(std::vector<int> const& x,
                      std::vector<int> const& y) -> std::vector<std::vector<int>> {
    std::vector<std::vector<int>> result;
    // std::transform: 두 벡터의 각 요소들을 페어로 묶어 result에 추가
    std::transform(x.begin(), x.end(), y.begin(), std::back_inserter(result),
                   [](int xi, int yi) { return std::vector<int>{xi, yi}; });
    return result;
}

// 27. 문자열 벡터를 길이 순으로 정렬하는 함수
// 주어진 문자열 벡터를 각 문자열의 길이 순으로 정렬하여 반환
auto sortByLength(std::vector<std::string> const& arr) -> std::vector<std::string> {
    std::vector<std::string> result = arr;
    // std::sort: 문자열을 길이 순서로 정렬
    std::sort(result.begin(), result.end(),
              [](const std::string& a, const std::string& b) { return a.size() < b.size(); });
    return result;
}

// 28. 문장에서 'ly'로 끝나는 부사의 수를 세는 함수
// 주어진 문장에서 'ly'로 끝나는 부사의 수를 세어 반환
auto countAdverbs(std::string const& s) -> int {
    // 정규식 활용
    std::regex adverb_regex(R"(\b\w+ly\b)");
    // sregex_iterator를 사용하여 입력 문자열을 정규식에 맞게 반복적으로 검색
    auto words_begin = std::sregex_iterator(s.begin(), s.end(), adverb_regex);
    auto words_end = std::sregex_iterator();
    // 찾은 부사의 개수를 계산하여 반환
    return std::distance(words_begin, words_end);
}

// 29. 친구들의 이름 첫 글자를 모아 사전 순서로 정렬하는 함수
// 주어진 친구들의 이름에서 첫 글자를 모아 사전 순서로 정렬하여 반환
auto societyName(std::vector<std::string> const& friends) -> std::string {
    std::string result;
    // 각 이름의 첫 글자를 추출하여 result에 추가
    std::transform(friends.begin(), friends.end(), std::back_inserter(result),
                   [](const std::string& name) { return name[0]; });
    // std::sort: 추출된 첫 글자를 사전 순서로 정렬
    std::sort(result.begin(), result.end());
    return result;
}

// 30. 문자열이 회문인지 검사하는 함수
// 주어진 문자열이 회문인지 검사하여 반환
auto isPalindrome(std::string const& str) -> bool {
    std::string filtered;
    // std::copy_if: 문자열에서 영숫자만 추출
    std::copy_if(str.begin(), str.end(), std::back_inserter(filtered),
                 [](char c) { return std::isalnum(c); });
    // std::transform: 문자열을 소문자로 변환
    std::transform(filtered.begin(), filtered.end(), filtered.begin(), ::tolower);
    // std::equal: 문자열의 앞뒤를 비교하여 회문인지 검사
    return std::equal(filtered.begin(), filtered.begin() + filtered.size() / 2, filtered.rbegin());
}

// 31. 두 문자열에서 고유한 문자의 개수를 세는 함수
// 주어진 두 문자열에서 고유한 문자의 개수를 세어 반환
auto countUnique(std::string const& str1, std::string const& str2) -> int {
    std::unordered_set<char> uniqueChars(str1.begin(), str1.end());
    uniqueChars.insert(str2.begin(), str2.end());
    return uniqueChars.size();
}

// 32. 전화번호가 유효한지 검사하는 함수
// 주어진 문자열이 유효한 전화번호인지 검사하여 반환
auto isValidPhoneNumber(const std::string& str) -> bool {
    // 전화번호 패턴 정의: (ddd) ddd-dddd 형식 (d는 숫자)
    std::regex pattern("\\(\\d{3}\\) \\d{3}-\\d{4}");

    // 정규식과 매치되는지 검사
    return std::regex_match(str, pattern);
}

// 33. 높이에 따라 트리를 생성하는 함수
// 주어진 높이에 따라 트리를 생성하여 반환
auto tree(int h) -> std::vector<std::string> {
    std::vector<std::string> result(h);

    // 레벨별로 트리 생성
    int max_width = 2 * h - 1;

    // 범위 기반 for 문을 사용하여 각 레벨의 트리를 생성
    for (int i = 0; i < h; ++i) {
        int num_hashes = 2 * i + 1;
        int num_spaces = (max_width - num_hashes) / 2;

        result[i] = std::string(num_spaces, ' ') + std::string(num_hashes, '#')
                    + std::string(num_spaces, ' ');
    }

    return result;
}

// 34. 문자열을 특정 형식으로 변환하는 함수
// 주어진 문자열을 특정 형식으로 변환하여 반환
auto accum(std::string const& s) -> std::string {
    std::string result;

    // 문자열을 순회하면서 원하는 패턴으로 변환하여 결과에 추가
    int count = 0;
    for (char c : s) {
        if (count > 0) {
            result += '-';
        }
        result += std::toupper(c);                      // 대문자로 변환
        result += std::string(count, std::tolower(c));  // 각 문자별로 추가적인 소문자 추가
        ++count;
    }

    return result;
}

// 35. 벡터에서 유일한 요소를 찾는 함수
// 주어진 벡터에서 유일한 요소를 찾아 반환
auto unique(std::vector<double> const& arr) -> double {
    std::unordered_map<double, int> countMap;
    // 각 요소의 개수를 세어 countMap에 저장
    std::for_each(arr.begin(), arr.end(), [&countMap](double num) { ++countMap[num]; });

    // count가 1인 첫 번째 요소를 찾아 반환
    auto it = std::find_if(arr.begin(), arr.end(),
                           [&countMap](double num) { return countMap[num] == 1; });

    return (it != arr.end()) ? *it : -1;  // 유일한 요소가 없으면 -1 반환
}

// 36. 두 문자열이 애너그램인지 확인하는 함수
// 주어진 두 문자열이 애너그램인지 확인하여 반환
auto isAnagram(std::string const& s1, std::string const& s2) -> bool {
    auto sorted1 = s1, sorted2 = s2;
    // std::transform: 문자열을 소문자로 변환
    std::transform(sorted1.begin(), sorted1.end(), sorted1.begin(), ::tolower);
    std::transform(sorted2.begin(), sorted2.end(), sorted2.begin(), ::tolower);
    // std::sort: 문자열을 정렬
    std::sort(sorted1.begin(), sorted1.end());
    std::sort(sorted2.begin(), sorted2.end());
    // 정렬된 두 문자열이 같은지 비교
    return sorted1 == sorted2;
}
