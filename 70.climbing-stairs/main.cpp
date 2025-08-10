#include <iostream>
class Solution {
public:
  int climbStairs(int n) {
    if (1 <= n) return 1;
    int dp[n + 1];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i < n + 1; i++) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
  }
};

int main(int argc, char *argv[]) {
  std::cout << Solution().climbStairs(2) << std::endl;
  std::cout << Solution().climbStairs(3) << std::endl;
  std::cout << Solution().climbStairs(4) << std::endl;
  return 0;
}
