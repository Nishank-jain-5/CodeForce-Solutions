# Codeforces 1845A: Forbidden Integer

![Difficulty](https://img.shields.io/badge/Rating-800-brightgreen)
![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)
![Topic](https://img.shields.io/badge/Topic-Constructive%20%2F%20Math-orange)

**Problem Link:** [Codeforces 1845A](https://codeforces.com/problemset/problem/1845/A)
**Time Limit:** 2 seconds | **Memory Limit:** 256 MB

---

## Problem Summary

You are given three integers `n`, `k` and `x` (`1 <= x <= k <= n <= 100`).

- You want to make the sum **exactly `n`**.
- You have an **unlimited supply** of every integer from `1` to `k`, **except `x`** (the number `x` is not available).
- You can use each available number as many times as you like.

**Task:** Tell whether it is possible. If yes, print one valid way to do it.

### Input
- `t`: number of test cases
- For each test case: one line with `n`, `k`, `x`

### Output
For each test case:
- Print `YES` or `NO`.
- If `YES`, print `m` (how many numbers you used), and then those `m` numbers. Any valid answer is accepted.

### Example

```
Input
5
10 3 2
5 2 1
4 2 1
7 7 3
6 1 1

Output (one valid answer)
YES
10
1 1 1 1 1 1 1 1 1 1
NO
YES
2
2 2
YES
7
1 1 1 1 1 1 1
NO
```

---

## Key Observation

The easiest number to build any sum with is **`1`**. If we can use `1`, we can make **any** `n` just by taking `n` ones.

So everything depends on whether `x` is `1` or not.

### Case 1: `x != 1`

`1` is available. Take `n` ones. The sum is `n`.

```
Answer: YES, with n copies of 1
```

### Case 2: `x == 1`

Now `1` is **not** available. We only have `2, 3, ..., k`.

#### Sub-case 2a: `k == 1`

Then there are **no numbers at all** (`1` is forbidden and `k = 1`). The answer is **NO**.

#### Sub-case 2b: `k == 2`

We only have `2`. We can only make **even** sums.

- `n` even: take `n / 2` twos. **YES**.
- `n` odd: **NO**.

#### Sub-case 2c: `k >= 3`

We have `2` and `3`.

- `n` even: take `n / 2` twos. **YES**.
- `n` odd: take **one `3`** and then `(n - 3) / 2` twos. Since `n` is odd and `n >= k >= 3`, `n - 3` is even and not negative. **YES**.

> `2` and `3` together can build every number from `2` upward (except `1`), and here `n >= 3`, so we are safe.

---

## Quick Rule

| Condition | Answer |
|-----------|--------|
| `x != 1` | `YES`: `n` ones |
| `x == 1` and `k == 1` | `NO` |
| `x == 1`, `k == 2`, `n` odd | `NO` |
| `x == 1`, `n` even (and `k >= 2`) | `YES`: `n / 2` twos |
| `x == 1`, `n` odd, `k >= 3` | `YES`: one `3` and `(n - 3) / 2` twos |

---

## Dry Run

```
10 3 2 -> x != 1                    -> YES, ten 1s
 5 2 1 -> x == 1, k == 2, n odd     -> NO
 4 2 1 -> x == 1, n even, k >= 2    -> YES, two 2s  (2 + 2 = 4)
 7 7 3 -> x != 1                    -> YES, seven 1s
 6 1 1 -> x == 1, k == 1            -> NO
```

**Extra example:** `n = 9, k = 4, x = 1`

```
x == 1, n odd, k >= 3
Take one 3 -> remaining 6
6 / 2 = 3 twos
Numbers: 3, 2, 2, 2  -> sum = 9
```

---

## My Approach

### Idea
Build the list `v` of numbers using the cases above. Then add them up. If the sum equals `n`, print `YES` and the list. Otherwise, print `NO`.

1. If `x != 1`: add `n` ones.
2. If `x == 1` and `n` is even and `k >= 2`: add `n / 2` twos.
3. If `x == 1` and `n` is odd:
   - If `k` is `1` or `2`, we cannot do it. (My code pushes a `0`, so the sum will not match `n`.)
   - Otherwise, add one `3` and then `(n - 3) / 2` twos.
4. Check the sum.

### My Code (C++)

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){

        int n, k, x;
        cin >> n >> k >> x;

        int num = n;
        vector<int> v;

        if(x != 1){
            while(num--){
                v.push_back(1);
            }
        }
        else{
            if(n % 2 == 0){
                if(k >= 2){
                    int temp = num / 2;
                    while(temp--){
                        v.push_back(2);
                    }
                }
            }
            else{
                if(k ==1 || k == 2){
                    v.push_back(0);
                }
                else{
                    v.push_back(3);
                    num = num - 3;
                    int temp = num / 2;

                    while(temp--){
                        v.push_back(2);
                    }
                }

            }
        }

        int sum = 0;
        for(auto i : v){
            sum += i;
        }

        if(sum != n){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
            cout << v.size() << endl;
            for(auto i : v){
                cout << i << " ";
            }
            cout << endl;
        }

    }

}
```

### Complexity
- **Time:** `O(n)` per test case (we build at most `n` numbers)
- **Space:** `O(n)` for the list

---

## Cleaner Version (Same Idea)

Instead of pushing a fake `0` and checking the sum, we can print `NO` directly when the case is impossible:

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, k, x;
        cin >> n >> k >> x;

        vector<int> v;

        if(x != 1){
            v.assign(n, 1);                       // n ones
        }
        else if(k == 1){
            // impossible
        }
        else if(n % 2 == 0){
            v.assign(n / 2, 2);                   // n/2 twos
        }
        else if(k >= 3){
            v.push_back(3);
            v.insert(v.end(), (n - 3) / 2, 2);    // one 3, then twos
        }
        // else: k == 2 and n odd -> impossible, v stays empty

        if(v.empty()){
            cout << "NO\n";
        }
        else{
            cout << "YES\n" << v.size() << "\n";
            for(int a : v) cout << a << " ";
            cout << "\n";
        }
    }
}
```

| | My Code | Cleaner Code |
|---|---|---|
| Idea | Build list, then check the sum | Build list only in possible cases |
| Time | `O(n)` | `O(n)` |
| Space | `O(n)` | `O(n)` |
| Readability | Works, but the fake `0` is a trick | Each case is clear |

Both are correct. In my code, the pushed `0` is **not** a real answer. It is just used to make the sum wrong so that `NO` is printed.

---

## Edge Cases to Remember

- **`x != 1`:** always `YES` (just use ones), no matter what `k` is.
- **`k = 1` and `x = 1`:** no numbers exist. Answer is `NO`.
- **`x = 1`, `k = 2`, `n` odd:** only `2` is available, so odd sums are impossible. `NO`.
- **`x = 1`, `n` even, `k >= 2`:** use `n / 2` twos. `YES`.
- **`x = 1`, `n` odd, `k >= 3`:** use one `3` and the rest twos. `n` must be at least `3` here, because `n >= k >= 3`.
- **`n = 1`:** since `1 <= x <= k <= n`, we get `k = 1` and `x = 1`. Answer is `NO`.
- **The numbers used must be `<= k`.** Both `2` and `3` are fine when `k >= 3`.

---

## What I Learned

- If a problem gives you a choice of numbers, ask: "Which number is the **easiest** to build everything with?" Here it was `1`.
- If the best number is not available, try the next smallest ones (`2` and `3`).
- `2` builds all even sums, and one `3` fixes the odd ones. This "2 and 3" trick is common in sum problems.
- Split a problem into small cases and check each case with an example.
- A fake value (like pushing `0`) can work, but writing the `NO` case directly is cleaner and safer.

---

## Tags
`constructive algorithms` `implementation` `math` `number theory` `800-rating`

---

*Part of my daily DSA / Codeforces journey. One problem at a time. One concept at a time.* 🚀
