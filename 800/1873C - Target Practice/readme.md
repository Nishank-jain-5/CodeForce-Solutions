# Codeforces 1873C: Target Practice

![Difficulty](https://img.shields.io/badge/Rating-800-brightgreen)
![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)
![Topic](https://img.shields.io/badge/Topic-Matrix%20%2F%20Implementation-orange)

**Problem Link:** [Codeforces 1873C](https://codeforces.com/problemset/problem/1873/C)
**Time Limit:** 1 second | **Memory Limit:** 256 MB

---

## Problem Summary

A `10 x 10` target is made of **five rings**. Each ring gives different points:

- Outermost ring: **1 point**
- Next ring: **2 points**
- Next ring: **3 points**
- Next ring: **4 points**
- Center ring: **5 points**

Vlad shot some arrows. The target is given as a grid:

- `X` means there is an arrow in that cell.
- `.` means there is no arrow.

**Task:** Find the **total points** Vlad got.

### Input
- `t`: number of test cases
- For each test case: **10 lines**, each with **10 characters** (`X` or `.`)

### Output
For each test case, print the total score.

### Example

```
Input (shortened: 4 test cases)
4
(test 1: 7 arrows on different rings)
(test 2: no arrows)
(test 3: one arrow in the center)
(test 4: all cells are X)

Output
17
0
5
220
```

*(The full grids are on the Codeforces problem page.)*

---

## Key Observation

Look at the target from outside to inside. Each ring is like a **square layer**:

```
1 1 1 1 1 1 1 1 1 1
1 2 2 2 2 2 2 2 2 1
1 2 3 3 3 3 3 3 2 1
1 2 3 4 4 4 4 3 2 1
1 2 3 4 5 5 4 3 2 1
1 2 3 4 5 5 4 3 2 1
1 2 3 4 4 4 4 3 2 1
1 2 3 3 3 3 3 3 2 1
1 2 2 2 2 2 2 2 2 1
1 1 1 1 1 1 1 1 1 1
```

The points of a cell depend on **how far it is from the nearest edge** of the grid.

For a cell at row `i` and column `j` (counting from `0` to `9`), the distances to the four edges are:

| Edge | Distance |
|------|----------|
| Top | `i` |
| Left | `j` |
| Bottom | `9 - i` |
| Right | `9 - j` |

The nearest edge distance is:

```
d = min(i, j, 9 - i, 9 - j)
```

And the points are:

```
points = d + 1
```

**Why?**
- A cell on the border has `d = 0`, so points = `1`.
- The next layer has `d = 1`, so points = `2`.
- ...
- The center cells have `d = 4`, so points = `5`.

---

## Dry Run

Use the formula `points = min(i, j, 9-i, 9-j) + 1`.

| Cell `(i, j)` | min(i, j, 9-i, 9-j) | Points |
|---------------|---------------------|--------|
| (0, 0) | min(0, 0, 9, 9) = 0 | 1 |
| (2, 7) | min(2, 7, 7, 2) = 2 | 3 |
| (3, 5) | min(3, 5, 6, 4) = 3 | 4 |
| (4, 6) | min(4, 6, 5, 3) = 3 | 4 |
| (4, 4) | min(4, 4, 5, 5) = 4 | 5 |

**Test 1:** arrows at `(0,0)`, `(2,7)`, `(3,5)`, `(4,6)`, `(6,9)`, `(7,2)`, `(9,9)`:

```
1 + 3 + 4 + 4 + 1 + 3 + 1 = 17
```

**Test 4:** all 100 cells are `X`. Count cells in each ring:

```
Ring 1: 36 cells x 1 = 36
Ring 2: 28 cells x 2 = 56
Ring 3: 20 cells x 3 = 60
Ring 4: 12 cells x 4 = 48
Ring 5:  4 cells x 5 = 20

Total = 36 + 56 + 60 + 48 + 20 = 220
```

---

## My Approach

### Idea
Read the grid cell by cell. If a cell has an arrow (`X`), add its ring points using the formula.

1. Create `score = 0`.
2. Read all `10 x 10` characters.
3. If the character is `X`, add `min(i, j, 9-i, 9-j) + 1` to `score`.
4. Print `score`.

### My Code (C++)

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){

        char arr[10][10];

        int score = 0;

        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                cin >> arr[i][j];

                if(arr[i][j] == 'X'){
                    score += min({i,j,9-i,9-j}) + 1;
                }

            }
        }

        cout << score << endl;

    }

}
```

### Complexity
- **Time:** `O(100)` per test case, which is `O(1)` because the grid size is fixed
- **Space:** `O(100)` for the grid, which is also `O(1)`

---

## Another Way (If-Else Rings)

Instead of the formula, we can check ring by ring:

```cpp
int check(int i, int j){
    if(i==0 || j==0 || i==9 || j==9) return 1;
    if(i==1 || j==1 || i==8 || j==8) return 2;
    if(i==2 || j==2 || i==7 || j==7) return 3;
    if(i==3 || j==3 || i==6 || j==6) return 4;
    return 5;
}
```

We check the outer rings first, so a cell like `(1, 9)` is already caught by the first line and gets `1` point, not `2`.

| | My Code | If-Else Way |
|---|---|---|
| Idea | One formula with `min` | Check each ring one by one |
| Time | `O(1)` per cell | `O(1)` per cell |
| Space | `O(1)` | `O(1)` |
| Readability | Short, needs the idea | Longer, but very clear |

Both are correct.

---

## Edge Cases to Remember

- **No arrows:** score is `0`.
- **All arrows** (every cell is `X`): score is `220`.
- **Corner cells** like `(0, 9)` or `(9, 0)`: they are on the outer ring (1 point).
- **Center cells** `(4,4)`, `(4,5)`, `(5,4)`, `(5,5)`: these 4 cells give 5 points each.
- **Indexes start from 0**, so the last row and column are `9`. That is why we use `9 - i` and `9 - j`.
- `cin >> char` skips new lines and spaces, so reading the grid is safe.

---

## What I Learned

- When a 2D grid has **layers** (like rings), think about the **distance from the edge**.
- `min(i, j, 9-i, 9-j)` is a useful trick for "how deep is this cell from the border".
- In C++, `min({a, b, c, d})` can compare many numbers at once (needs `<algorithm>`).
- Drawing the grid on paper first made the pattern (1, 2, 3, 4, 5) easy to see.
- Always check the total on the **full grid** (220). It is a good test for the formula.

---

## Tags
`implementation` `matrix` `math` `800-rating`

---

*Part of my daily DSA / Codeforces journey. One problem at a time. One concept at a time.* 🚀
