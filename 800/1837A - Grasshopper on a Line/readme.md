# Day 18 | Codeforces: Split Into Non-Multiples of k

## Problem
Given two integers `x` and `k`, split `x` into the **minimum number of positive integers**
that sum to `x`, where **no number is divisible by `k`**.
If it is impossible, print `-1`.

> Problem link: <add Codeforces link here>

## Approach: Biggest Valid Number First
Think in cases:

| Case | Answer | Why |
|------|--------|-----|
| `x % k != 0` | `x` (1 number) | `x` itself is allowed |
| `x % k == 0` and `k > 1` | `x-1` and `1` (2 numbers) | `x-1` is not a multiple of `k`, and neither is `1` |
| `k == 1` | `-1` | Every number is divisible by 1 |

## Example
| x | k | Output |
|---|---|--------|
| 10 | 3 | `1` / `10` |
| 10 | 5 | `2` / `9 1` |
| 7 | 1 | `1` / `-1` |

## My Code
The solution in `solution.cpp` scans from 1 to `x` to find the largest number
not divisible by `k`, then looks for the partner that completes the sum.

## Complexity
- Time: O(x) per test case
- Space: O(1) (the answer never has more than 2 numbers)

## Optimization
The scan is not needed. The three cases above give the answer in **O(1)**:

```cpp
if (k == 1) cout << "1\n-1\n";
else if (x % k != 0) cout << "1\n" << x << "\n";
else cout << "2\n" << x - 1 << " 1\n";
```

## What I Learned
- Ask: "What is the largest valid piece I can take?" Then fix what's left.
- Divisibility problems often reduce to checking `x % k` and shifting by 1.
- Always handle the impossible case (`k = 1`) explicitly.
- My loop worked, but the math shows a simpler O(1) solution.

## Tags
`Codeforces` `Math` `Constructive` `Greedy` `C++`