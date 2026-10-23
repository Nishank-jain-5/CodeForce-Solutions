# Codeforces 1896A: Jagged Swaps

![Difficulty](https://img.shields.io/badge/Rating-800-brightgreen)
![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)
![Topic](https://img.shields.io/badge/Topic-Observation%20%2F%20Sortings-orange)

**Problem Link:** [Codeforces 1896A](https://codeforces.com/problemset/problem/1896/A)
**Time Limit:** 1 second | **Memory Limit:** 256 MB

---

## Problem Summary

You are given a **permutation** `a` of size `n` (numbers `1` to `n`, each used exactly once, in any order).

You can do this operation as many times as you want:

- Pick an index `i` from `2` to `n-1` such that `a[i-1] < a[i]` and `a[i] > a[i+1]` (so `a[i]` is bigger than both neighbors).
- **Swap** `a[i]` and `a[i+1]`.

**Task:** Tell whether it is possible to **sort** the permutation (make it `1, 2, 3, ..., n`).

### Input
- `t`: number of test cases
- For each test case:
  - `n`: size of the permutation (`3 <= n <= 10`)
  - `a1 a2 ... an`: the permutation

### Output
For each test case, print `YES` if it can be sorted, otherwise print `NO`.

### Example

```
Input
6
3
1 2 3
5
1 3 2 5 4
5
5 4 3 2 1
3
3 1 2
4
2 3 1 4
5
5 1 2 3 4

Output
YES
YES
NO
NO
NO
NO
```

---

## Key Observation

Look at **which positions can change**.

The index `i` must be between `2` and `n-1`, and the swap touches positions `i` and `i+1`. So:

- Position `1` is **never touched**. `i` starts from 2, so `a[1]` is never swapped with anything.

That means **the first element can never change**.

In a sorted array, the first element must be `1`. So:

> If `a[1] != 1`, the answer is **NO**.

### What if `a[1] == 1`?

Then the answer is always **YES**. Here is why:

1. If the array is not sorted, there is some place where `a[j] > a[j+1]` (a "descent"). Take the **first** such place.
2. Since `a[1] = 1` is the smallest number, this `j` cannot be 1, so `j >= 2`.
3. Because `j` is the first descent, everything before it is increasing, so `a[j-1] < a[j]`.
4. Also `a[j] > a[j+1]`. So the operation is **allowed** at index `j`.
5. Swapping `a[j]` and `a[j+1]` fixes exactly **one** wrong pair (it reduces the number of inversions by 1).
6. The number of wrong pairs is finite, so after some swaps the array becomes sorted.

So we can always finish. No simulation is needed.

---

## Quick Rule

| Situation | Answer |
|-----------|--------|
| `a[1] == 1` | `YES` |
| `a[1] != 1` | `NO` |

---

## Dry Run

```
[1, 2, 3]        -> first is 1 -> YES (already sorted)
[1, 3, 2, 5, 4]  -> first is 1 -> YES
[5, 4, 3, 2, 1]  -> first is 5 -> NO
[3, 1, 2]        -> first is 3 -> NO
[2, 3, 1, 4]     -> first is 2 -> NO
[5, 1, 2, 3, 4]  -> first is 5 -> NO
```

**Test 2 in detail:** `[1, 3, 2, 5, 4]`

```
i = 2: 1 < 3 and 3 > 2 -> swap -> [1, 2, 3, 5, 4]
i = 4: 3 < 5 and 5 > 4 -> swap -> [1, 2, 3, 4, 5]  Sorted!
```

---

## My Approach

### Idea
Only the first element matters. If it is `1`, print `YES`. Otherwise print `NO`.

1. Read the permutation.
2. Check `v[0] == 1`.
3. Print the answer.

### Complexity
- **Time:** `O(n)` per test case (only to read the input)
- **Space:** `O(n)` for the vector

---

## Shorter Version (Same Idea)

We do not need to store the array. We only need the first number, but we still have to **read** all numbers:

```cpp
int first, x;
cin >> first;
for(int i = 1; i < n; i++) cin >> x;   // read and ignore the rest
cout << (first == 1 ? "YES" : "NO") << "\n";
```

| | My Code | Shorter Code |
|---|---|---|
| Idea | Store all, check `v[0]` | Read all, keep only the first |
| Time | `O(n)` | `O(n)` |
| Space | `O(n)` | `O(1)` |
| Readability | Clear and simple | Slightly less clear |

Both are correct. (Note: `<algorithm>` is not needed in my code.)

---

## Edge Cases to Remember

- **Already sorted** (`1 2 3 ...`): first element is 1, so `YES`.
- **First element is the largest** (`n ... `): `NO`.
- **First element is 1 but the rest is fully reversed** (like `1 5 4 3 2`): still `YES`.
- **Always read the full array** before the next test case, even when the answer is already known. Otherwise the input gets mixed up.
- `n >= 3` here, so there is always at least one valid index range.

---

## What I Learned

- Ask: "Which element can **never move**?" It can give the answer very fast.
- When an operation has a limit (like `i` from 2 to `n-1`), check what it does **not** touch.
- A swap that fixes one wrong pair at a time always finishes, so we only need to prove it **can** start.
- The sample tests are small, but the real idea is a proof. Do not just guess a pattern, ask "why?"

---

## Tags
`brute force` `math` `observation` `sortings` `800-rating`

---

*Part of my daily DSA / Codeforces journey. One problem at a time. One concept at a time.* 🚀
