#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int minCostClimbingStairs(vector<int> &cost) {
    int n = cost.size();
    if (n < 2)
      return 0;
    if (n == 2)
      return min(cost[0], cost[1]);
    int dp[n + 1];
    dp[0] = cost[0];
    dp[1] = cost[1];
    for (int i = 2; i < n; i++) {
      dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
    }
    dp[n] = min(dp[n - 1], dp[n - 2]);
    return dp[n];
  }
};

class Solution2 {
public:
  int minCostClimbingStairs(vector<int> &cost) {
    int n = cost.size();
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i < n + 1; i++) {
      dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }
    return dp[n];
  }
};

int main(int argc, char *argv[]) {
  vector<int> v1 = {10, 15, 20};
  vector<int> v2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
  cout << Solution2().minCostClimbingStairs(v1) << endl;
  cout << Solution2().minCostClimbingStairs(v2) << endl;
  return 0;
}
