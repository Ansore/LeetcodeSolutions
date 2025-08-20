#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int countSquares(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int result = 0;

    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
      dp[i][0] = matrix[i][0];
      if (matrix[i][0] == 1) {
        result++;
      }
    }
    for (int j = 1; j < n; j++) {
      dp[0][j] = matrix[0][j];
      if (matrix[0][j] == 1) {
        result++;
      }
    }

    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        if (matrix[i][j] == 1) {
          result++;
          if (matrix[i - 1][j] == 1 && matrix[i][j - 1] == 1 &&
              matrix[i - 1][j - 1] == 1) {
            dp[i][j] =
                min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
            result += dp[i][j] - 1;
          } else {
            dp[i][j] = 1;
          }
        }
      }
    }
    return result;
  }
};
