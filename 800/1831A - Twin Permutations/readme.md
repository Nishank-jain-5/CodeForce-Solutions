# Day 20 | Codeforces 1831A: Twin Permutations

## Problem
You are given a permutation `a` of length `n`.
Find **any** permutation `b` of length `n` such that:

`a1 + b1 <= a2 + b2 <= a3 + b3 <= ... <= an + bn`

It is guaranteed that such a `b` always exists.

> Problem link: https://codeforces.com/problemset/problem/1831/A

## Approach: Make Every Sum Equal
A sequence where all values are **equal** is always non-decreasing.
So I make every `a[i] + b[i]` the same number.

Choose:

```
b[i] = n + 1 - a[i]
```

Then `a[i] + b[i] = n + 1` for every `i`.

Why `b` is a valid permutation: `a` has every number from 1 to n exactly once,
so `n + 1 - a[i]` also covers every number from 1 to n exactly once.
It just mirrors the values (1 <-> n, 2 <-> n-1, ...).

## Example
| a | b | Sums |
|---|---|------|
| `1 2 4 5 3` | `5 4 2 1 3` | 6 6 6 6 6 |
| `1 2` | `2 1` | 3 3 |
| `3 2 1` | `1 2 3` | 4 4 4 |
| `1 4 3 2` | `4 1 2 3` | 5 5 5 5 |

The output differs from the sample, but any valid answer is accepted.

## My Code
```cpp
for (int i = 0; i < n; i++) {
    ans[i] = n - v[i] + 1;
}
```

## Complexity
- Time: O(n) per test case
- Space: O(n)

## What I Learned
- Ask: "What is the simplest way to make a chain of inequalities true?" Make all sums equal.
- Mirroring a permutation with `n + 1 - x` gives another valid permutation.
- Constructive problems often have a simple pattern, so don't overthink them.
- The condition looks hard, but one constant sum removes the whole problem.

## Tags
`Codeforces` `Constructive` `Math` `Permutation` `C++`