#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int deleteAndEarn(vector<int> &nums) {
    if (nums.size() < 2)
      return nums[0];
    unordered_map<int, int> m;

    for (auto num : nums) {
      m[num] += num;
    }

    vector<int> ns;
    for (auto n : m) {
      ns.push_back(n.first);
    }
    if (ns.size() < 2) {
      return m[ns[0]];
    }

    sort(ns.begin(), ns.end());

    vector<int> dp(ns.size(), 0);
    dp[0] = m[ns[0]];
    if (ns[1] != (ns[0] + 1)) {
      dp[1] = m[ns[0]] + m[ns[1]];
    } else {
      dp[1] = max(dp[0], m[ns[1]]);
    }

    for (int i = 2; i < ns.size(); i++) {
      if (ns[i] != (ns[i - 1] + 1)) {
        dp[i] = max(dp[i - 1], dp[i - 2]) + m[ns[i]];
      } else {
        dp[i] = max(dp[i - 1], m[ns[i]] + dp[i - 2]);
      }
    }
    return dp[ns.size() - 1];
  }
};

int main(int argc, char *argv[]) {
  vector<int> v1 = {8, 10, 4, 9, 1, 3, 5, 9, 4, 10};
  vector<int> v2 = {2, 2, 3, 3, 3, 4};
  vector<int> v3 = {1, 1, 1};

  cout << Solution().deleteAndEarn(v1) << endl;
  cout << Solution().deleteAndEarn(v2) << endl;
  cout << Solution().deleteAndEarn(v3) << endl;
  return 0;
}
