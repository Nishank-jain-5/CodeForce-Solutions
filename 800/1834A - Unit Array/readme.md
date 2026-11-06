# Day 19 | Codeforces: A. Unit Array

## Problem
You are given an array `a` of length `n` where every element is `-1` or `1`.
The array is **good** if:
- the sum of all elements is `>= 0`, and
- the product of all elements is `1`.

In one operation you can flip any element (`-1 -> 1` or `1 -> -1`).
Find the **minimum number of operations** to make the array good.

> Problem link: <add Codeforces link here>

## Approach: Count the Minus Ones
Only the number of `-1`s matters, so count `plus` (number of 1s) and `minus` (number of -1s).

| Condition | What it needs |
|-----------|---------------|
| Product = 1 | `minus` must be **even** |
| Sum >= 0 | `plus >= minus` |

Flipping a `-1` to `1` does two things at once: it lowers `minus` by 1 and raises `plus` by 1.
So we flip one `-1` at a time until both conditions hold.

```cpp
while (plus < minus || minus % 2 == 1) {
    plus++;
    minus--;
    cnt++;
}
```

## Example
| Array | Output | Why |
|-------|--------|-----|
| `-1 -1 1 -1` | 1 | Flip one `-1`: minus = 2 (even), plus = 2 |
| `-1 -1 -1 1 1` | 1 | Flip one `-1`: minus = 2, plus = 3 |
| `-1 1 -1 1` | 0 | Already good |
| `-1 -1 -1` | 3 | Flip all: minus = 0, plus = 3 |
| `-1` | 1 | Flip it: minus = 0 |

## Complexity
- Time: O(n) per test case
- Space: O(n) (O(1) if you don't store the array)

## Optimization
The final `minus` is the largest **even** number that is at most `min(minus, n/2)`.
The answer is the difference, so no loop is needed:

```cpp
int lim = min(minus, n / 2);
if (lim % 2 == 1) lim--;
cout << minus - lim << "\n";
```

## What I Learned
- Turn the conditions into counts: product = 1 means an even number of `-1`s, sum >= 0 means `plus >= minus`.
- One flip can fix both conditions at once, so a simple greedy loop works.
- Only the counts matter, not the positions.
- A `while` loop with two conditions is clean for "keep fixing until valid" problems.

## Tags
`Codeforces` `Math` `Greedy` `Implementation` `C++`