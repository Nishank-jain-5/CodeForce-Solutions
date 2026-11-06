# Day 22 | Codeforces: A. Coins

## Problem
There are two coin types: denomination `2` and denomination `k`.
Decide whether `n` burles can be paid exactly, i.e. whether there are
non-negative integers `x`, `y` with `2*x + k*y = n`.

Constraints: `1 <= k <= n <= 10^18`, `k != 2`.

> Problem link: <add Codeforces link here>

## Approach: Think in Parity
Only whether numbers are even or odd matters.

| Case | Answer | Why |
|------|--------|-----|
| `n` is even | YES | Use `n / 2` coins of 2 |
| `n` is odd and `k` is odd | YES | Use one `k`, then `(n - k) / 2` coins of 2 |
| `n` is odd and `k` is even | NO | Every coin is even, so the sum can never be odd |

Since `k <= n`, the value `n - k` is never negative, so using one `k` coin is always possible.

```cpp
if (n % 2 == 0 || (n - k) % 2 == 0) cout << "YES";
else cout << "NO";
```

## Example
| n | k | Output | Why |
|---|---|--------|-----|
| 5 | 3 | YES | 2 + 3 |
| 6 | 1 | YES | three 2s |
| 7 | 4 | NO | n odd, k even |
| 8 | 8 | YES | one 8 |

## Complexity
- Time: O(1) per test case
- Space: O(1)

## Optimization
`(n - k) % 2 == 0` with odd `n` simply means `k` is odd, so this is equivalent:

```cpp
if (n % 2 == 0 || k % 2 == 1) cout << "YES\n";
else cout << "NO\n";
```

## What I Learned
- When coins are fixed, think about parity (even/odd) before trying any brute force.
- Even + even is always even, so an odd target needs an odd coin.
- Use `long long` because `n` goes up to 10^18.
- With `n` this large, a loop is impossible, so the answer must be a formula.

## Tags
`Codeforces` `Math` `Number Theory` `Parity` `C++`