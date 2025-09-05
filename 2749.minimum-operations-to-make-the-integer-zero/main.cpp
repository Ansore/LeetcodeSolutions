class Solution {
public:
  int makeTheIntegerZero(int num1, int num2) {
    long long x = num1;
    long long y = num2;

    for (int k = 0; k <= 60; k++) {
      long long target = x - k * y;
      if (target < 0)
        continue;
      int bits = __builtin_popcountll(target);
      if (bits <= k && target >= k) {
        return k;
      }
    }
    return -1;
  }
};
