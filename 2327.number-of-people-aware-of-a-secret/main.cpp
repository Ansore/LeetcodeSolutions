#include <deque>

using namespace std;

class Solution {
public:
  int peopleAwareOfSecret(int n, int delay, int forget) {
    deque<long long> mem(forget, 0);
    const int MOD = 1e9 + 7;
    long long ans = 0, sum = 0;
    mem[forget - 1] = 1;
    for (int i = 2; i <= n; i++) {
      sum = (sum + mem[forget - delay]) - mem[0];
      mem.pop_front();
      mem.push_back(sum);
      if (i > n - forget)
        ans = (ans + sum) % MOD;
    }
    return ans + ((n == forget) ? 1 : 0);
  }
};
