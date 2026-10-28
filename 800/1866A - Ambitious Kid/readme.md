# Codeforces 1866A: Ambitious Kid

![Difficulty](https://img.shields.io/badge/Rating-800-brightgreen)
![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)
![Topic](https://img.shields.io/badge/Topic-Math%20%2F%20Greedy-orange)

**Problem Link:** [Codeforces 1866A](https://codeforces.com/problemset/problem/1866/A)
**Time Limit:** 1 second | **Memory Limit:** 256 MB

---

## Problem Summary

You are given an array of integers `A1, A2, ..., AN`.

In **one operation**, you can pick **one element** and **increase or decrease it by 1**. You can do as many operations as you want, on any elements.

**Task:** Find the **minimum number of operations** needed to make the product of all elements equal to `0`:

```
A1 x A2 x A3 x ... x AN = 0
```

### Input
- `N`: size of the array (`1 <= N <= 10^5`)
- `A1 A2 ... AN`: the array (`-10^5 <= Ai <= 10^5`)

(There is only **one** test case in this problem.)

### Output
Print the minimum number of operations.

### Example

```
Input 1
3
2 -6 5

Output 1
2

Input 2
1
-3

Output 2
3

Input 3
5
0 -1 0 1 0

Output 3
0
```

---

## Key Observation

A product of numbers is `0` **only when at least one number is 0**.

So we do not need to touch all the numbers. We only need to make **one** number equal to `0`.

### How many operations does it cost to make one number 0?

For a number `x`, each operation moves it by 1. To reach `0`:

```
cost = |x|
```

- `2` needs `2` operations (go down: 2 -> 1 -> 0)
- `-6` needs `6` operations (go up: -6 -> -5 -> ... -> 0)
- `0` needs `0` operations (it is already `0`)

### Which number should we pick?

The cheapest one, of course!

> **Answer = the smallest absolute value in the array** = `min(|A1|, |A2|, ..., |AN|)`

If the array already has a `0`, the smallest absolute value is `0`, so the answer is `0`.

---

## Dry Run

**Example 1:** `2 -6 5`

```
|2| = 2, |-6| = 6, |5| = 5
Minimum = 2
Answer = 2
```

**Example 2:** `-3`

```
|-3| = 3
Minimum = 3
Answer = 3
```

**Example 3:** `0 -1 0 1 0`

```
There is a 0 in the array already
Minimum = 0
Answer = 0
```

---

## My Approach

### Idea
Go through the array and keep the **smallest absolute value** seen so far.

1. Start with `mini = INT_MAX` (a very big number).
2. Read each element.
3. If the element is `0`, the answer is `0`. Set `mini = 0` and stop.
4. Otherwise, take `abs(element)` and update `mini` if it is smaller.
5. Print `mini`.

### My Code (C++)

```cpp
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){

    int n;
    cin >> n;

    vector<int> v(n);
    int mini = INT_MAX;

    for(int i=0; i<n; i++){
        cin >> v[i];

        if(v[i] == 0){
            mini = 0;
            break;
        }
        else{
            int a = abs(0-v[i]);
            if(a < mini){
                mini = a;
            }
        }

    }

    cout << mini;

}
```

### Complexity
- **Time:** `O(N)` (one pass over the array)
- **Space:** `O(N)` for the vector

---

## Shorter Version (Same Idea)

We do not need the vector. We can update the minimum while reading. We also do not need a special check for `0`, because `abs(0) = 0` is already the smallest:

```cpp
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <climits>
using namespace std;

int main(){
    int n;
    cin >> n;

    int mini = INT_MAX;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        mini = min(mini, abs(x));
    }

    cout << mini << "\n";
}
```

| | My Code | Shorter Code |
|---|---|---|
| Idea | Track the smallest `abs`, stop at `0` | Track the smallest `abs` always |
| Time | `O(N)` | `O(N)` |
| Space | `O(N)` | `O(1)` |
| Readability | Clear | Short and clean |

Both are correct.

---

## Edge Cases to Remember

- **The array has a `0`:** answer is `0`, no operations needed.
- **`N = 1`:** the only element must become `0`, so the answer is `|A1|` (like `-3` gives `3`).
- **All numbers are negative:** use the absolute value (`-6` costs `6`, not `-6`).
- **Big values** (`10^5`): the answer is at most `10^5`, so `int` is enough.
- **About the `break` in my code:** it stops reading input early. This is safe here because there is only **one** test case. In a problem with many test cases, you must read the whole input first, or the next test case will be mixed up.
- `abs()` needs `<cstdlib>`. It usually works through `<iostream>`, but it is safer to include it.

---

## What I Learned

- A product equals `0` as soon as **one** factor is `0`. We do not need to change anything else.
- "Cost to reach `0`" for a number is just its **absolute value**.
- When we need the cheapest way to do something, take the **minimum** over all choices.
- Be careful with `break` when reading input, and remember it is only safe if there are no more test cases after it.

---

## Tags
`math` `greedy` `implementation` `800-rating`

---

*Part of my daily DSA / Codeforces journey. One problem at a time. One concept at a time.* 🚀
