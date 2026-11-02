# Codeforces 1857A: Array Coloring

![Difficulty](https://img.shields.io/badge/Rating-800-brightgreen)
![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)
![Topic](https://img.shields.io/badge/Topic-Math%20%2F%20Parity-orange)

**Problem Link:** [Codeforces 1857A](https://codeforces.com/problemset/problem/1857/A)
**Time Limit:** 1 second | **Memory Limit:** 256 MB

---

## Problem Summary

You are given an array of `n` integers. You must color **every element** with one of **two colors** (say blue and red) so that:

1. The **sum of the blue elements** and the **sum of the red elements** have the **same parity** (both even or both odd).
2. **Each color is used at least once.**

**Task:** Tell whether such a coloring is possible.

### Input
- `t`: number of test cases
- For each test case:
  - `n`: length of the array (`2 <= n <= 50`)
  - `a1 a2 ... an`: the array (`1 <= ai <= 50`)

### Output
For each test case, print `YES` if it is possible, otherwise print `NO`.

### Example

```
Input
7
8
1 2 4 3 2 3 5 4
2
4 7
3
3 9 8
2
1 7
5
5 4 3 2 1
4
4 3 4 5
2
50 48

Output
YES
NO
YES
YES
NO
YES
YES
```

---

## Key Observation

Let the blue sum be `B` and the red sum be `R`. The total sum is:

```
S = B + R
```

### When do `B` and `R` have the same parity?

| `B` | `R` | `B + R` |
|-----|-----|---------|
| even | even | **even** |
| odd | odd | **even** |
| even | odd | odd |
| odd | even | odd |

So:

> `B` and `R` have the **same parity** exactly when the **total sum `S` is even**.

This works in **both directions**:
- If `S` is even, **any** split gives `B` and `R` with the same parity.
- If `S` is odd, **no** split can work.

### What about "each color at least once"?

Since `n >= 2`, we can always make one element blue and the rest red (or any other split). So this condition never causes trouble.

### When is the total sum even?

Even numbers do not change the parity of a sum. Only **odd numbers** matter:

> The sum is even exactly when the **count of odd numbers is even**.

So the final rule is:

```
Answer is YES  if (number of odd elements) is even
Answer is NO   if (number of odd elements) is odd
```

---

## Quick Rule

| Odd elements in the array | Answer |
|---------------------------|--------|
| Even count (0, 2, 4, ...) | `YES` |
| Odd count (1, 3, 5, ...) | `NO` |

---

## Dry Run

```
[1 2 4 3 2 3 5 4]  -> odd numbers: 1, 3, 3, 5 -> count 4 (even) -> YES
[4 7]              -> odd numbers: 7           -> count 1 (odd)  -> NO
[3 9 8]            -> odd numbers: 3, 9        -> count 2 (even) -> YES
[1 7]              -> odd numbers: 1, 7        -> count 2 (even) -> YES
[5 4 3 2 1]        -> odd numbers: 5, 3, 1     -> count 3 (odd)  -> NO
[4 3 4 5]          -> odd numbers: 3, 5        -> count 2 (even) -> YES
[50 48]            -> odd numbers: none        -> count 0 (even) -> YES
```

---

## My Approach

### Idea
Count the **even** numbers (`e`) and the **odd** numbers (`o`). Then decide using the counts.

My code splits the situation into many cases:

1. All numbers odd: `YES` if `o` is even, else `NO`.
2. All numbers even: `YES`.
3. `n = 2`: `YES` if both are the same parity, else `NO`.
4. `e == o`: `YES` if `e` is even, else `NO`.
5. `o` even (and `e` anything): `YES`.
6. Otherwise: `NO`.

If you check every case, the answer is `YES` exactly when `o` is even. So all these cases are just different ways of writing the same rule.

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

        vector<int> v(n);
        int e = 0;
        int o = 0;

        for(int i=0; i<n; i++){
            cin >> v[i];
            if(v[i] % 2 == 0) e++;
            else o++;
        }

        if(e == 0 && o != 0){
            if(o % 2 == 0){
                cout << "Yes" << endl;
            }
            else{
                cout << "No" << endl;
            }
            continue;
        }
        else if(o == 0 && e != 0){
            cout << "Yes" << endl;
            continue;
        }

        if(v.size() == 2){
            if(e == 2 || o == 2){
                cout << "Yes" << endl;
            }
            else{
                cout << "No" << endl;
            }
        }
        else if(e == o){
            if(e % 2 == 0){
                cout << "Yes" << endl;
            }
            else{
                cout << "No" << endl;
            }
        }
        else if(o % 2 == 0 && e % 2 != 0){
            cout << "Yes" << endl;
        }
        else if(o % 2 == 0 && e % 2 == 0){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }

    }

}
```

### Complexity
- **Time:** `O(n)` per test case
- **Space:** `O(n)` for the vector

---

## Shorter Version (Same Idea)

Since the whole problem is "is the number of odd elements even?", the code can be very short and does not need a vector:

```cpp
#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, odd = 0;
        cin >> n;

        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            if(x % 2 == 1) odd++;
        }

        cout << (odd % 2 == 0 ? "YES" : "NO") << "\n";
    }
}
```

Another way to think: add up all numbers, and check `sum % 2 == 0`.

| | My Code | Shorter Code |
|---|---|---|
| Idea | Many cases using counts `e` and `o` | One check: `odd % 2 == 0` |
| Time | `O(n)` | `O(n)` |
| Space | `O(n)` | `O(1)` |
| Readability | Hard to follow | Very easy |

Both are correct.

---

## Edge Cases to Remember

- **All numbers even** (`50 48`): sum is even, so `YES`.
- **All numbers odd with even count** (`1 7`): `YES`.
- **All numbers odd with odd count** (`1 3 5`): sum is odd, so `NO`.
- **`n = 2`, one odd and one even** (`4 7`): `NO`.
- **Both colors must be used:** since `n >= 2`, this is always possible, so it does not change the answer.
- **Do not try all colorings.** There are `2^n` of them. The parity rule is much faster.

---

## What I Learned

- When a problem asks about **parity** (odd or even), think about **the sum of everything**.
- `B` and `R` have the same parity exactly when `B + R` is even. This turns a "split" problem into a simple check.
- Even numbers do not change parity. Only the **count of odd numbers** matters.
- Many `if-else` cases can often be replaced with one clean rule. If the cases look messy, step back and look for the one idea behind them.
- My many-case solution was correct, but the simple rule is faster to write and easier to trust.

---

## Tags
`math` `parity` `implementation` `800-rating`

---

*Part of my daily DSA / Codeforces journey. One problem at a time. One concept at a time.* 🚀
