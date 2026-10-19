# Codeforces 1901A: Line Trip

![Difficulty](https://img.shields.io/badge/Rating-800-brightgreen)
![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)
![Topic](https://img.shields.io/badge/Topic-Greedy%20%2F%20Math-orange)

**Problem Link:** [Codeforces 1901A](https://codeforces.com/problemset/problem/1901/A)
**Time Limit:** 2 seconds | **Memory Limit:** 256 MB

---

## Problem Summary

You are standing at point `0` on a number line. You want to drive to point `x` and then come back to `0`.

- The car uses **1 liter of fuel per 1 unit** of distance.
- You start with a **full tank**.
- There are `n` gas stations at positions `a1, a2, ..., an`.
- At every station the tank is **fully refilled**.
- There is **no station at 0 or at x**.

**Task:** Find the **minimum tank capacity** that lets you complete the full round trip (`0 -> x -> 0`).

### Input
- `t`: number of test cases
- For each test case:
  - `n x`: number of stations and the destination
  - `a1 a2 ... an`: station positions (sorted, strictly between `0` and `x`)

### Output
For each test case, print the minimum tank volume.

### Example

```
Input
3
3 7
1 2 5
3 6
1 2 5
1 10
7

Output
4
3
7
```

---

## Key Observation

Because the tank is refilled **completely** at every station, the total distance does not matter. What matters is the **longest stretch you must drive without refueling**. The tank must be at least as big as that stretch.

The journey breaks into these parts:

| Part | Distance needed |
|------|-----------------|
| Start `0` -> first station | `a1 - 0` |
| Station `i` -> station `i+1` | `a[i+1] - a[i]` |
| Last station -> `x` -> back to the same last station | `2 * (x - an)` |

> The last part is **doubled** because there is no station at `x`. You reach `x`, turn around, and must get back to the last station on the same tank.

(The gaps between stations are the same on the way back, so they do not add anything new.)

**Answer = maximum of all these values.**

---

## Dry Run

`x = 7`, stations = `[1, 2, 5]`

```
0 -> 1   : gap = 1
1 -> 2   : gap = 1
2 -> 5   : gap = 3
5 -> 7 -> 5 : 2 * (7 - 5) = 4

Answer = max(1, 1, 3, 4) = 4
```

---

## Approach 1: My Solution (Walking Through Every Point)

### Idea
Walk from `0` to `x` one unit at a time and keep a counter `cnt` of the distance since the last station.

1. At every point, check whether it is a station (using `find`).
2. If it is a station: update `maxi = max(maxi, cnt)` and reset `cnt = 0`.
3. After reaching `x`, walk **back** from `x` until the first station is found. This adds the return distance, so the last part becomes `2 * (x - an)`.
4. Print `maxi`.

### Complexity
- **Time:** `O(x * n)` per test case, because `find()` is `O(n)` and it runs for each of the `x` points.
- **Space:** `O(n)` to store the stations.

This is fine here since `x <= 100` and `n <= 50`, but it does extra work.

---

## Approach 2: Optimal Solution (Just Use the Gaps)

### Idea
No need to visit every point. Only the stations matter.

1. Keep `prev = 0` (the start).
2. For each station `a`, update `ans = max(ans, a - prev)` and set `prev = a`.
3. At the end, handle the last part: `ans = max(ans, 2 * (x - prev))`.

### Complexity
- **Time:** `O(n)` per test case (one pass over the stations)
- **Space:** `O(1)` extra space (no array needed, we read and process on the fly)

---

## Comparison

| | Approach 1 (Mine) | Approach 2 (Optimal) |
|---|---|---|
| Idea | Walk every unit, count distance | Compute gaps between stations |
| Time | `O(x * n)` | `O(n)` |
| Space | `O(n)` | `O(1)` |
| Uses `find()` | Yes | No |
| Passes constraints | Yes | Yes |

---

## Edge Cases to Remember

- **Only one station** (`n = 1`): answer is `max(a1, 2 * (x - a1))`.
  Example: `x = 10`, station at `7` -> `max(7, 6) = 7`.
- **Last station right before x**: the doubled part is small, so an earlier gap may be the answer.
- **Last station far from x**: the doubled part usually dominates.
- Forgetting to double the last part is the **most common mistake** on this problem.

---

## What I Learned

- When a resource is refilled completely, think about the **maximum gap**, not the total distance.
- A round trip with no refuel point at the turning point **doubles** the last segment.
- Brute force that passes the constraints is good, but looking for the simpler `O(n)` idea makes the solution cleaner.

---

## Tags
`greedy` `math` `implementation` `800-rating`

---

*Part of my daily DSA / Codeforces journey. One problem at a time. One concept at a time.* 🚀
