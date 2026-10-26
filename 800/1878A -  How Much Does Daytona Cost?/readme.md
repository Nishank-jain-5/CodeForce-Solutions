# Codeforces 1878A: How Much Does Daytona Cost?

![Difficulty](https://img.shields.io/badge/Rating-800-brightgreen)
![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)
![Topic](https://img.shields.io/badge/Topic-Observation%20%2F%20Implementation-orange)

**Problem Link:** [Codeforces 1878A](https://codeforces.com/problemset/problem/1878/A)
**Time Limit:** 1 second | **Memory Limit:** 256 MB

---

## Problem Summary

We say an integer is the **most common** in a subsegment if it appears **more times** than **every other** integer in that subsegment.

A **subsegment** is a continuous part of the array.

You are given an array `a` of size `n` and a number `k`.

**Task:** Tell whether there is a **non-empty subsegment** in which `k` is the most common element.

### Input
- `t`: number of test cases
- For each test case:
  - `n k`: size of the array and the number `k` (`1 <= n <= 100`, `1 <= k <= 100`)
  - `a1 a2 ... an`: the array (`1 <= ai <= 100`)

### Output
For each test case, print `YES` if such a subsegment exists, otherwise print `NO`.

### Example

```
Input
7
5 4
1 4 3 4 1
4 1
2 3 4 4
5 6
43 5 60 4 2
2 5
1 5
4 1
5 3 3 1
1 3
3
5 3
3 4 1 5 5

Output
YES
NO
NO
YES
YES
YES
YES
```

---

## Key Observation

The problem sounds hard, but the answer depends on **one simple question**:

> Is the number `k` present in the array at all?

### Case 1: `k` is in the array -> YES

Pick a subsegment of **length 1** that contains only `k`.

```
[k]
```

In this subsegment, `k` appears **1 time** and **no other number appears** (they appear 0 times). Since `1 > 0`, `k` is the most common. So the answer is **YES**.

We do not need long subsegments at all.

### Case 2: `k` is NOT in the array -> NO

Then `k` appears **0 times** in every subsegment. For `k` to be the most common, it must appear more times than other numbers, but `0` is never larger than the count of another number (the subsegment is non-empty, so some other number appears at least once). So the answer is **NO**.

---

## Quick Rule

| Situation | Answer |
|-----------|--------|
| `k` appears in the array | `YES` |
| `k` does not appear in the array | `NO` |

---

## Dry Run

```
n=5, k=4, [1, 4, 3, 4, 1]   -> 4 is present                -> YES
n=4, k=1, [2, 3, 4, 4]      -> 1 is not present            -> NO
n=5, k=6, [43, 5, 60, 4, 2] -> 6 is not present            -> NO
n=2, k=5, [1, 5]            -> 5 is present                -> YES
n=4, k=1, [5, 3, 3, 1]      -> 1 is present                -> YES
n=1, k=3, [3]               -> 3 is present                -> YES
n=5, k=3, [3, 4, 1, 5, 5]   -> 3 is present                -> YES
```

---

## My Approach

### Idea
Just search for `k` in the array.

1. Read the array.
2. Loop through all elements.
3. If any element is equal to `k`, print `YES` and stop.
4. If the loop finishes without finding it, print `NO`.

### Complexity
- **Time:** `O(n)` per test case
- **Space:** `O(n)` for the vector

---

## Shorter Version (Same Idea)

C++ has a ready-made function to search in an array:

```cpp
#include <algorithm>

if(find(v.begin(), v.end(), k) != v.end()) cout << "YES\n";
else cout << "NO\n";
```

We can also skip storing the array. Just remember if we have seen `k`:

```cpp
bool found = false;
for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    if(x == k) found = true;
}
cout << (found ? "YES" : "NO") << "\n";
```

| | My Code | No-Array Version |
|---|---|---|
| Idea | Store the array, then search | Check while reading |
| Time | `O(n)` | `O(n)` |
| Space | `O(n)` | `O(1)` |
| Readability | Very clear | Short and clean |

Both are correct.

---

## Edge Cases to Remember

- **`n = 1` and the element is `k`** (like `[3]`, `k = 3`): `YES`.
- **`n = 1` and the element is not `k`**: `NO`.
- **`k` appears only once among many other numbers** (like `[5, 3, 3, 1]`, `k = 1`): still `YES`, because we can pick just `[1]`.
- **`k` is not present at all:** always `NO`.
- If you stop reading early (after `break`), you must have already read the **whole array** first. In my code, the array is read fully before searching, so this is safe.

---

## What I Learned

- Do not be scared by a long definition. Look for the **smallest** example that satisfies it (here, a subsegment of length 1).
- Always try the **smallest subsegment** first. It can make the problem very easy.
- A problem about "most common element" does not always need counting or frequency maps.
- Read the problem name for fun, but read the **statement** for the logic (the Daytona car has nothing to do with the solution!).

---

## Tags
`greedy` `implementation` `observation` `800-rating`

---

*Part of my daily DSA / Codeforces journey. One problem at a time. One concept at a time.* 🚀
