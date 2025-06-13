class Solution {
public:
    int uniquePaths(int m, int n) {
        // If there's only one row or one column, there's only one unique path
        if (m == 1 || n == 1)
            return 1;

        // Create a 2D DP table initialized with 0
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Optional but unnecessary assignments:
        // These lines set base cases but will be overwritten below
        dp[0][1] = 1;
        dp[1][0] = 1;

        // Initialize the first column with 1 (only one way to move vertically)
        for (int i = 0; i < m; i++)
            dp[i][0] = 1;

        // Initialize the first row with 1 (only one way to move horizontally)
        for (int i = 0; i < n; i++)
            dp[0][i] = 1;

        // Fill the DP table using the recurrence relation:
        // dp[i][j] = paths from top (i-1, j) + paths from left (i, j-1)
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        // Return the value at bottom-right corner, which is the total unique paths
        return dp[m - 1][n - 1];
    }
};
