# Leetcode-62.-Unique-Paths
# Unique Paths - LeetCode 62

## Problem Statement

Given two integers `m` and `n`, return the number of possible unique paths that the robot can take to reach the bottom-right corner of an `m x n` grid.

The robot can only move **either down or right** at any point in time.

### Constraints:

* `1 <= m, n <= 100`

## Example

```
Input: m = 3, n = 7
Output: 28
```

---

## Approach 1: Recursive Backtracking (Naive Recursive Solution)

### Description:

This recursive approach explores all possible paths from the top-left corner `(0, 0)` to the bottom-right corner `(m-1, n-1)` by moving either right or down.

### Code Snippet:

```cpp
int Allpaths(int i, int j, int m, int n) {
    if (i >= m || j >= n)
        return 0;
    if (i == m - 1 && j == n - 1)
        return 1;
    return Allpaths(i + 1, j, m, n) + Allpaths(i, j + 1, m, n);
}

int uniquePaths(int m, int n) {
    return Allpaths(0, 0, m, n);
}
```

### Time Complexity:

* **Exponential**, approximately `O(2^(m+n))`

### Space Complexity:

* **O(m + n)** (due to recursion stack)

### Pros:

* Simple to understand

### Cons:

* Highly inefficient for large inputs due to repeated subproblem calculations

---

## Approach 2: Dynamic Programming (Bottom-Up Tabulation)

### Description:

This DP approach builds a 2D grid `dp` where each cell `(i, j)` represents the number of unique paths to that point. The result is computed iteratively based on paths from the top and left.

### Code Snippet:

```cpp
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) dp[i][0] = 1;
    for (int i = 0; i < n; i++) dp[0][i] = 1;

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}
```

### Time Complexity:

* **O(m \* n)**

### Space Complexity:

* **O(m \* n)** (can be optimized to `O(n)` with 1D array)

### Pros:

* Efficient and avoids redundant computations

### Cons:

* Requires additional space

---

## Author

**Ridham Garg**
B.Tech Computer Engineering, Thapar University
LeetCode Username: [ridhamgarg](https://leetcode.com/)

---

## Summary Table

| Approach      | Time Complexity | Space Complexity | Efficient |
| ------------- | --------------- | ---------------- | --------- |
| Recursive     | O(2^(m+n))      | O(m+n)           | No        |
| Dynamic Prog. | O(m \* n)       | O(m \* n)        | Yes       |

---

Feel free to optimize further with memoization or combinatorial formulas for even better performance!
