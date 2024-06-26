---
marp: true
theme: gaia
class:
  - invert
paginate: true
---

### Problem #6

```c++
auto findIndex(std::vector<std::string> const & src,
               std::string const &              tgt) -> int
{
    return std::distance(src.cbegin(), std::ranges::find(src, tgt));
}
```

---

### Problem #7

```c++
auto divisible(std::vector<int> const & src) -> bool
{
    auto [prod, sum] =
        std::accumulate(src.cbegin(),
                        src.cend(),
                        std::pair{1, 0},
                        [](auto && s, auto && v) {
                            return std::pair{s.first * v, s.second + v};
                        });

    return prod % sum == 0;
}
```

---

### Problem #8

```c++
auto factorChain(std::vector<int> const & src) -> bool
{
    auto rst = std::transform_reduce(std::next(src.cbegin()),
                                     src.cend(),
                                     src.cbegin(),
                                     0,
                                     std::plus<>{},
                                     std::modulus<>{});

    return not static_cast<bool>(rst);
}
```

---

### Problem #9

- [What is the best way to concatenate two vectors](https://stackoverflow.com/questions/3177241/what-is-the-best-way-to-concatenate-two-vectors)
- [Concatenating two stdvectors](https://stackoverflow.com/questions/201718/concatenating-two-stdvectors)

```c++
auto concat(std::vector<int> const & ls,
            std::vector<int> const & rs) -> std::vector<int>
{
    std::vector<int> rst;
    rst.reserve(ls.size() + rs.size());
    rst.insert(rst.end(), ls.begin(), ls.end());
    rst.insert(rst.end(), rs.begin(), rs.end());

    return rst;
}
```

---

### Problem #10

```c++
auto isIdentical(std::string const & src) -> bool
{
    if (src.empty()) {
        return false;
    }

    // [alg.all.of] 2
    return std::all_of(std::next(src.cbegin()),
                       src.cend(),
                       [c0{src.front()}](auto c) { return c0 == c; });
}
```

---

### Problem #11

- [bool to int conversion](https://stackoverflow.com/questions/5369770/bool-to-int-conversion)

```c++
auto hammingDistance(std::string const & src0, std::string const & src1) -> int
{
    return std::transform_reduce(src0.cbegin(),
                                 src0.cend(),
                                 src1.cbegin(),
                                 0,
                                 std::plus<>{},
                                 [](auto c0, auto c1) {
                                     return static_cast<int>(c0 != c1);
                                 });
}
```

---

### Problem #12

```c++
auto charCount(char ch, std::string const & src) -> int
{
    return std::accumulate(src.cbegin(), src.cend(), 0, [ch](auto a, auto c) {
        return a + static_cast<int>(ch == c);
    });
}
```

---

### Problem #13

```c++
auto mean(int n) -> int
{
    auto const s = std::to_string(std::abs(n));

    auto [sum, len] = std::accumulate(s.cbegin(),
                                      s.cend(),
                                      std::pair{0, 0},
                                      [](auto && a, auto c) {
                                          a.first += c - '0';
                                          ++a.second;
                                          return a;
                                      });

    return static_cast<int>(static_cast<double>(sum) / len);
}
```

---

### Problem #14

```c++
auto doubleLetters(std::string const & src) -> bool
{
    auto rst = std::transform_reduce(std::next(src.cbegin()),
                                     src.cend(),
                                     src.cbegin(),
                                     0,
                                     std::plus<>{},
                                     [](auto c0, auto c1) {
                                         return static_cast<int>(c0 == c1);
                                     });

    return static_cast<bool>(rst);
}
```

---

### Problem #15

- [Difference between partial_sum and inclusive_scan](https://stackoverflow.com/questions/38006107/whats-the-difference-between-stdpartial-sum-and-stdinclusive-scan)
- [Converting a reverse iterator to a forward iterator](https://stackoverflow.com/questions/2037867/can-i-convert-a-reverse-iterator-to-a-forward-iterator)

```c++
auto minimumRemovals(std::vector<int> const & src) -> int
{
    std::vector<int> ps;
    ps.reserve(src.size());
    std::partial_sum(src.rbegin(), src.rend(), std::back_inserter(ps));

    auto found =
        std::find_if(ps.rbegin(), ps.rend(), [](auto v) { return v % 2 == 0; });

    return std::distance(found.base(), ps.end());
}
```

---

### Problem #16

- https://en.cppreference.com/w/cpp/algorithm/ranges/rotate

```c++
auto mauriceWins(std::vector<int> const & m, std::vector<int> const & s) -> bool
{
    auto s1{s};
    std::ranges::rotate(s1, std::prev(s1.end()));

    return std::transform_reduce(m.cbegin(),
                                 m.cend(),
                                 s1.cbegin(),
                                 0,
                                 std::plus<>{},
                                 [](auto vm, auto vs) {
                                     return static_cast<int>(vm > vs);
                                 }) >= 2;
}
```

---

### Problem #17

```c++
auto indexShuffle(std::string const & src) -> std::string
{
    auto [sEven, sOdd] =
        std::accumulate(src.cbegin(),
                        src.cend(),
                        std::pair{std::string{}, std::string{}},
                        [idx{0}](auto && p, auto c) mutable {
                            std::string const cs{c};
                            idx++ % 2 == 0 ? p.first += cs : p.second += cs;

                            return p;
                        });

    return sEven + sOdd;
}
```

---

### Problem #18

```c++
auto spelling(std::string const & src) -> std::vector<std::string>
{
    if (src.empty()) {
        return {};
    }

    std::vector<std::string> rst;
    rst.reserve(src.size());
    rst.emplace_back(std::string{src.front()});

    return std::accumulate(std::next(src.cbegin()),
                           src.cend(),
                           std::move(rst),
                           [](auto && a, auto v) {
                               a.emplace_back(a.back() + v);
                               return a;
                           });
}
```

---

### Problem #19

- [erase remove_if idiom](https://stackoverflow.com/questions/39019806/using-erase-remove-if-idiom)

```c++
auto factorize(int n) -> std::vector<int>
{
    std::vector<int> rst(n);
    std::iota(rst.begin(), rst.end(), 1);

    rst.erase(std::remove_if(rst.begin(),
                             rst.end(),
                             [n](auto && v) { return n % v != 0; }),
              rst.end());

    return rst;
}
```

---

### Problem #20

```c++
auto missingNum(std::vector<int> const & src) -> int
{
    return 55 - std::accumulate(src.cbegin(), src.cend(), 0);
}
```