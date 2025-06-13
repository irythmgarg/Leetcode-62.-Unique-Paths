class Solution {
public:

    // Recursive function to count all unique paths from (i, j) to bottom-right corner (m-1, n-1)
    int Allpaths(int i, int j, int m, int n) {
        // If out of bounds, return 0 (invalid path)
        if (i >= m || j >= n)
            return 0;

        // If destination is reached, return 1 (valid path)
        if (i == m - 1 && j == n - 1) {
            return 1;
        }

        // Move down (i+1, j) and right (i, j+1), and sum both paths
        return Allpaths(i + 1, j, m, n) + Allpaths(i, j + 1, m, n);
    }

    // Entry function that starts from top-left (0,0) and tries to reach (m-1, n-1)
    int uniquePaths(int m, int n) {
        return Allpaths(0, 0, m, n);
    }
};
