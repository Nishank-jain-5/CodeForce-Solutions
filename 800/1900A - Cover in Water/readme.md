# Codeforces 1900A: Cover in Water

![Difficulty](https://img.shields.io/badge/Rating-800-brightgreen)
![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)
![Topic](https://img.shields.io/badge/Topic-Greedy%20%2F%20Strings-orange)

**Problem Link:** [Codeforces 1900A](https://codeforces.com/problemset/problem/1900/A)
**Time Limit:** 1 second | **Memory Limit:** 256 MB

---

## Problem Summary

Filip has a row of `n` cells. Some cells are **empty** (`.`) and some are **blocked** (`#`). He wants **every empty cell** to have water.

He has two actions:

- **Action 1:** Place water in an empty cell.
- **Action 2:** Take water from one cell and move it to any other empty cell.

There is also one **special rule**:

> If an empty cell has water in **both** its left neighbor and its right neighbor, it fills with water **by itself**.

**Task:** Find the **minimum number of times Action 1 is needed**. (Action 2 can be used as many times as you like.)

### Input
- `t`: number of test cases
- For each test case:
  - `n`: number of cells
  - `s`: a string of length `n` made of `.` and `#`

### Output
For each test case, print the minimum number of Action 1.

### Example

```
Input
5
3
...
7
##....#
7
..#.#..
4
####
10
#...#..#.#

Output
2
2
5
0
2
```

---

## Key Observation

The whole problem depends on **one question**:

> Is there a place with **three empty cells in a row** (`...`)?

### Case 1: There is a `...` somewhere

The answer is **always 2**.

Why?
1. Take three empty cells in a row. Put water in the **first** and the **third**. The middle one fills by itself.
2. Now we have 2 water sources. We can **move** water using Action 2 (it is free).
3. Move the water from the end cell to the next empty cell. The cell we just left is now between two waters, so it fills by itself.
4. Keep doing this, and we can cover **every** empty cell in the row, even in other parts of the row (Action 2 can place water in **any** empty cell).

So 2 waters are enough for everything. And 1 water is not enough when there are 3 or more connected empty cells, so the answer is exactly 2.

### Case 2: There is NO `...`

Then every group of empty cells has **length 1 or 2**. The self-fill rule needs an empty cell with water on both sides, but with groups this small, no cell can get water from its neighbors.

So **every empty cell needs its own water**.

**Answer = number of `.` in the string.**

---

## Quick Rule

| Situation | Answer |
|-----------|--------|
| String contains `...` | `2` |
| String does not contain `...` | count of `.` |

---

## Dry Run

**Test 2:** `##....#`

```
There is "..." (cells 3, 4, 5) -> Answer = 2
```

**Test 3:** `..#.#..`

```
Groups of empty cells: ".." , "." , ".."
No "..." anywhere
Count of '.' = 5 -> Answer = 5
```

**Test 4:** `####`

```
No empty cells -> Answer = 0
```

**Test 5:** `#...#..#.#`

```
There is "..." at the start -> Answer = 2
```

---

## My Approach

### Idea
Walk through the string from left to right and count empty cells. If I ever find **three empty cells in a row**, I stop and the answer is **2**.

1. Skip every `#`.
2. If the current cell and the next two cells are all `.`, set `cnt = 2` and **break**.
3. Otherwise, add `1` to `cnt` for this empty cell.
4. Print `cnt`.

### Complexity
- **Time:** `O(n)` per test case (one pass over the string)
- **Space:** `O(1)` extra space (apart from the string)

---

## Shorter Version (Same Idea)

C++ can search for `"..."` directly:

```cpp
if(s.find("...") != string::npos) cout << 2 << "\n";
else cout << count(s.begin(), s.end(), '.') << "\n";
```

(Add `#include <algorithm>` for `count`.)

| | My Code | Shorter Code |
|---|---|---|
| Idea | Count while walking, break on `...` | Use `find` and `count` |
| Time | `O(n)` | `O(n)` |
| Space | `O(1)` | `O(1)` |
| Readability | Shows the logic step by step | Very short |

Both are correct.

---

## Edge Cases to Remember

- **No empty cells** (`####`): answer is `0`.
- **Only one empty cell**: answer is `1`.
- **Only `..`** (two empty cells in a row): no triple, so answer is `2` (the count of dots).
- **`...` in the middle of the string**: the answer is still `2`, because water can be moved anywhere.
- **Empty cells separated by `#`** (like `.#.#.`): they are not connected, so there is no triple. The answer is the count of dots.
- When a triple is found, **set** `cnt = 2` (do not add to it). The cells counted earlier are no longer needed.

---

## What I Learned

- Sometimes the answer is just **two simple cases**. Look for the one condition that splits them.
- A free action (Action 2) can make a hard problem easy. Ask: "What can I do for free?"
- Check small patterns (like `...`) before thinking about big solutions.
- Moving a resource around can replace buying more of it. 2 waters can cover a whole row!

---

## Tags
`greedy` `strings` `implementation` `constructive` `800-rating`

---

*Part of my daily DSA / Codeforces journey. One problem at a time. One concept at a time.* 🚀
