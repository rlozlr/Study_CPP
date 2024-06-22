#pragma once

#ifndef WEEK01_HPP
#define WEEK01_HPP

#include <vector>
#include <string>
// 표준 라이브러리의 다양한 알고리즘 함수들을 포함 (https://en.cppreference.com/w/cpp/algorithm)
// std::transform, std::minmax_element 등을 위해
#include <algorithm>
// 함수 객체와 함수 조합 지원
// std::negate를 위해
#include <functional>

// 1. Typing Game >>> 단어를 비교하여 일치 여부
auto correctStream(const std::vector<std::string> &src,
                   const std::vector<std::string> &tgt) -> std::vector<int>;

// 2. Negate the List >>> 모든 숫자 부호 반전
auto negate(const std::vector<int> &src) -> std::vector<int>;

// 3. Exists a Number Higher? >>> 주어진 숫자보다 큰 숫자가 존재하는지F
auto existsHigher(const std::vector<int> &src, int n) -> bool;

// 4. Word Endings >>> 각 단어에 접미사를 추가
auto addEnding(const std::vector<std::string> &src,
               const std::string &sfx) -> std::vector<std::string>;

// 5. Difference of Max and Min Numbers in Array >>> 벡최대값과 최소값의 차이
auto differenceMaxMin(const std::vector<int> &src) -> int;

#endif // WEEK01_HPP
