#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sumZero(int n) {
    vector<int> ret;
    if (n % 2 == 1) {
      ret.push_back(0);
    }
    for (int i = n / 2; i > 0; i--) {
      ret.push_back(i);
      ret.push_back(-i);
    }
    return ret;
  }
};
