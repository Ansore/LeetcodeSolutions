#include <cmath>
class Solution {
public:
  int maximum69Number(int num) {
    int max = num, tmp = num, i = 0;
    while (tmp) {
      if (tmp % 10 == 6) {
        int x = num + 3 * pow(10, i);
        if (max < x) {
          max = x;
        }
      }
      tmp /= 10;
      i ++;
    }
    return max;
  }
};
