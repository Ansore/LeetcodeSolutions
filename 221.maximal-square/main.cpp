#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
  int maximalSquare(vector<vector<char>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int ret = INT_MIN;
    if (m < 1 || n < 1)
      return 0;
    if (m < 2 && n < 2)
      return matrix[0][0] - '0';

    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
      dp[i][0] = matrix[i][0] - '0';
      if (dp[i][0] > ret) {
        ret = dp[i][0];
      }
    }
    for (int i = 0; i < n; i++) {
      dp[0][i] = matrix[0][i] - '0';
      if (dp[0][i] > ret) {
        ret = dp[0][i];
      }
    }

    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        if (matrix[i][j] != '0' && matrix[i - 1][j] != '0' &&
            matrix[i][j - 1] != '0' && matrix[i - 1][j - 1] != '0') {
          dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
        } else {
          dp[i][j] = matrix[i][j] - '0';
        }
        if (dp[i][j] > ret) {
          ret = dp[i][j];
        }
      }
    }
    return ret * ret;
  }
};
