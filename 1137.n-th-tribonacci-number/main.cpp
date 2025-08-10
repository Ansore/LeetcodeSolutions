#include <iostream>
class Solution {
public:
  int tribonacci(int n) {
    if (n < 2)
      return n;
    if (n == 2)
      return 1;
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= n; i++) {
      dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    return dp[n];
  }
};

int main(int argc, char *argv[]) {
  std::cout << Solution().tribonacci(4) << std::endl;
  std::cout << Solution().tribonacci(25) << std::endl;
  return 0;
}
