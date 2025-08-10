#include <algorithm>
#include <vector>
#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
  int minFallingPathSum(vector<vector<int>> &matrix) {
    int n = matrix.size();
    if (n == 1)
      return matrix[0][0];
    int ret = INT_MAX;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
      dp[0][i] = matrix[0][i];
    }
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (0 == j) {
          dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + 1]) + matrix[i][j];
        } else if (n - 1 == j) {
          dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + matrix[i][j];
        } else {
          dp[i][j] =
              min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i - 1][j + 1]) +
              matrix[i][j];
        }
      }
    }
    for (int i = 0; i < n; i++) {
      if (dp[n - 1][i] < ret) {
        ret = dp[n - 1][i];
      }
    }
    return ret;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<int>> matrix = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
  cout << Solution().minFallingPathSum(matrix) << endl;
  return 0;
}
