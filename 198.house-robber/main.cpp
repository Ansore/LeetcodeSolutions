#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int rob(vector<int> &nums) {
    int n = nums.size();
    if (n < 2)
      return nums[0];
    if (n < 3)
      return max(nums[0], nums[1]);
    int dp[n + 1];
    dp[0] = nums[0];
    dp[1] = nums[1];
    dp[2] = nums[0] + nums[2];
    for (int i = 3; i < n; i++) {
      dp[i] = max(dp[i - 2], dp[i - 3]) + nums[i];
    }
    dp[n] = max(dp[n - 1], dp[n - 2]);
    return dp[n];
  }
};

class Solution2 {
public:
  int rob(vector<int> &nums) {
    int n = nums.size();
    if (n < 2)
      return nums[0];
    if (n < 3)
      return max(nums[0], nums[1]);
    int dp[n];
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++) {
      dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }
    return dp[n - 1];
  }
};

int main(int argc, char *argv[]) {
  vector<int> v1 = {1, 2, 3, 1};
  vector<int> v2 = {2, 7, 9, 3, 1};
  cout << Solution().rob(v1) << endl;
  cout << Solution().rob(v2) << endl;
  cout << Solution2().rob(v1) << endl;
  cout << Solution2().rob(v2) << endl;
  return 0;
}
