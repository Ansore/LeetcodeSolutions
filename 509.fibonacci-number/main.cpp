#include <iostream>
class Solution {
public:
  int fib(int n) {
    if (n < 2)
      return n;
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
  }
};

int main(int argc, char *argv[]) {
  std::cout << Solution().fib(2) << std::endl;
  std::cout << Solution().fib(3) << std::endl;
  std::cout << Solution().fib(4) << std::endl;
  std::cout << Solution().fib(12) << std::endl;
  return 0;
}
