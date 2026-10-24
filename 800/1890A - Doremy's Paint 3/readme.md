# Codeforces 1890A: Doremy's Paint 3

![Difficulty](https://img.shields.io/badge/Rating-800-brightgreen)
![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)
![Topic](https://img.shields.io/badge/Topic-Math%20%2F%20Hashing-orange)

**Problem Link:** [Codeforces 1890A](https://codeforces.com/problemset/problem/1890/A)
**Time Limit:** 1 second | **Memory Limit:** 256 MB

---

## Problem Summary

An array `b` is called **good** if the sum of every two **neighbor** elements is the **same** value.

That is: `b1 + b2 = b2 + b3 = ... = b(n-1) + bn = k` for some `k`.

You are given an array `a` of length `n`. You can **change the order** of its elements (permute) in any way.

**Task:** Tell whether it is possible to make the array good.

### Input
- `t`: number of test cases
- For each test case:
  - `n`: length of the array (`2 <= n <= 100`)
  - `a1 a2 ... an`: the array (`1 <= ai <= 10^5`)

### Output
For each test case, print `Yes` if the array can be made good, otherwise print `No`.

### Example

```
Input
5
2
8 9
3
1 1 2
4
1 1 4 5
5
2 3 3 3 3
4
100000 100000 100000 100000

Output
Yes
Yes
No
No
Yes
```

---

## Key Observation

Take two neighbor sums that must be equal:

```
b1 + b2 = b2 + b3
```

Remove `b2` from both sides:

```
b1 = b3
```

The same works for every step, so:

> `b1 = b3 = b5 = ...` and `b2 = b4 = b6 = ...`

So a good array always looks like this:

```
x, y, x, y, x, y, ...
```

Only **two different values** can appear, and they **alternate**.

### What does this mean for our counts?

| Distinct values in the array | Result |
|------------------------------|--------|
| 1 (all numbers are same) | **Yes** (like `5 5 5 5`) |
| 2 | Maybe. Check the counts (see below) |
| 3 or more | **No** |

### The two-value case

In `x, y, x, y, ...` the two values take turns, so their counts can differ by **at most 1**:

- If `n` is even, both appear `n/2` times (counts are equal).
- If `n` is odd, one appears `(n+1)/2` times and the other `(n-1)/2` times (counts differ by 1).

So with exactly 2 values, the answer is **Yes** only if:

```
|count of x - count of y| <= 1
```

---

## Dry Run

```
[8, 9]                    -> 2 values, counts 1 and 1 (diff 0)  -> Yes   ([8,9])
[1, 1, 2]                 -> 2 values, counts 2 and 1 (diff 1)  -> Yes   ([1,2,1])
[1, 1, 4, 5]              -> 3 values                           -> No
[2, 3, 3, 3, 3]           -> 2 values, counts 1 and 4 (diff 3)  -> No
[100000 x4]               -> 1 value                            -> Yes
```

---

## My Approach

### Idea
Count how many times each number appears (using a map), then use the rules above.

1. Store the frequency of every number in an `unordered_map`.
2. If there are **more than 2** different numbers, print `NO`.
3. If there is **only 1** different number, print `YES`.
4. If there are **exactly 2**, take their two counts. If they are equal or differ by 1, print `YES`, else print `NO`.

### Complexity
- **Time:** `O(n)` per test case (average, for hash map operations)
- **Space:** `O(n)` for the map (at most `n` different values)

---

## Another Way (Sorting)

If we sort the array, equal numbers come together. Then we can check the pattern without a map:

```cpp
sort(a.begin(), a.end());
// count distinct values and the size of the first group
```

Also, the long `if` condition can be shorter:

```cpp
if(abs(v[0] - v[1]) <= 1) cout << "YES\n";
else cout << "NO\n";
```

| | My Code | Sorting Idea |
|---|---|---|
| Idea | Count frequency with a map | Sort and count groups |
| Time | `O(n)` average | `O(n log n)` |
| Space | `O(n)` | `O(1)` extra |
| Readability | Very clear | Needs more care |

Both are fine here because `n <= 100`.

---

## Edge Cases to Remember

- **All elements same** (`7 7 7`): always `Yes`.
- **`n = 2` with different numbers** (`8 9`): `Yes`, because `[8, 9]` has only one neighbor sum.
- **`n = 2` with same numbers** (`4 4`): `Yes` (one value).
- **Two values but very different counts** (`2 3 3 3 3`): `No`.
- **Three or more distinct values**: always `No`, no matter the counts.
- The difference rule is `<= 1`, not `== 1`. Equal counts are also fine (like `1 1 2 2`).

---

## What I Learned

- Remove the common part from both sides of an equation. `b1 + b2 = b2 + b3` simply becomes `b1 = b3`.
- A rule like "all neighbor sums are equal" can hide a simple pattern: **alternating values**.
- When order does not matter (we can permute), think about **frequency counts**, not positions.
- Writing the pattern down (`x, y, x, y...`) made the counting rule easy to see.

---

## Tags
`math` `hashing` `constructive` `implementation` `800-rating`

---

*Part of my daily DSA / Codeforces journey. One problem at a time. One concept at a time.* 🚀
