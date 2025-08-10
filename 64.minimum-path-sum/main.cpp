#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void printGrid(vector<vector<int>> &grid) {
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        cout << grid[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl;
    cout << endl;
  }
  int minPathSum(vector<vector<int>> &grid) {
    if (grid.size() < 1 || grid[0].size() < 1)
      return 0;
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = grid[0][0];
    for (int i = 1; i < m; i++) {
      dp[i][0] = dp[i - 1][0] + grid[i][0];
    }
    for (int i = 1; i < n; i++) {
      dp[0][i] = dp[0][i - 1] + grid[0][i];
    }
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        printGrid(dp);
      }
    }
    return dp[m - 1][n - 1];
  }
};
