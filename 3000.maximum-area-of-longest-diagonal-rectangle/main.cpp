#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
  int areaOfMaxDiagonal(vector<vector<int>> &dimensions) {
    int res = 0;
    long long max = 0.0;
    for (auto dimension : dimensions) {
      long long tmp = (dimension[0] * dimension[0]) + (dimension[1] * dimension[1]);
      if (tmp > max) {
        max = tmp;
        res = dimension[0] * dimension[1];
      } else if (tmp == max) {
        int x = dimension[0] * dimension[1];
        if (x > res) {
          res = x;
        }
      }
    }
    return res;
  }
};
