# Codeforces 1853A: Desorting

![Difficulty](https://img.shields.io/badge/Rating-800-brightgreen)
![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)
![Topic](https://img.shields.io/badge/Topic-Math%20%2F%20Greedy-orange)

**Problem Link:** [Codeforces 1853A](https://codeforces.com/problemset/problem/1853/A)
**Time Limit:** 1 second | **Memory Limit:** 256 MB

---

## Problem Summary

An array `a` of length `n` is called **sorted** if:

```
a1 <= a2 <= a3 <= ... <= an
```

Ntarsis has an array `a`. He can do this operation **any number of times** (even zero):

- Choose an index `i` (`1 <= i <= n-1`).
- **Add 1** to `a1, a2, ..., ai` (the left part).
- **Subtract 1** from `a(i+1), ..., an` (the right part).

Values can become negative.

**Task:** Find the **minimum number of operations** needed to make the array **not sorted**.

### Input
- `t`: number of test cases
- For each test case:
  - `n`: length of the array (`2 <= n <= 500`)
  - `a1 a2 ... an`: the array (`1 <= ai <= 10^9`)

### Output
For each test case, print the minimum number of operations.

### Example

```
Input
4
2
1 1
4
1 8 10 13
3
1 3 2
3
1 9 14

Output
1
2
0
3
```

---

## Key Observation

Look at the **gap** between two neighbors:

```
d[i] = a[i+1] - a[i]
```

The array is sorted exactly when **every gap is `>= 0`**. It becomes **not sorted** as soon as **one gap becomes negative**.

### What does one operation do to the gaps?

Say we pick index `i`:

- Elements in the left part all go **+1**, so the gaps **inside** the left part do not change.
- Elements in the right part all go **-1**, so the gaps **inside** the right part do not change.
- The only gap that changes is between `a[i]` and `a[i+1]`:

```
new gap = (a[i+1] - 1) - (a[i] + 1) = old gap - 2
```

> **One operation at index `i` makes exactly one gap smaller by 2. All other gaps stay the same.**

### Case 1: The array is already not sorted

There is already a negative gap. Answer is **0**.

### Case 2: The array is sorted

All gaps are `>= 0`. We need to make **one** gap negative. The best choice is the **smallest gap** `d`, since it needs the fewest operations.

After `k` operations on it, the gap is `d - 2k`. We want:

```
d - 2k < 0   ->   k > d / 2
```

The smallest whole number `k` that works is:

```
k = d / 2 + 1     (using integer division)
```

### Why only the smallest gap?

Operating on one gap never helps another gap, so we just pick the gap that is cheapest to break. That is the smallest one.

---

## Quick Rule

| Situation | Answer |
|-----------|--------|
| Some gap is negative (array not sorted) | `0` |
| Array is sorted | `min_gap / 2 + 1` |

---

## Dry Run

**Test 1:** `[1, 1]`

```
Gaps: 1 - 1 = 0
Min gap = 0
Answer = 0 / 2 + 1 = 1
```

**Test 2:** `[1, 8, 10, 13]`

```
Gaps: 7, 2, 3
Min gap = 2
Answer = 2 / 2 + 1 = 2
```

**Test 3:** `[1, 3, 2]`

```
Gaps: 2, -1
There is a negative gap -> already not sorted
Answer = 0
```

**Test 4:** `[1, 9, 14]`

```
Gaps: 8, 5
Min gap = 5
Answer = 5 / 2 + 1 = 2 + 1 = 3
```

(Here `5 / 2 = 2` because of integer division.)

---

## My Approach

### Idea
Find the **smallest gap** between neighbors.

1. Read the array.
2. Go through all neighbors and find the smallest `a[i] - a[i-1]`.
3. If the smallest gap is **negative**, print `0`.
4. Otherwise, print `smallest_gap / 2 + 1`.

### My Code (C++)

```cpp
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        vector<long long> v(n);
        long long min_diff = INT_MAX;
        int index = -1;
        int cnt = 0;


        for(int i=0; i<n; i++){
            cin >> v[i];
        }

        for(int i=1; i<n; i++){
            long long diff = v[i] - v[i-1];

            if(diff < min_diff){
                index = i-1;
                min_diff = min(min_diff, diff);
            }

        }

        if(min_diff < 0){
            cout << 0 << endl;
        }
        else{

            long long diff = v[index+1] - v[index];

            long long ans = (diff / 2) + 1;

            cout << ans << endl;
        }


    }

}
```

### Complexity
- **Time:** `O(n)` per test case
- **Space:** `O(n)` for the vector

---

## Cleaner Version (Same Idea)

We do not need to remember the index, because `min_diff` already holds the smallest gap. We also do not need to store the array:

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        long long prev, x;
        cin >> prev;

        long long min_gap = 2000000000LL;   // bigger than any possible gap

        for(int i = 1; i < n; i++){
            cin >> x;
            min_gap = min(min_gap, x - prev);
            prev = x;
        }

        if(min_gap < 0) cout << 0 << "\n";
        else cout << min_gap / 2 + 1 << "\n";
    }
}
```

| | My Code | Cleaner Code |
|---|---|---|
| Idea | Find the smallest gap and its index | Find the smallest gap only |
| Time | `O(n)` | `O(n)` |
| Space | `O(n)` | `O(1)` |
| Readability | Has a few extra variables (`index`, `cnt`) | Short and clear |

Both are correct. (`cnt` is not used in my code, and `min(min_diff, diff)` is not needed because we already know `diff < min_diff`.)

---

## Edge Cases to Remember

- **Already not sorted** (`1 3 2`): answer is `0`.
- **All elements equal** (`1 1`): gap is `0`, answer is `0 / 2 + 1 = 1`.
- **Odd gap** (`5`): `5 / 2 + 1 = 3`. After 2 operations the gap is `1` (still fine), after 3 it is `-1` (broken).
- **Even gap** (`2`): `2 / 2 + 1 = 2`. After 1 operation the gap is `0` (still sorted), after 2 it is `-2` (broken).
- **`n = 2`:** only one gap, so use the same formula.
- **Big values** (up to `10^9`): use `long long`.
- **Initial value for the minimum** should be larger than any possible gap (the largest gap is about `10^9`, so `INT_MAX` works).

---

## What I Learned

- Instead of tracking the whole array, track the **differences** between neighbors. An operation that looks big may only change **one** difference.
- Ask: "What does one operation change, and what stays the same?"
- An operation that changes a gap by `2` means we need `gap / 2 + 1` steps to push it below zero. Be careful with **odd and even** gaps.
- When we want the **minimum** operations, aim at the **weakest** point (here, the smallest gap).
- Check the "already done" case first (answer `0`).

---

## Tags
`greedy` `math` `brute force` `800-rating`

---

*Part of my daily DSA / Codeforces journey. One problem at a time. One concept at a time.* 🚀
