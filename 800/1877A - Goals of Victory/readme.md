# Codeforces 1877A: Goals of Victory

![Difficulty](https://img.shields.io/badge/Rating-800-brightgreen)
![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)
![Topic](https://img.shields.io/badge/Topic-Math%20%2F%20Observation-orange)

**Problem Link:** [Codeforces 1877A](https://codeforces.com/problemset/problem/1877/A)
**Time Limit:** 1 second | **Memory Limit:** 256 MB

---

## Problem Summary

There are `n` teams in a football tournament. **Every pair of teams plays exactly one match.**

After each match, we know how many goals each team scored.

The **efficiency** of a team is:

```
efficiency = (total goals the team scored) - (total goals its opponents scored against it)
```

You are given the efficiency of `n - 1` teams. One team's efficiency is missing.

**Task:** Find the efficiency of the missing team. (It is guaranteed that it can be found in only one way.)

### Input
- `t`: number of test cases
- For each test case:
  - `n`: number of teams (`2 <= n <= 100`)
  - `a1 a2 ... a(n-1)`: efficiency of `n - 1` teams (`-100 <= ai <= 100`)

### Output
For each test case, print the efficiency of the missing team.

### Example

```
Input
2
4
3 -4 5
11
-30 12 -57 7 0 -81 -68 41 -89 0

Output
-4
265
```

---

## Key Observation

Think about **one single match** between Team A and Team B.

Say Team A scores `x` goals and Team B scores `y` goals.

| Team | Effect on its efficiency |
|------|--------------------------|
| Team A | `+x - y` |
| Team B | `+y - x` |

Add them together:

```
(x - y) + (y - x) = 0
```

So **every match adds exactly 0** to the total of all efficiencies. The goals just move from one side to the other.

> That means the **sum of efficiencies of all teams is always 0**.

### The formula

Let the missing efficiency be `m`:

```
a1 + a2 + ... + a(n-1) + m = 0
```

So:

```
m = -(a1 + a2 + ... + a(n-1))
```

**The answer is the negative of the sum of the given numbers.**

We do not need to care about how many matches, how many goals, or who played whom.

---

## Dry Run

**Test 1:** `3 -4 5`

```
Sum = 3 + (-4) + 5 = 4
Answer = -4
```

**Test 2:** `-30 12 -57 7 0 -81 -68 41 -89 0`

```
-30 + 12 = -18
-18 + (-57) = -75
-75 + 7 = -68
-68 + 0 = -68
-68 + (-81) = -149
-149 + (-68) = -217
-217 + 41 = -176
-176 + (-89) = -265
-265 + 0 = -265

Sum = -265
Answer = 265
```

---

## My Approach

### Idea
Add all given efficiencies and print the **negative** of the sum.

1. Read `n`.
2. Read `n - 1` numbers and add them into `sum`.
3. Print `-sum`.

### Complexity
- **Time:** `O(n)` per test case
- **Space:** `O(n)` for the vector

---

| | My Code | Shorter Code |
|---|---|---|
| Idea | Store numbers, add them, print `-sum` | Add while reading, print `-sum` |
| Time | `O(n)` | `O(n)` |
| Space | `O(n)` | `O(1)` |
| Readability | Clear | Short |

Both are correct.

---

## Edge Cases to Remember

- **`n = 2`:** only one number is given. The missing team's efficiency is the negative of it (if one team has `+5`, the other has `-5`).
- **Sum is `0`:** the answer is `0` (not `-0`). With `int`, this prints correctly.
- **Negative sum:** the answer becomes **positive** (see Test 2: sum `-265`, answer `265`).
- **Loop runs `n - 1` times**, not `n` times. Reading one number too many would break the input.
- The numbers are small, so `int` is enough. The largest possible sum is about `99 * 100 = 9900`.

---

## What I Learned

- A long story (matches, goals, teams) can hide a very **short formula**.
- Look for something that stays **constant** (here, the total is always `0`). This is called an **invariant**.
- Check a **single match** first. Small cases show the rule quickly.
- When something is gained by one side and lost by the other, the total does not change.

---

## Tags
`math` `observation` `implementation` `800-rating`

---

*Part of my daily DSA / Codeforces journey. One problem at a time. One concept at a time.* 🚀
