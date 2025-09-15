#include <string>

using namespace std;

class Solution {
public:
  int maxFreqSum(string s) {
    int count[26] = {0};
    int y[5] = {0, 4, 8, 14, 20};
    int f[21] = {1,  2,  3,  5,  6,  7,  9,  10, 11, 12, 13,
                 15, 16, 17, 18, 19, 21, 22, 23, 24, 25};
    int res = 0;
    int max = 0;
    for (char c : s) {
      count[c - 'a']++;
    }
    for (int i : y) {
      if (max < count[i]) {
        max = count[i];
      }
    }
    res = max;
    max = 0;
    for (int i : f) {
      if (max < count[i]) {
        max = count[i];
      }
    }
    return res + max;
  }
};
