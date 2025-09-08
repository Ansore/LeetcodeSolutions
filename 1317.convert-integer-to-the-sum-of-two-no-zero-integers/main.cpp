#include <vector>

using namespace std;

class Solution {
public:
  bool have_zero(int x) {
    while (x) {
      if (x % 10 == 0) {
        return true;
      }
      x /= 10;
    }
    return false;
  }
  vector<int> getNoZeroIntegers(int n) {
    for (int i = 1; i <= n / 2; i++) {
      if (have_zero(i) || have_zero(n - i))
        continue;
      return {i, n - i};
    }
    return {};
  }
};
