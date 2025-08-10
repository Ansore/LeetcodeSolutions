#include <vector>

using namespace std;

class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    if (obstacleGrid.size() < 1 || obstacleGrid[0].size() < 1) {
      return 0;
    }
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    bool flag = false;
    for (int i = 0; i < m; i++) {
      if (flag) {
        dp[i][0] = 0;
        continue;
      }
      if (obstacleGrid[i][0] == 0) {
        dp[i][0] = 1;
      } else {
        dp[i][0] = 0;
        flag = true;
      }
    }
    flag = false;
    for (int i = 0; i < n; i++) {
      if (flag) {
        dp[0][i] = 0;
        continue;
      }
      if (obstacleGrid[0][i] == 0) {
        dp[0][i] = 1;
      } else {
        dp[0][i] = 0;
        flag = true;
      }
    }
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        if (obstacleGrid[i][j] == 0) {
          if (dp[i - 1][j] == 0 && dp[i][j - 1] == 0) {
            dp[i][j] = 0;
          } else if (dp[i - 1][j] == 0) {
            dp[i][j] = dp[i][j - 1];
          } else if (dp[i][j - 1] == 0) {
            dp[i][j] = dp[i - 1][j];
          } else {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
          }
        } else {
          dp[i][j] = 0;
        }
      }
    }
    return dp[m - 1][n - 1];
  }
};
