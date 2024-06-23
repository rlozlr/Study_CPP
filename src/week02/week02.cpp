#include "week02.hpp"

// 6. Find the Index
// ���ڿ� ���Ϳ� ���ڿ��� ���ڷ� �޾Ƽ� �ش� ���ڿ��� index�� return
auto findIndex(std::vector<std::string> const& src, std::string const& tgt) -> int {
    // - std::ranges::find: �������� ��Ҹ� ã��. ���⼭�� ���Ϳ��� tgt ���ڿ��� ã��
    auto foundIdx = std::ranges::find(src.begin(), src.end(), tgt);
    // - std::distance: �� �ݺ��� ������ �Ÿ��� ����Ͽ� �ε����� ����
    return (foundIdx != src.end()) ? std::distance(src.begin(), foundIdx) : -1;
}

// 7. Product Divisible By Sum?
// ���� ���Ͱ� �־����� ��, �� ������ ���� �ش� ������ ������ ���������� true return
auto divisible(std::vector<int> const& src) -> bool {
    // - std::accumulate: �������� ��� ��Ҹ� �����Ͽ� �� �Ǵ� ���� ���
    int sum = std::accumulate(src.begin(), src.end(), 0);
    int product = std::accumulate(src.begin(), src.end(), 1, std::multiplies<int>());
    return product % sum == 0;
}

// 8. Factor Chain
// �μ� ü��(factor chain)�� �� ���� ��Ұ� ���� ���� ����� �μ�(factor)�� ����
// "�μ�(factor)"�� �� ���ڰ� �ٸ� ���ڸ� ������ �������� ����� ��
auto factorChain(std::vector<int> const& src) -> bool {
    // - std::adjacent_find: ������ ��� ���� ã��. ���⼭�� b�� a�� ���������� �ʴ� ���� ã��
    return std::adjacent_find(src.begin(), src.end(), [](int a, int b) { return b % a != 0; })
           == src.end();
}

// 9. Concatenating two integer vectors
// �� ���� ���� ���͸� �ϳ��� ��ġ�� �Լ�
auto concat(std::vector<int> const& ls, std::vector<int> const& rs) -> std::vector<int> {
    std::vector<int> result(ls);
    // - std::vector::insert: �ٸ� ������ ��Ҹ� ���� ������ ���� ����
    result.insert(result.end(), rs.begin(), rs.end());
    return result;
}

// 10. Check if a String Contains only Identical Characters
// ���ڿ� �� ��� ���ڰ� �������� Ȯ��
auto isIdentical(std::string const& src) -> bool {
    // - std::all_of: ������ ��� ��Ұ� �־��� ������ �����ϴ��� Ȯ��
    return std::all_of(src.begin(), src.end(), [&src](char c) { return c == src[0]; });
}

// 11. Hamming Distance
// Hamming Distance�� �� ���ڿ� ������ ���� �ٸ� ������ ������ �ǹ�
// �� ���ڿ� ������ �ع� �Ÿ��� ���
auto hammingDistance(std::string const& src0, std::string const& src1) -> int {
    // - std::transform_reduce: �� ������ ��Ҹ� �����ϰ� ��ȯ�Ͽ� ���� ���� ���
    return std::transform_reduce(
        src0.begin(), src0.end(), src1.begin(), 0, std::plus<>(),
        std::not_equal_to<char>());  // - std::not_equal_to: ��Ұ� ���� �ٸ��� Ȯ��
}

// 12. Count Instances of a Characters in a String
// �� ���� ���ڿ��� �޾Ƽ�, ù ��° ���ڿ��� �� ��° ���ڿ����� �ߺ� ���� (��ҹ��� ����)
auto charCount(char ch, std::string const& src) -> int {
    // - std::ranges::count: �������� Ư�� ���� ������ ��
    return std::ranges::count(src.begin(), src.end(), ch);
}

// 13. Mean of All Digits
// ��� �ڸ����� ��� ��ȯ (�׻� integer)
auto mean(int n) -> int {
    n = std::abs(n);
    // - std::to_string: ������ ���ڿ��� ��ȯ
    std::string digits = std::to_string(n);
    // - std::accumulate: �������� ��� ��Ҹ� �����Ͽ� ���� ���
    // ASCII ���� Ȱ���Ͽ� char�� int�� ����ȯ
    int sum = std::accumulate(digits.begin(), digits.end(), 0,
                              [](int sum, char c) { return sum + (c - '0'); });
    return sum / digits.size();
}
// 14. Double Letters
// ���� �ܾ ���ӵ� �� ���� ������ ���ڸ� ������ �ִ��� ���� �Ǻ�
auto doubleLetters(std::string const& src) -> bool {
    // - std::adjacent_find: ������ ��� ���� ã��
    return std::adjacent_find(src.begin(), src.end()) != src.end();
}

// 15. Minimum Removals to Make Sum Even
// ������ ��� ��ҵ��� ���� ¦���� ����� ���� �ʿ��� �ּ� ���� Ƚ��
// �̹� ���� ¦���� ��쿡�� 0�� ��ȯ
// Ȧ���� ��쿡�� idx �տ��� �ϳ��� ����鼭 Ȧ���� ����
auto minimumRemovals(std::vector<int> const& src) -> int {
    // - std::accumulate: �������� ��� ��Ҹ� �����Ͽ� ���� ���
    int sum = std::accumulate(src.begin(), src.end(), 0);
    if (sum % 2 == 0) return 0;

    int currentSum = sum;
    int removalCount = 0;

    // - std::ranges::find_if: ������ �����ϴ� ù ��° ��Ҹ� ã��
    auto foundIdx = std::ranges::find_if(src, [&](int n) {
        currentSum -= n;
        ++removalCount;
        return currentSum % 2 == 0;
    });

    return removalCount;
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

    // - std::sort: ������ ��Ҹ� ����
    std::sort(maurice.begin(), maurice.end());
    std::sort(steve.begin(), steve.end());

    // �� ���� �� ����� ���Ϳ� ����
    std::vector<bool> results = {
        maurice[0] > steve[2],  // Round 1: Maurice's slowest vs Steve's fastest
        maurice[1] > steve[0],  // Round 2: Maurice's middle vs Steve's slowest
        maurice[2] > steve[1]   // Round 3: Maurice's fastest vs Steve's middle
    };

    // - std::count: �������� Ư�� ������ �����ϴ� ����� ������ ��
    int mauriceWinsCount = std::count(results.begin(), results.end(), true);

    // Maurice�� ��� 2���� ���忡�� �̰���� Ȯ��
    return mauriceWinsCount >= 2;
}

// 17. Index Shuffle
// ���ڿ����� ¦�� �ε����� �ִ� ���ڵ�� Ȧ�� �ε����� �ִ� ���ڵ��� �����ͼ� �̵��� ����
auto indexShuffle(std::string const& src) -> std::string {
    std::string evenCharacters, oddCharacters;
    // - std::partition_copy: ������ �� ���� ������ �����Ͽ� ����
    // - std::back_inserter: ��Ҹ� �����̳��� ���� ������ �� �ִ� �ݺ��� ����
    std::partition_copy(src.begin(), src.end(), std::back_inserter(evenCharacters),
                        std::back_inserter(oddCharacters),
                        [index = 0](char) mutable { return index++ % 2 == 0; });

    return evenCharacters + oddCharacters;
}

// 18. Spelling it Out
// �־��� �ܾ ó������ �ϳ��� �߰��Ͽ� ������ �ܾ �����
auto spelling(std::string const& src) -> std::vector<std::string> {
    std::vector<std::string> result(src.size());
    // - std::ranges::generate: ������ ���� �Լ� ȣ���� ���� ���� ����
    // lambda: ���� �ε��������� �κ� ���ڿ��� ����
    // mutable: ���� �Լ��� ���ο��� length ������ ���� ������ �� �ֵ���
    // substr: ���ڿ��� �Ϻκ��� �����ϴ� ����
    std::ranges::generate(result, [&, length = 0]() mutable { return src.substr(0, ++length); });
    return result;
}

// 19. Factorize a Number
// �־��� ������ ��� ����� �����ϴ� ����
// �Է����� �־����� ������ ���
auto factorize(int n) -> std::vector<int> {
    std::vector<int> factors;
    // - std::ranges::for_each: ������ �� ��ҿ� ���� �Լ� ȣ��
    // - std::views::iota: ������ ������ ���� �������� ����
    // ������(sequence)�� �Ϸ��� ������� �迭�� ��ҵ��� �ǹ�
    // C++���� ������ ǥ��: ���� �⺻�����δ� �迭(array)�̳� ����(vector) ���� ���ӵ� �޸� ������
    // ��ҵ��� �����ϴ� ������ ������ �ְ�, �� �ܿ��� ����Ʈ(list), ��(map), ����(set) � ������
    // ������ ������ ��ҵ��� �������� �������� ����
    std::ranges::for_each(std::views::iota(1, n + 1), [&](int candidateFactor) {
        if (n % candidateFactor == 0) factors.push_back(candidateFactor);
    });
    return factors;
}
// 20. Find the Missing Number
// �־��� ���� ���Ϳ��� (1���� 10������ ���� �߿��� �ϳ��� ����) ������ ���ڸ� ã��
auto missingNum(std::vector<int> const& src) -> int {
    // - std::accumulate: �������� ��� ��Ҹ� �����Ͽ� ���� ���
    return 55 - std::accumulate(src.begin(), src.end(), 0);
}