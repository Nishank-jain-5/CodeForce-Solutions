# Codeforces 1899A: Game with Integers

![Difficulty](https://img.shields.io/badge/Rating-800-brightgreen)
![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)
![Topic](https://img.shields.io/badge/Topic-Math%20%2F%20Games-orange)

**Problem Link:** [Codeforces 1899A](https://codeforces.com/problemset/problem/1899/A)
**Time Limit:** 1 second | **Memory Limit:** 256 MB

---

## Problem Summary

Two players, **Vanya** and **Vova**, play a game with an integer `n`.

- On a turn, a player can **add 1** or **subtract 1** from the current number.
- They play **one after another**. **Vanya always starts**.
- If **after Vanya's move** the number is **divisible by 3**, Vanya wins.
- If **10 moves** pass and Vanya has not won, **Vova wins**.

**Task:** If both players play in the best possible way, tell who wins: `First` (Vanya) or `Second` (Vova).

### Input
- `t`: number of test cases
- For each test case: one integer `n` (`1 <= n <= 1000`)

### Output
For each test case, print `First` if Vanya wins, otherwise print `Second`.

### Example

```
Input
6
1
3
5
100
999
1000

Output
First
Second
First
First
Second
First
```

---

## Key Observation

Vanya only needs to make the number divisible by 3 **once**, and he moves first. So the whole game depends on **his very first move**.

Every integer `n` has one of three remainders when divided by 3:

| `n % 3` | What can Vanya do on move 1? | Result |
|---------|------------------------------|--------|
| `1` | Subtract 1, number becomes divisible by 3 | **First** wins |
| `2` | Add 1, number becomes divisible by 3 | **First** wins |
| `0` | Any move (+1 or -1) breaks divisibility | Game continues... |

### What if `n % 3 == 0`?

Vanya must move, so the number becomes `n + 1` or `n - 1` (not divisible by 3).
Now Vova can simply **undo Vanya's move** and bring the number back to `n` (which is divisible by 3).

Then it is Vanya's turn again, and he must move away again. This repeats forever, so Vanya **never** gets a number divisible by 3 after his own move.

After 10 moves, **Vova wins**.

> So the "10 moves" rule is just a story. The answer is decided on move 1.

---

## Dry Run

```
n = 1    -> 1 % 3 = 1 -> Vanya subtracts 1 -> 0 (divisible by 3)  -> First
n = 3    -> 3 % 3 = 0 -> Vanya moves to 2 or 4, Vova moves back to 3 -> Second
n = 5    -> 5 % 3 = 2 -> Vanya adds 1 -> 6 (divisible by 3)        -> First
n = 100  -> 100 % 3 = 1 -> Vanya subtracts 1 -> 99                 -> First
n = 999  -> 999 % 3 = 0 -> Vova keeps undoing                      -> Second
n = 1000 -> 1000 % 3 = 1 -> Vanya subtracts 1 -> 999               -> First
```

---

## My Approach

### Idea
Check whether Vanya can reach a multiple of 3 in **one move**.

1. Check if `n + 1` is divisible by 3.
2. Check if `n - 1` is divisible by 3.
3. If **either** is true, print `First`.
4. Otherwise print `Second`.

## Shorter Version (Same Idea)

If `n + 1` or `n - 1` is divisible by 3, then `n` itself is **not** divisible by 3.
So the whole condition can be written as just:

```cpp
if(n % 3 != 0) cout << "First\n";
else cout << "Second\n";
```

| | My Code | Shorter Code |
|---|---|---|
| Idea | Check `n+1` and `n-1` | Check `n % 3 != 0` |
| Time | `O(1)` | `O(1)` |
| Space | `O(1)` | `O(1)` |
| Readability | Shows the game move clearly | Short and clean |

Both are correct.

---

## Edge Cases to Remember

- `n = 1`: remainder 1, Vanya subtracts 1 and gets 0, which is divisible by 3. Answer: `First`.
- `n = 3` and other multiples of 3: Vanya always loses. Answer: `Second`.
- `n = 1000` (the largest value): remainder 1, so `First`.
- Do **not** try to simulate all 10 moves. It is not needed.
- A common mistake is thinking the number of moves (10) matters. It does not.

---

## What I Learned

- In game problems, look at the **first move** first. Sometimes the game is already decided there.
- When one player can always **undo** the other player's move, that player is safe.
- Before writing a long simulation, try small examples and find the **pattern** (here: remainder when divided by 3).
- A simple math idea (`n % 3`) can replace a lot of code.

---

## Tags
`math` `games` `number-theory` `implementation` `800-rating`

---

*Part of my daily DSA / Codeforces journey. One problem at a time. One concept at a time.* 🚀
