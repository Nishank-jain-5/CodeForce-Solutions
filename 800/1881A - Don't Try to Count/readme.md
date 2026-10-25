# Codeforces 1881A: Don't Try to Count

![Difficulty](https://img.shields.io/badge/Rating-800-brightgreen)
![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)
![Topic](https://img.shields.io/badge/Topic-Strings%20%2F%20Brute%20Force-orange)

**Problem Link:** [Codeforces 1881A](https://codeforces.com/problemset/problem/1881/A)
**Time Limit:** 2 seconds | **Memory Limit:** 256 MB

---

## Problem Summary

You are given two strings:

- `x` of length `n`
- `s` of length `m`

and it is guaranteed that `n * m <= 25` (so the strings are very small).

In **one operation**, you take the current `x` and **append it to itself**.

```
"aba" -> "abaaba" -> "abaabaabaaba" -> ...
```

**Task:** Find the **minimum number of operations** after which `s` appears inside `x` as a **substring**. If it can never appear, print `-1`.

### Input
- `t`: number of test cases
- For each test case:
  - `n m`: lengths of `x` and `s`
  - `x`: the first string
  - `s`: the second string

### Output
For each test case, print the minimum number of operations, or `-1` if it is impossible.

### Example (first 6 tests)

```
Input
6
1 5
a
aaaaa
5 5
eforc
force
2 5
ab
ababa
3 5
aba
ababa
4 3
babb
bbb
5 1
aaaaa
a

Output
3
1
2
-1
1
0
```

---

## Key Observation

The title says "Don't Try to Count". That is the hint: **do not do clever math, just simulate**. The input is tiny, so we can actually build the string.

### Idea 1: Try operation by operation
After each operation `x` becomes double in length. After `k` operations:

```
x becomes (original x) repeated 2^k times
```

So we can just double `x` and check with `find()` each time.

### Idea 2: When should we stop?

We cannot loop forever, so we need a limit.

- The final string is just the original `x` repeated again and again.
- If `s` ever appears, it starts somewhere inside the **first `n` characters** (because after that, the pattern repeats).
- So we only need the string to be at least about `n + m` characters long.

This means we need `2^k * n >= n + m`.

Now use the rule `n * m <= 25`. The **worst case** is `n = 1` and `m = 25`:

```
x = "a", s = 25 letters  ->  need length >= 25  ->  2^5 = 32 >= 25
```

So **at most 5 operations** are ever needed.

> If `s` is not found after 5 operations, it will **never** be found. Print `-1`.

(Check from the example: the last test has `n = 1`, `m = 19` and the answer is `5`. This is the largest answer.)

---

## Dry Run

**Test 2:** `x = "eforc"`, `s = "force"`

```
x.find("force") ? -> not found
Operation 1: x = "eforceforc"
x.find("force") ? -> found!  -> Answer = 1
```

**Test 3:** `x = "ab"`, `s = "ababa"`

```
Operation 0: "ab"        -> not found
Operation 1: "abab"       -> not found (length 4 < 5)
Operation 2: "abababab"   -> contains "ababa" -> Answer = 2
```

**Test 4:** `x = "aba"`, `s = "ababa"`

```
After 5 operations the string is "aba" repeated 32 times
It looks like: abaabaabaaba...
"ababa" never appears (there is always "aa" between the "aba" blocks)
Answer = -1
```

**Test 6:** `x = "aaaaa"`, `s = "a"`

```
x.find("a") -> found at the start -> Answer = 0
```

---

## My Approach

### Idea
Simulate the operations. Check first, then double and check again.

1. If `s` is already inside `x`, print `0`.
2. Otherwise, double `x` (`x += x`) and increase the counter.
3. After each doubling, check if `s` is inside `x`. If yes, print the counter.
4. If it is still not found after 5 doublings, print `-1`.

### Complexity
- Each test does at most 5 doublings. After 5 doublings the string has length at most `32 * n`.
- **Time:** `O(32 * n * m)` per test case, which is a tiny constant because `n * m <= 25`
- **Space:** `O(32 * n)`

---

## Cleaner Version (Same Idea)

The loop only needs the counter. A simple `for` loop makes it easier to read:

| | My Code | Cleaner Code |
|---|---|---|
| Idea | Check, then double up to 5 times | Same idea in a `for` loop |
| Time | `O(32 * n * m)` | `O(32 * n * m)` |
| Space | `O(32 * n)` | `O(32 * n)` |
| Readability | Works, but the loop condition is tricky | Easy to follow |

Note about my loop condition `while(n <= m || i != 0)`: because `n` doubles 5 times, `n` becomes at least `32`, which is always bigger than `m` (`m <= 25`). So the loop effectively stops after exactly 5 rounds, and the `n <= m` part never changes the result.

---

## Edge Cases to Remember

- **`s` is already in `x`:** answer is `0`. Check this **before** doing any operation.
- **`s` is longer than `x`:** we must double until the string is long enough (example: `x = "a"`, `s = "aaaaa"` needs 3 operations).
- **Impossible case:** answer is `-1` (example: `x = "aba"`, `s = "ababa"`).
- **Worst case is `n = 1`, `m = 25`:** needs 5 operations. This is why 5 is the safe limit.
- **Use `find`:** `x.find(s) != -1` (or `!= string::npos`) means "found".
- Do not forget to print the answer only **once** per test case.

---

## What I Learned

- When the constraints are tiny (`n * m <= 25`), **simulation is the answer**. "Don't try to count" really means "just try it".
- Always ask: "How many steps are enough?" Here, `2^5 = 32` already covers the worst case.
- A repeating string only needs to be checked for a limited length. After that, it is the same pattern again.
- Strings in C++ make this easy: `+=` to build and `find` to search.

---

## Tags
`brute force` `strings` `implementation` `800-rating`

---

*Part of my daily DSA / Codeforces journey. One problem at a time. One concept at a time.* 🚀
