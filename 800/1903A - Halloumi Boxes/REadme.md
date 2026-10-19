# 1903A - Halloumi Boxes

## Problem Link

[Codeforces 1903A - Halloumi Boxes](https://codeforces.com/problemset/problem/1903/A)

## Problem Summary

Given an array of `n` integers and an integer `k`, we can reverse any contiguous subarray whose length does not exceed `k`.

The task is to determine whether it is possible to sort the array in non-decreasing order using this operation any number of times.

## Approach 1: Brute Force

A straightforward way to think about this problem is to consider the possible reversals and try to make the array sorted.

However, trying every possible subarray reversal is unnecessary. By examining the value of `k`, we can determine whether sorting is possible without simulating the operations.

### Key Observation

**Case 1: `k == 1`**

We can only reverse a subarray containing one element. This does not change the array.

Therefore, the array must already be sorted in non-decreasing order.

- `[1, 2, 3]` → `YES`
- `[3, 1, 2]` → `NO`

**Case 2: `k > 1`**

We can reverse a subarray of length `2`, which is equivalent to swapping two adjacent elements.

Since any array can be sorted using adjacent swaps, the answer is always `YES`.

### Algorithm

1. Read `n`, `k`, and the array.
2. If `k > 1`, print `YES`.
3. Otherwise, check whether the array is already sorted.
4. Print `YES` if it is sorted; otherwise, print `NO`.

### Complexity

- **Time Complexity:** `O(n)` per test case in the worst case.
- **Space Complexity:** `O(1)` auxiliary space, excluding input storage.

## Approach 2: Optimal Solution

The key observation is that we do not need to perform any reversals or simulate sorting operations.

The value of `k` alone determines whether sorting is always possible.

- If `k > 1`, the array can always be sorted.
- If `k == 1`, the array must already be sorted.

We can implement this logic directly using the standard C++ function `is_sorted()`.

### Algorithm

1. Read `n`, `k`, and the array.
2. If `k > 1` or the array is already sorted, print `YES`.
3. Otherwise, print `NO`.

### Complexity

- **Time Complexity:** `O(n)` per test case in the worst case.
- **Space Complexity:** `O(1)` auxiliary space, excluding input storage.

## Test Cases

### Test Case 1

**Input**
```text
3 2
3 1 2
```

**Output**
```text
YES
```

**Explanation:** Since `k > 1`, adjacent elements can be swapped to sort the array.

### Test Case 2

**Input**
```text
3 1
1 2 3
```

**Output**
```text
YES
```

**Explanation:** The array is already sorted.

### Test Case 3

**Input**
```text
3 1
3 1 2
```

**Output**
```text
NO
```

**Explanation:** When `k == 1`, no element can change its position.

### Test Case 4

**Input**
```text
4 4
6 4 2 1
```

**Output**
```text
YES
```

**Explanation:** Since `k > 1`, the array can be sorted using adjacent swaps.

## Key Learnings

- Understand the constraints before choosing an algorithm.
- Identify how the allowed operations affect the array.
- Adjacent swaps are sufficient to sort any array.
- A key observation can eliminate unnecessary operations.
- The optimal solution does not always require a more complex algorithm.

## Tags

`#Codeforces` `#DSA` `#ProblemSolving` `#Greedy` `#BruteForce` `#Sorting` `#CPlusPlus`
