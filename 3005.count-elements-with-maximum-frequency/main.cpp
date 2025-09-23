#include <vector>

using namespace std;

class Solution {
public:
  int maxFrequencyElements(vector<int> &nums) {
    int max = 0, res = 0;
    int table[100] = {0};
    for (int n : nums) {
      table[n - 1]++;
      if (table[n - 1] > max) {
        max = table[n - 1];
      }
    }
    for (int n : table) {
      if (n == max) {
        res += n;
      }
    }
    return res;
  }
};
