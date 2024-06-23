#include "week02.hpp"

// 6. Find the Index
// 문자열 벡터와 문자열을 인자로 받아서 해당 문자열의 index를 return
auto findIndex(std::vector<std::string> const& src, std::string const& tgt) -> int {
    // - std::ranges::find: 범위에서 요소를 찾음. 여기서는 벡터에서 tgt 문자열을 찾음
    auto foundIdx = std::ranges::find(src.begin(), src.end(), tgt);
    // - std::distance: 두 반복자 사이의 거리를 계산하여 인덱스를 얻음
    return (foundIdx != src.end()) ? std::distance(src.begin(), foundIdx) : -1;
}

// 7. Product Divisible By Sum?
// 정수 벡터가 주어졌을 때, 그 벡터의 곱이 해당 벡터의 합으로 나누어지면 true return
auto divisible(std::vector<int> const& src) -> bool {
    // - std::accumulate: 범위에서 모든 요소를 누적하여 합 또는 곱을 계산
    int sum = std::accumulate(src.begin(), src.end(), 0);
    int product = std::accumulate(src.begin(), src.end(), 1, std::multiplies<int>());
    return product % sum == 0;
}

// 8. Factor Chain
// 인수 체인(factor chain)은 각 이전 요소가 다음 연속 요소의 인수(factor)인 정수
// "인수(factor)"는 한 숫자가 다른 숫자를 나누어 떨어지게 만드는 수
auto factorChain(std::vector<int> const& src) -> bool {
    // - std::adjacent_find: 인접한 요소 쌍을 찾음. 여기서는 b가 a로 나누어지지 않는 쌍을 찾음
    return std::adjacent_find(src.begin(), src.end(), [](int a, int b) { return b % a != 0; })
           == src.end();
}

// 9. Concatenating two integer vectors
// 두 개의 정수 벡터를 하나로 합치는 함수
auto concat(std::vector<int> const& ls, std::vector<int> const& rs) -> std::vector<int> {
    std::vector<int> result(ls);
    // - std::vector::insert: 다른 벡터의 요소를 현재 벡터의 끝에 삽입
    result.insert(result.end(), rs.begin(), rs.end());
    return result;
}

// 10. Check if a String Contains only Identical Characters
// 문자열 내 모든 문자가 동일한지 확인
auto isIdentical(std::string const& src) -> bool {
    // - std::all_of: 범위의 모든 요소가 주어진 조건을 만족하는지 확인
    return std::all_of(src.begin(), src.end(), [&src](char c) { return c == src[0]; });
}

// 11. Hamming Distance
// Hamming Distance는 두 문자열 사이의 서로 다른 문자의 개수를 의미
// 두 문자열 사이의 해밍 거리를 계산
auto hammingDistance(std::string const& src0, std::string const& src1) -> int {
    // - std::transform_reduce: 두 범위의 요소를 결합하고 변환하여 누적 값을 계산
    return std::transform_reduce(
        src0.begin(), src0.end(), src1.begin(), 0, std::plus<>(),
        std::not_equal_to<char>());  // - std::not_equal_to: 요소가 서로 다른지 확인
}

// 12. Count Instances of a Characters in a String
// 두 개의 문자열을 받아서, 첫 번째 문자열이 두 번째 문자열에서 중복 개수 (대소문자 구분)
auto charCount(char ch, std::string const& src) -> int {
    // - std::ranges::count: 범위에서 특정 값의 개수를 셈
    return std::ranges::count(src.begin(), src.end(), ch);
}

// 13. Mean of All Digits
// 모든 자릿수의 평균 반환 (항상 integer)
auto mean(int n) -> int {
    n = std::abs(n);
    // - std::to_string: 정수를 문자열로 변환
    std::string digits = std::to_string(n);
    // - std::accumulate: 범위에서 모든 요소를 누적하여 합을 계산
    // ASCII 값을 활용하여 char를 int로 형변환
    int sum = std::accumulate(digits.begin(), digits.end(), 0,
                              [](int sum, char c) { return sum + (c - '0'); });
    return sum / digits.size();
}
// 14. Double Letters
// 어진 단어가 연속된 두 개의 동일한 문자를 가지고 있는지 여부 판별
auto doubleLetters(std::string const& src) -> bool {
    // - std::adjacent_find: 인접한 요소 쌍을 찾음
    return std::adjacent_find(src.begin(), src.end()) != src.end();
}

// 15. Minimum Removals to Make Sum Even
// 벡터의 모든 요소들의 합을 짝수로 만들기 위해 필요한 최소 삭제 횟수
// 이미 합이 짝수인 경우에는 0을 반환
// 홀수인 경우에는 idx 앞에서 하나씩 지우면서 홀수로 맞춤
auto minimumRemovals(std::vector<int> const& src) -> int {
    // - std::accumulate: 범위에서 모든 요소를 누적하여 합을 계산
    int sum = std::accumulate(src.begin(), src.end(), 0);
    if (sum % 2 == 0) return 0;

    int currentSum = sum;
    int removalCount = 0;

    // - std::ranges::find_if: 조건을 만족하는 첫 번째 요소를 찾음
    auto foundIdx = std::ranges::find_if(src, [&](int n) {
        currentSum -= n;
        ++removalCount;
        return currentSum % 2 == 0;
    });

    return removalCount;
}

// 16. Snail Race
// 모리스와 스티브가 3마리의 달팽이를 가지고 달팽이 경주를 하는데, 모리스가 최소 2번 이상 승리하는지
// They each have 3, a slow (s), medium (m) and fast (written [Maurice, Steve]) Round 1: [s, f]
// Sacrifice his slowest snail against Steve's fastest. Round 2: [m, s] Use his middle snail against
// Steve's slowest. Round 3: [f, m] Use his fastest snail against Steve's middle. The function
// inputs:
//
// Array 1: [s, m, f] for Maurice.
// Array 2: [s, m, f] for Steve.
// Steve will always play in this order: [f, s, m].
// [&]는 람다 함수가 외부 범위의 모든 변수를 참조
auto mauriceWins(std::vector<int> const& m, std::vector<int> const& s) -> bool {
    std::vector<int> maurice = m;
    std::vector<int> steve = s;

    // - std::sort: 범위의 요소를 정렬
    std::sort(maurice.begin(), maurice.end());
    std::sort(steve.begin(), steve.end());

    // 각 라운드 비교 결과를 벡터에 저장
    std::vector<bool> results = {
        maurice[0] > steve[2],  // Round 1: Maurice's slowest vs Steve's fastest
        maurice[1] > steve[0],  // Round 2: Maurice's middle vs Steve's slowest
        maurice[2] > steve[1]   // Round 3: Maurice's fastest vs Steve's middle
    };

    // - std::count: 범위에서 특정 조건을 만족하는 요소의 개수를 셈
    int mauriceWinsCount = std::count(results.begin(), results.end(), true);

    // Maurice가 적어도 2개의 라운드에서 이겼는지 확인
    return mauriceWinsCount >= 2;
}

// 17. Index Shuffle
// 문자열에서 짝수 인덱스에 있는 문자들과 홀수 인덱스에 있는 문자들을 가져와서 이들을 연결
auto indexShuffle(std::string const& src) -> std::string {
    std::string evenCharacters, oddCharacters;
    // - std::partition_copy: 범위를 두 개의 범위로 복사하여 분할
    // - std::back_inserter: 요소를 컨테이너의 끝에 삽입할 수 있는 반복자 생성
    std::partition_copy(src.begin(), src.end(), std::back_inserter(evenCharacters),
                        std::back_inserter(oddCharacters),
                        [index = 0](char) mutable { return index++ % 2 == 0; });

    return evenCharacters + oddCharacters;
}

// 18. Spelling it Out
// 주어진 단어를 처음부터 하나씩 추가하여 완전한 단어를 만들기
auto spelling(std::string const& src) -> std::vector<std::string> {
    std::vector<std::string> result(src.size());
    // - std::ranges::generate: 범위에 대해 함수 호출을 통해 값을 생성
    // lambda: 현재 인덱스까지의 부분 문자열을 생성
    // mutable: 람다 함수의 내부에서 length 변수의 값을 변경할 수 있도록
    // substr: 문자열의 일부분을 추출하는 역할
    std::ranges::generate(result, [&, length = 0]() mutable { return src.substr(0, ++length); });
    return result;
}

// 19. Factorize a Number
// 주어진 숫자의 모든 약수를 포함하는 벡터
// 입력으로 주어지는 정수는 양수
auto factorize(int n) -> std::vector<int> {
    std::vector<int> factors;
    // - std::ranges::for_each: 범위의 각 요소에 대해 함수 호출
    // - std::views::iota: 지정된 범위의 숫자 시퀀스를 생성
    // 시퀀스(sequence)는 일련의 순서대로 배열된 요소들을 의미
    // C++에서 시퀀스 표현: 가장 기본적으로는 배열(array)이나 벡터(vector) 등의 연속된 메모리 공간에
    // 요소들을 저장하는 데이터 구조가 있고, 그 외에도 리스트(list), 맵(map), 집합(set) 등도 일정한
    // 순서를 가지는 요소들의 집합으로 시퀀스로 간주
    std::ranges::for_each(std::views::iota(1, n + 1), [&](int candidateFactor) {
        if (n % candidateFactor == 0) factors.push_back(candidateFactor);
    });
    return factors;
}
// 20. Find the Missing Number
// 주어진 정수 벡터에서 (1부터 10까지의 숫자 중에서 하나가 빠진) 누락된 숫자를 찾기
auto missingNum(std::vector<int> const& src) -> int {
    // - std::accumulate: 범위에서 모든 요소를 누적하여 합을 계산
    return 55 - std::accumulate(src.begin(), src.end(), 0);
}