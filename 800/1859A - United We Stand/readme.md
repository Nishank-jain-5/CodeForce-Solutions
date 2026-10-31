# Codeforces 1859A: United We Stand

![Difficulty](https://img.shields.io/badge/Rating-800-brightgreen)
![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)
![Topic](https://img.shields.io/badge/Topic-Constructive%20%2F%20Number%20Theory-orange)

**Problem Link:** [Codeforces 1859A](https://codeforces.com/problemset/problem/1859/A)
**Time Limit:** 1 second | **Memory Limit:** 256 MB

---

## Problem Summary

You are given an array `a` of length `n`. There are two empty arrays `b` and `c`.

You must put **every** element of `a` into **exactly one** of `b` or `c`, so that:

1. Both `b` and `c` are **non-empty**.
2. For any `bi` and any `cj`, **`cj` is not a divisor of `bi`**.

**Task:** Print arrays `b` and `c`, or print `-1` if it is not possible.

(Remember: "`x` is a divisor of `y`" means `y % x == 0`.)

### Input
- `t`: number of test cases
- For each test case:
  - `n`: length of the array (`2 <= n <= 100`)
  - `a1 a2 ... an`: the array (`1 <= ai <= 10^9`)

### Output
For each test case:
- Print `-1` if there is no answer.
- Otherwise, print `lb lc` (lengths of `b` and `c`), then the elements of `b`, then the elements of `c`.
- Any valid answer is accepted.

### Example

```
Input
5
3
2 2 2
5
1 2 3 4 5
3
1 3 5
7
1 7 7 2 9 1 4
5
4 8 12 12 4

Output (one valid answer)
-1
1 4
1
2 3 4 5
1 2
1
3 5
2 5
1 1
2 4 7 7 9
3 2
4 8 4
12 12
```

---

## Key Observation

We want every `cj` to **not divide** every `bi`.

Think about when a number `x` can divide a number `y` (with `y` positive):

> `x` can divide `y` only if `x <= y`.

So if `cj` is **bigger** than `bi`, then `cj` can **never** divide `bi`. 

### The idea

Put the **smallest** elements in `b`, and all the **bigger** elements in `c`.

- `b` = all copies of the **minimum** value
- `c` = everything else (every element here is **strictly bigger** than the minimum)

Now every `cj > bi`, so `cj` can never be a divisor of `bi`. The answer is always valid.

### When is the answer `-1`?

If **all elements are equal** (like `2 2 2`), then `c` would be empty, because every element equals the minimum.

If we try to split them, then some `cj` equals some `bi`, and a number always divides itself. So no answer exists.

> **Answer is `-1` only when all elements are equal. Otherwise, it always exists.**

---

## Quick Rule

| Situation | Answer |
|-----------|--------|
| All elements are equal | `-1` |
| Some element is bigger than the minimum | `b` = all minimums, `c` = the rest |

---

## Dry Run

**Test 1:** `2 2 2`

```
All equal -> c is empty -> -1
```

**Test 2:** `1 2 3 4 5`

```
Minimum = 1
b = [1]
c = [2, 3, 4, 5]
Check: 2, 3, 4, 5 are all bigger than 1, so none can divide 1. Valid!
```

**Test 4:** `1 7 7 2 9 1 4`

```
Minimum = 1
b = [1, 1]
c = [7, 7, 2, 9, 4]
Valid!
```

**Test 5:** `4 8 12 12 4`

```
Minimum = 4
b = [4, 4]
c = [8, 12, 12]
Check: 8 does not divide 4 (8 > 4), and 12 does not divide 4. Valid!
```

---

## My Approach

### Idea
Sort the array. Then the smallest element is at the front.

1. Sort `a` in increasing order.
2. Put `a[0]` (the minimum) into `b`.
3. For every other element:
   - If it is **equal** to the minimum, put it in `b`.
   - Otherwise, put it in `c`.
4. If `c` is empty, print `-1`. Else print `b` and `c`.

### How my code checks "equal to the minimum"

My code uses this condition:

```cpp
if(b[0] % a[i] == 0)
```

Since the array is sorted, every `a[i]` is `>= b[0]`. So:

- If `a[i] == b[0]`, then `b[0] % a[i] == 0`, and the element goes to `b`.
- If `a[i] > b[0]`, then `b[0] % a[i] = b[0]` (not zero), and the element goes to `c`.

So this condition works exactly as "is `a[i]` equal to the minimum?".

### My Code (C++)

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        vector<long long> a(n);

        for(int i=0; i<n; i++){
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        vector<long long> b;
        vector<long long> c;

        for(int i=0; i<n; i++){
            if(i == 0){
                b.push_back(a[i]);
                continue;
            }
            else{
                if(b[0] % a[i] == 0){
                    b.push_back(a[i]);
                }
                else{
                    c.push_back(a[i]);
                }
            }
        }

        if(b.size() == 0 || c.size() == 0){
            cout << -1 << endl;
        }
        else{
            cout << b.size() << " " << c.size() << endl;

            for(auto i : b){
                cout << i << " ";
            }
            cout << endl;

            for(auto i : c){
                cout << i << " ";
            }
            cout << endl;
        }

    }

}
```

### Complexity
- **Time:** `O(n log n)` per test case (because of sorting)
- **Space:** `O(n)`

---

## Simpler Version (Same Idea)

We do not need to sort. Just find the minimum, then split:

```cpp
long long mn = *min_element(a.begin(), a.end());

for(long long x : a){
    if(x == mn) b.push_back(x);
    else c.push_back(x);
}
```

The condition `x == mn` is also easier to read than `b[0] % a[i] == 0`.

| | My Code | Simpler Version |
|---|---|---|
| Idea | Sort, then split by `b[0] % a[i]` | Find the min, then split by `x == mn` |
| Time | `O(n log n)` | `O(n)` |
| Space | `O(n)` | `O(n)` |
| Readability | Works, needs the extra thinking | Very clear |

Both are correct.

---

## Edge Cases to Remember

- **All elements equal** (`2 2 2`): answer is `-1`.
- **`n = 2` with different numbers** (`3 5`): `b = [3]`, `c = [5]`. Valid.
- **`n = 2` with equal numbers** (`4 4`): answer is `-1`.
- **Many copies of the minimum** (`1 1 7`): all copies of `1` go to `b`. If a copy of the minimum went into `c`, it would divide the ones in `b`.
- **The minimum is `1`:** every number is divisible by `1`, so `1` must **never** be in `c`. Our method keeps all `1`s in `b`, so it is safe.
- The output can be different from the sample. Any valid answer is accepted.

---

## What I Learned

- A number can only divide a number that is **equal or bigger**. A bigger number can never divide a smaller positive number.
- For "not a divisor" problems, **separating small and big** values is a strong idea.
- To find when there is **no answer**, ask: "What is the worst case?" Here it is when all numbers are equal.
- Constructive problems need an idea that **always works**, not a search through all the options.
- Sorting helps to see the minimum, but sometimes `min_element` is enough and faster.

---

## Tags
`constructive algorithms` `math` `number theory` `sortings` `800-rating`

---

*Part of my daily DSA / Codeforces journey. One problem at a time. One concept at a time.* 🚀
