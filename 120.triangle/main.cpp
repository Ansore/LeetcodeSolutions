#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int minimumTotal(vector<vector<int>> &triangle) {
    if (triangle.size() == 1)
      return triangle[0][0];
    int ret = 10000; // minimux
    vector<vector<int>> dp;
    dp.push_back(triangle[0]);

    for (int i = 1; i < triangle.size(); i++) {
      vector<int> tmp;
      for (int j = 0; j < triangle[i].size(); j++) {
        if (0 == j) {
          // first element
          tmp.push_back(dp[i - 1][0] + triangle[i][0]);
        } else if (triangle[i].size() - 1 == j) {
          // last element
          tmp.push_back(dp[i - 1][dp[i - 1].size() - 1] + triangle[i][j]);
        } else {
          // mid element
          tmp.push_back(min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j]);
        }
      }
      dp.push_back(tmp);
    }

    for (auto x : dp[dp.size() - 1]) {
      if (x < ret) {
        ret = x;
      }
    }
    return ret;
  }
};
