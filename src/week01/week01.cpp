#include "week01.hpp"

// 캡처(Capture)란 C++ 람다(lambda) 함수에서 외부 변수를 내부로 가져오는 것
// 캡처를 통해 람다 함수는 자신이 생성된 시점에서의 외부 변수의 값을 유지하거나 사용
// 일반적으로 람다 함수는 외부 변수에 대한 접근을 제한
// 람다 함수 내에서 외부 변수에 접근하려면, 그 변수를 명시적으로 캡처해야 됨.
// 캡처는 대괄호([]) 안에 위치하며, 여기에 캡처할 변수를 지정
namespace annzy::week01 {

    // 1. Typing Game >>> 단어를 비교하여 일치 여부
    auto correctStream(const std::vector<std::string>& word1,
                       const std::vector<std::string>& word2) -> std::vector<int> {
        // 결과 벡터 생성
        std::vector<int> result(word1.size());

        // 일치하면 1, 일치하지 않으면 -1을 결과 벡터에 저장
        // 일반적으로 std::transform을 사용할 때는 변환 대상 범위와 결과를 저장할 범위는 반드시
        // 동일한 크기 std::transform(범위의 시작, 범위의 끝, 비교범위 시작, 결과를 저장할 시작점,
        // 람다식)
        std::transform(
            word1.begin(), word1.end(), word2.begin(), result.begin(),
            [](const std::string& w1,
               const std::string& w2) {  // []는 C++에서 람다(lambda) 함수를 정의할 때 사용
                return (w1 == w2) ? 1 : -1;
            });
        return result;
    }

    // 2. Negate the List >>> 모든 숫자 부호 반전
    // std::negate<int>()는 STL에서 제공하는 함수 객체로, <functional> 헤더 파일에 정의
    auto negate(const std::vector<int>& nums) -> std::vector<int> {
        // 결과 벡터 생성
        std::vector<int> result(nums.size());

        // 부호 반전하여 결과 벡터에 저장
        // std::transform(범위의 시작, 범위의 끝, 결과를 저장할 시작점, 변환 함수);
        std::transform(nums.begin(), nums.end(), result.begin(), std::negate<int>());
        return result;
    }

    // 3. Exists a Number Higher? >>> 주어진 숫자보다 큰 숫자가 존재하는지
    auto existsHigher(const std::vector<int>& nums, int standardNum) -> bool {
        // 입력 벡터에서 주어진 숫자보다 큰 숫자가 존재하는지 여부를 검사하여 반환
        // std::any_of(범위의 시작, 범위의 끝, 특정 조건)
        return std::any_of(nums.begin(), nums.end(),
                           [standardNum](int num) { return num > standardNum; });
    }

    // constrained algorithm
    // std::range::transform

    // 4. Word Endings >>> 각 단어에 접미사를 추가
    auto addEnding(const std::vector<std::string>& words,
                   const std::string& suffix) -> std::vector<std::string> {
        // 람다 함수를 반환형(함수의 반환형이 명확하지 않을 때)을 지정해야 하는 함수에 사용할 때 ->
        // 구문을 사용 결과 벡터 생성
        std::vector<std::string> result(words.size());

        // 접미사를 추가하여 결과 벡터에 저장
        std::transform(words.begin(), words.end(), result.begin(),
                       [&suffix](const std::string& word) { return word + suffix; });
        return result;
    }

    // 5. Difference of Max and Min Numbers in Array >>> 최대값과 최소값의 차이
    auto differenceMaxMin(const std::vector<int>& nums) -> int {
        // 입력 벡터가 비어있으면 0 반환
        if (nums.empty()) {
            return 0;
        }

        // 벡터에서 최소값과 최대값을 구하고 그 차이를 반환
        // std::minmax_element()는 pair 타입으로 최소값과 최대값을 반환
        // pair는 #include <utility> 여기에 정의
        auto [min, max] = std::minmax_element(nums.begin(), nums.end());
        return *max - *min;
    }

}  // namespace annzy::week01
