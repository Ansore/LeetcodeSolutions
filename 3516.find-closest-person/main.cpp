#include <cstdlib>

using namespace std;

class Solution {
public:
  int findClosest(int x, int y, int z) {
    int r1 = abs(x - z);
    int r2 = abs(y - z);
    if (r1 < r2)
      return 1;
    else if (r1 > r2)
      return 2;
    return 0;
  }
};
