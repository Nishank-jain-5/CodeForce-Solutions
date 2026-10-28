# Codeforces 1862B: Sequence Game

![Difficulty](https://img.shields.io/badge/Rating-900-brightgreen)
![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)
![Topic](https://img.shields.io/badge/Topic-Constructive%20%2F%20Greedy-orange)

**Problem Link:** [Codeforces 1862B](https://codeforces.com/problemset/problem/1862/B)
**Time Limit:** 2 seconds | **Memory Limit:** 256 MB

---

## Problem Summary

Vika writes a sequence `a` of positive integers (length `m`). Then she makes a new sequence `b` using this rule:

1. Write down `a1`.
2. Then write down every `ai` (for `i >= 2`) only if `a(i-1) <= ai`.

**Example:** `a = [4, 3, 2, 6, 3, 3]`

```
a1 = 4                  -> keep (first element)
3: is 4 <= 3 ? No       -> skip
2: is 3 <= 2 ? No       -> skip
6: is 2 <= 6 ? Yes      -> keep
3: is 6 <= 3 ? No       -> skip
3: is 3 <= 3 ? Yes      -> keep

b = [4, 6, 3]
```

Tema only sees `b`. He must find **any** sequence `a` that could produce this `b`.

The length `m` of your answer must satisfy: `n <= m <= 2 * n` (where `n` is the length of `b`).

### Input
- `t`: number of test cases
- For each test case:
  - `n`: length of `b`
  - `b1 b2 ... bn`: the sequence

### Output
For each test case, print `m` and then the sequence `a`. Any valid answer is accepted.

### Example

```
Input
3
3
4 6 3
3
1 2 3
1
144

Output
6
4 3 2 6 3 3
3
1 2 3
1
144
```

*(Other valid answers are also accepted, for example for `4 6 3` my method gives `4 6 3 3`.)*

---

## Key Observation

We need to **build** a sequence `a` so that the rule gives back `b`. Look at two neighbors in `b`: `b[i-1]` and `b[i]`.

### Case 1: `b[i] >= b[i-1]` (going up or equal)

Just put `b[i]` right after `b[i-1]` in `a`.

Since `b[i-1] <= b[i]`, the rule **keeps** `b[i]`. 

```
a: ... b[i-1], b[i]
```

### Case 2: `b[i] < b[i-1]` (going down)

If we just put `b[i]` after `b[i-1]`, the rule would **skip** it (because `b[i-1] > b[i]`). That is a problem.

Trick: write `b[i]` **twice**.

```
a: ... b[i-1], b[i], b[i]
```

- The **first** `b[i]` comes after a bigger number, so it is skipped.
- The **second** `b[i]` comes after an equal number (`b[i] <= b[i]`), so it is **kept**.

That gives exactly one `b[i]` in the result.

### Length check

Every element of `b` is written at most **2 times**, so:

```
n <= m <= 2 * n
```

This is exactly what the problem allows.

---

## Quick Rule

| Situation | What we add to `a` |
|-----------|--------------------|
| `i = 0` (first element) | `b[0]` once |
| `b[i] >= b[i-1]` | `b[i]` once |
| `b[i] < b[i-1]` | `b[i]` twice |

---

## Dry Run

**Example 1:** `b = [4, 6, 3]`

```
4          -> first element       -> a = [4]
6 >= 4     -> add once            -> a = [4, 6]
3 < 6      -> add twice           -> a = [4, 6, 3, 3]

Check a = [4, 6, 3, 3]:
  keep 4 (first)
  6: 4 <= 6 -> keep
  3: 6 <= 3 ? no -> skip
  3: 3 <= 3 -> keep
  b = [4, 6, 3]  Correct!
```

**Example 2:** `b = [1, 2, 3]`

```
1 -> a = [1]
2 >= 1 -> a = [1, 2]
3 >= 2 -> a = [1, 2, 3]
```

**Example 3:** `b = [1, 7, 9, 5, 7]`

```
1 -> [1]
7 >= 1 -> [1, 7]
9 >= 7 -> [1, 7, 9]
5 < 9  -> [1, 7, 9, 5, 5]
7 >= 5 -> [1, 7, 9, 5, 5, 7]
```

---

## My Approach

### Idea
Build the answer while reading `b` from left to right.

1. Add `b[0]` to the answer.
2. For every next element:
   - If it is **bigger or equal** to the previous one, add it once.
   - If it is **smaller**, add it twice.
3. Print the length and the sequence.

### My Code (C++)

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        vector<long long> v(n);
        for(int i=0; i<n; i++){
            cin >> v[i];
        }

        vector<long long> ans;
        for(int i=0; i<n; i++){
            if(i == 0){
                ans.push_back(v[i]);
            }
            else if(v[i] >= v[i-1]){
                ans.push_back(v[i]);
            }
            else if(v[i] < v[i-1]){
                ans.push_back(v[i]);
                ans.push_back(v[i]);
            }
        }

        cout << ans.size() << endl;

        for(auto v : ans){
            cout << v << " ";
        }
        cout << endl;

    }

}
```

### Complexity
- **Time:** `O(n)` per test case
- **Space:** `O(n)` for the answer vector

---

## Small Improvements

Two small things can make the code safer and faster:

**1. Use `"\n"` instead of `endl`.** `endl` flushes the output every time. With up to `2 * 10^5` numbers, this can make the program slower.

**2. Do not reuse the name `v` inside the loop.** In my code, `for(auto v : ans)` uses the same name as the input vector `v`. It works (the new `v` hides the old one), but a different name like `x` is clearer.

Also, fast input can help:

```cpp
ios::sync_with_stdio(false);
cin.tie(nullptr);
```

| | My Code | Improved Code |
|---|---|---|
| Idea | Same | Same |
| Time | `O(n)` | `O(n)` (faster output) |
| Space | `O(n)` | `O(n)` |
| Output | `endl` | `"\n"` |

Both are correct. The improved version is just safer for big inputs.

---

## Edge Cases to Remember

- **`n = 1`:** `b = [144]`. The answer is just `144` (length `1`).
- **All elements equal** (`1 1`): `b[i] >= b[i-1]`, so add once. Answer is `1 1`.
- **Strictly decreasing** (`5 4 3 2 1`): every element after the first is written twice. Length becomes `1 + 2 * (n-1)`, which is less than `2n`. Fine.
- **Big values** (up to `10^9`): `int` fits, and `long long` is also safe.
- The answer is **not unique**. Your output may differ from the sample, and it is still correct.
- **Always check the length** is between `n` and `2n`. This method gives it automatically.

---

## What I Learned

- In **constructive** problems, we do not search for the answer. We **build** one that follows the rule.
- When one case causes trouble (going down), find a small trick (write it twice) to fix it.
- Check your idea on a small example by running the rule on your output (like `[4, 6, 3, 3]` giving back `[4, 6, 3]`).
- If the problem says "any valid answer", there are many correct outputs. Do not worry if yours is different from the sample.
- Small habits matter: use `"\n"` instead of `endl` for large outputs.

---

## Tags
`constructive algorithms` `greedy` `implementation` `900-rating`

---

*Part of my daily DSA / Codeforces journey. One problem at a time. One concept at a time.* 🚀
