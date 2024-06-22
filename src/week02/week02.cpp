#include "week02.hpp"

// 6. Find the Index
// ���ڿ� ���Ϳ� ���ڿ��� ���ڷ� �޾Ƽ� �ش� ���ڿ��� index�� return
auto findIndex(std::vector<std::string> const& src, std::string const& tgt) -> int {
    auto it = std::find(src.begin(), src.end(), tgt);
    return (it != src.end()) ? std::distance(src.begin(), it) : -1;
}

// 7. Product Divisible By Sum?
// ���� ���Ͱ� �־����� ��, �� ������ ���� �ش� ������ ������ ���������� true return
auto divisible(std::vector<int> const& src) -> bool {
    int sum = std::accumulate(src.begin(), src.end(), 0);
    int product = std::accumulate(src.begin(), src.end(), 1, std::multiplies<int>());
    return product % sum == 0;
}

// 8. Factor Chain
// �μ� ü��(factor chain)�� �� ���� ��Ұ� ���� ���� ����� �μ�(factor)�� ����
// "�μ�(factor)"�� �� ���ڰ� �ٸ� ���ڸ� ������ �������� ����� ��
auto factorChain(std::vector<int> const& src) -> bool {
    return std::adjacent_find(src.begin(), src.end(), [](int a, int b) { return b % a != 0; })
           == src.end();
}

// 9. Concatenating two integer vectors
// �� ���� ���� ���͸� �ϳ��� ��ġ�� �Լ�
auto concat(std::vector<int> const& ls, std::vector<int> const& rs) -> std::vector<int> {
    std::vector<int> result(ls);
    result.insert(result.end(), rs.begin(), rs.end());
    return result;
}

// 10. Check if a String Contains only Identical Characters
// ���ڿ� �� ��� ���ڰ� �������� Ȯ��
auto isIdentical(std::string const& src) -> bool {
    return std::all_of(src.begin(), src.end(), [&src](char c) { return c == src[0]; });
}

// 11. Hamming Distance
// Hamming Distance�� �� ���ڿ� ������ ���� �ٸ� ������ ������ �ǹ�
// �� ���ڿ� ������ �ع� �Ÿ��� ���
auto hammingDistance(std::string const& src0, std::string const& src1) -> int {
    return std::transform_reduce(src0.begin(), src0.end(), src1.begin(), 0, std::plus<>(),
                                 std::not_equal_to<char>());
}

// 12. Count Instances of a Characters in a String
// �� ���� ���ڿ��� �޾Ƽ�, ù ��° ���ڿ��� �� ��° ���ڿ����� �ߺ� ���� (��ҹ��� ����)
auto charCount(char ch, std::string const& src) -> int {
    return std::ranges::count(src.begin(), src.end(), ch);
}

// 13. Mean of All Digits
// ��� �ڸ����� ��� ��ȯ (�׻� integer)
auto mean(int n) -> int {
    n = std::abs(n);
    std::string digits = std::to_string(n);
    int sum = std::accumulate(digits.begin(), digits.end(), 0,
                              [](int sum, char c) { return sum + (c - '0'); });
    return sum / digits.size();
}
// 14. Double Letters
// ���� �ܾ ���ӵ� �� ���� ������ ���ڸ� ������ �ִ��� ���� �Ǻ�
auto doubleLetters(std::string const& src) -> bool {
    return std::adjacent_find(src.begin(), src.end()) != src.end();
}

// 15. Minimum Removals to Make Sum Even
// ������ ��� ��ҵ��� ���� ¦���� ����� ���� �ʿ��� �ּ� ���� Ƚ��
// �̹� ���� ¦���� ��쿡�� 0�� ��ȯ
// Ȧ���� ��쿡�� idx �տ��� �ϳ��� ����鼭 Ȧ���� ����
auto minimumRemovals(std::vector<int> const& src) -> int {
    int sum = std::accumulate(src.begin(), src.end(), 0);
    if (sum % 2 == 0) return 0;

    // int currentSum = sum;
    // int removalCount = 0;

    // auto it = std::ranges::find_if(src, [&](int n) {
    //     currentSum -= n;
    //     ++removalCount;
    //     return currentSum % 2 == 0;
    // });

    // return removalCount;

    std::vector<std::pair<int, int>> indexed_src(src.size());
    std::ranges::transform(src, indexed_src.begin(),
                           [index = 0](int n) mutable { return std::pair{index++, n}; });

    auto it = std::ranges::find_if(
        indexed_src, [sum](auto const& pair) { return (sum - pair.second) % 2 == 0; });

    return it != indexed_src.end() ? it->first + 1 : 0;
}

// 16. Snail Race
// �𸮽��� ��Ƽ�갡 3������ �����̸� ������ ������ ���ָ� �ϴµ�, �𸮽��� �ּ� 2�� �̻� �¸��ϴ���
// They each have 3, a slow (s), medium (m) and fast (written [Maurice, Steve]) Round 1: [s, f]
// Sacrifice his slowest snail against Steve's fastest. Round 2: [m, s] Use his middle snail against
// Steve's slowest. Round 3: [f, m] Use his fastest snail against Steve's middle. The function
// inputs:
//
// Array 1: [s, m, f] for Maurice.
// Array 2: [s, m, f] for Steve.
// Steve will always play in this order: [f, s, m].
// [&]�� ���� �Լ��� �ܺ� ������ ��� ������ ����
auto mauriceWins(std::vector<int> const& m, std::vector<int> const& s) -> bool {
    std::vector<int> maurice = m;
    std::vector<int> steve = s;

    // ���͸� �����մϴ�.
    std::sort(maurice.begin(), maurice.end());
    std::sort(steve.begin(), steve.end());

    // �� ���� �� ����� ���Ϳ� �����մϴ�.
    std::vector<bool> results = {
        maurice[0] > steve[2],  // Round 1: Maurice's slowest vs Steve's fastest
        maurice[1] > steve[0],  // Round 2: Maurice's middle vs Steve's slowest
        maurice[2] > steve[1]   // Round 3: Maurice's fastest vs Steve's middle
    };

    // Maurice�� �̱� ������ ���� ����մϴ�.
    int mauriceWinsCount = std::count(results.begin(), results.end(), true);

    // Maurice�� ��� 2���� ���忡�� �̰���� Ȯ���մϴ�.
    return mauriceWinsCount >= 2;
}

// 17. Index Shuffle
// ���ڿ����� ¦�� �ε����� �ִ� ���ڵ�� Ȧ�� �ε����� �ִ� ���ڵ��� �����ͼ� �̵��� ����
auto indexShuffle(std::string const& src) -> std::string {
    std::string evenCharacters, oddCharacters;

    std::partition_copy(src.begin(), src.end(), std::back_inserter(evenCharacters),
                        std::back_inserter(oddCharacters),
                        [index = 0](char) mutable { return index++ % 2 == 0; });

    return evenCharacters + oddCharacters;
}

// 18. Spelling it Out
// �־��� �ܾ ó������ �ϳ��� �߰��Ͽ� ������ �ܾ �����
auto spelling(std::string const& src) -> std::vector<std::string> {
    std::vector<std::string> result(src.size());
    std::ranges::generate(result, [&, n = 0]() mutable { return src.substr(0, ++n); });
    return result;
}

// 19. Factorize a Number
// �־��� ������ ��� ����� �����ϴ� ����
// �Է����� �־����� ������ ���
auto factorize(int n) -> std::vector<int> {
    std::vector<int> factors;
    std::ranges::for_each(std::views::iota(1, n + 1), [&](int i) {
        if (n % i == 0) factors.push_back(i);
    });
    return factors;
}
// 20. Find the Missing Number
// �־��� ���� ���Ϳ��� (1���� 10������ ���� �߿��� �ϳ��� ����) ������ ���ڸ� ã��
auto missingNum(std::vector<int> const& src) -> int {
    return 55 - std::accumulate(src.begin(), src.end(), 0);
}