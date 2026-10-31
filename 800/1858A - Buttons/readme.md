# Codeforces 1858A: Buttons

![Difficulty](https://img.shields.io/badge/Rating-800-brightgreen)
![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)
![Topic](https://img.shields.io/badge/Topic-Games%20%2F%20Math-orange)

**Problem Link:** [Codeforces 1858A](https://codeforces.com/problemset/problem/1858/A)
**Time Limit:** 1 second | **Memory Limit:** 256 MB

---

## Problem Summary

Anna and Katie are in a lab with `a + b + c` buttons:

- `a` buttons can be pressed **only by Anna**
- `b` buttons can be pressed **only by Katie**
- `c` buttons can be pressed by **either of them**

They play a game and **take turns** pressing buttons. **Anna goes first.** Each button can be pressed **at most once**.

The girl who **cannot press a button** on her turn **loses**.

**Task:** If both play in the best possible way, who wins?

### Input
- `t`: number of test cases
- For each test case: three integers `a`, `b`, `c` (`1 <= a, b, c <= 10^9`)

### Output
For each test case, print `First` if Anna wins, or `Second` if Katie wins.

### Example

```
Input
5
1 1 1
9 3 3
1 2 3
6 6 9
2 2 8

Output
First
First
Second
First
Second
```

---

## Key Observation

The **shared buttons** (`c`) are the important part.

If a player presses a shared button, it is **gone** for the other player too. So the smart move is to **use shared buttons first**, and save your own private buttons for later.

Both players think the same way, so they **take turns grabbing the shared buttons**:

```
Anna takes one, Katie takes one, Anna takes one, ...
```

Since Anna starts:

- Anna gets **`ceil(c / 2)`** shared buttons (the bigger half if `c` is odd)
- Katie gets **`floor(c / 2)`** shared buttons

### Total turns each girl can make

```
Anna's total  = a + ceil(c / 2)
Katie's total = b + floor(c / 2)
```

### Who wins?

The turns go: Anna, Katie, Anna, Katie, ...

- If **Anna's total > Katie's total**, Katie runs out first, so **Anna wins**.
- If **Anna's total <= Katie's total**, Anna runs out first (she goes first, so she needs strictly more), so **Katie wins**.

> **Anna wins only if `a + ceil(c/2) > b + floor(c/2)`.**

### Simplify into two cases

**If `c` is even:** `ceil(c/2) = floor(c/2) = c/2`, so they cancel:

```
a + c/2 > b + c/2   ->   a > b
```

**If `c` is odd:** `ceil(c/2) = (c+1)/2` and `floor(c/2) = (c-1)/2`:

```
a + (c+1)/2 > b + (c-1)/2   ->   a + 1 > b   ->   a >= b
```

---

## Quick Rule

| `c` | Anna wins (`First`) when | Otherwise |
|-----|--------------------------|-----------|
| Odd | `a >= b` | `Second` |
| Even | `a > b` | `Second` |

---

## Dry Run

```
1 1 1  -> c odd,  a >= b ? 1 >= 1 yes -> First
9 3 3  -> c odd,  a >= b ? 9 >= 3 yes -> First
1 2 3  -> c odd,  a >= b ? 1 >= 2 no  -> Second
6 6 9  -> c odd,  a >= b ? 6 >= 6 yes -> First
2 2 8  -> c even, a > b  ? 2 > 2  no  -> Second
```

**Check test 3 with totals:** `a = 1, b = 2, c = 3`

```
Anna's total  = 1 + 2 = 3
Katie's total = 2 + 1 = 3
3 > 3 ? No -> Second  (matches)
```

---

## My Approach

### Idea
Use the two cases from the quick rule.

1. If `c` is **odd**: Katie wins only when `b > a`. Otherwise Anna wins.
2. If `c` is **even**: Anna wins only when `a > b`. Otherwise Katie wins.

### My Code (C++)

```cpp
#include <iostream>
using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){

        long long a, b, c;
        cin >> a >> b >> c;

        if(c % 2 == 1){
            if(b > a){
                cout << "Second" << endl;
            }
            else{
                cout << "First" << endl;
            }
        }
        else{
            if(a > b){
                cout << "First" << endl;
            }
            else{
                cout << "Second" << endl;
            }
        }
    }

}
```

### Complexity
- **Time:** `O(1)` per test case
- **Space:** `O(1)`

---

## Shorter Version (Same Idea)

We can skip the two cases and use the total turns formula directly:

```cpp
long long anna  = a + (c + 1) / 2;
long long katie = b + c / 2;

cout << (anna > katie ? "First" : "Second") << "\n";
```

| | My Code | Shorter Code |
|---|---|---|
| Idea | Two cases (`c` odd or even) | Compare total turns |
| Time | `O(1)` | `O(1)` |
| Space | `O(1)` | `O(1)` |
| Readability | Fast to check | Easier to explain |

Both are correct.

---

## Edge Cases to Remember

- **`a == b` and `c` is odd:** Anna wins (she gets the extra shared button).
- **`a == b` and `c` is even:** Katie wins (shared buttons are split equally, and Anna must go first and run out first).
- **`a < b`:** Anna always loses, no matter how big `c` is. With `c` odd she needs `a >= b`, and with `c` even she needs `a > b`. So `a < b` always means `Second`.
- **Large values** (up to `10^9`): `long long` is the safe choice because sums like `a + c` can go above what `int` stores.
- The shared count `c` only matters through its **parity** (odd or even), not its size.

---

## What I Learned

- In game problems, ask: "What is the **best first thing** to do?" Here it is to use shared resources first.
- When both players take turns on the same pile, the first player gets the **bigger half** (`ceil`), the second gets the **smaller half** (`floor`).
- Count **how many turns each player can make**, then compare. The player who runs out first loses.
- Big numbers (`10^9`) do not mean big work. We only needed the **parity** of `c`.
- Simplifying an inequality (`a + 1 > b` becomes `a >= b`) gives a clean rule.

---

## Tags
`games` `math` `greedy` `800-rating`

---

*Part of my daily DSA / Codeforces journey. One problem at a time. One concept at a time.* 🚀
