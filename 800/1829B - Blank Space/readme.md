# Day 21 | Codeforces: B. Blank Space

## Problem
You are given a binary array `a` of `n` elements (only 0s and 1s).
A **blank space** is a segment of consecutive elements that are all `0`.
Find the length of the **longest blank space**.

> Problem link: <add Codeforces link here>

## Approach: Count Each Run of Zeros
Scan the array from left to right.
- When I find a `0`, I keep moving forward while the elements are `0` and count them.
- When the run ends, I compare it with the best answer so far (`maxi`) and reset the counter.
- If there are no zeros at all, the answer stays `0`.

```cpp
for (int i = 0; i < n; i++) {
    if (v[i] == 0) {
        while (i < n && !v[i]) {
            cnt++;
            i++;
        }
        maxi = max(maxi, cnt);
        cnt = 0;
    }
}
```

## Example
| Array | Output | Why |
|-------|--------|-----|
| `1 0 0 1 0` | 2 | Runs of zeros: 2 and 1 |
| `0 1 1 1` | 1 | Only one zero |
| `1 1 1` | 0 | No zeros |
| `1 0 0 0 1 0 0 0 1` | 3 | Two runs of 3 |

## Complexity
- Time: O(n) per test case (each element is visited once)
- Space: O(n) (O(1) if you don't store the array)

## Optimization
A single loop with one counter does the same job without the nested `while`:

```cpp
int maxi = 0, cnt = 0;
for (int i = 0; i < n; i++) {
    int x; cin >> x;
    if (x == 0) cnt++;
    else cnt = 0;
    maxi = max(maxi, cnt);
}
```

## What I Learned
- For "longest consecutive segment" problems, count the current run and keep the best so far.
- Reset the counter when the run breaks.
- Start `maxi` at 0 so the "no zeros" case is handled automatically.
- Moving `i` inside a `while` works, but a single counter is simpler and less error-prone.

## Tags
`Codeforces` `Implementation` `Arrays` `Two Pointers` `C++`