// https://leetcode-cn.com/problems/unique-paths-ii/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() < 1 || obstacleGrid[0].size() < 1) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        long long dp[m][n] = {0};
        for (int i = 0; i < m; ++i) {
            if (obstacleGrid[i][0]) {
                break;
            } else {
                dp[i][0] = 1;
            }
        }

        for (int i = 0; i < n; ++i) {
            if (obstacleGrid[0][i]) {
                break;
            } else {
                dp[0][i] = 1;
            }
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = obstacleGrid[i][j] ? 0 : dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};