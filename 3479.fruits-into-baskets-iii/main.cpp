#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets) {
    int ret = fruits.size();
    int n = baskets.size();
    int m = sqrt(baskets.size());
    int section = (n + m - 1) / m;
    vector<int> maxV(section);
    for (int i = 0; i < n; i++) {
      maxV[i / m] = max(maxV[i / m], baskets[i]);
    }
    for (auto fruit : fruits) {
      for (int sec = 0; sec < section; sec++) {
        if (maxV[sec] < fruit) {
          continue;
        }
        int choose = 0;
        maxV[sec] = 0;
        for (int i = 0; i < m; i++) {
          int pos = sec * m + i;
          if (pos < n && baskets[pos] >= fruit && !choose) {
            baskets[pos] = 0;
            choose = 1;
          }
          if (pos < n) {
            maxV[sec] = max(maxV[sec], baskets[pos]);
          }
        }
        ret--;
        break;
      }
    }
    return ret;
  }
};

int main(int argc, char *argv[]) {
  // vector<int> fruits = {3, 6, 1};
  // vector<int> baskets = {6, 4, 7};
  // cout << Solution().numOfUnplacedFruits(fruits, baskets) << endl;
  vector<int> fruits = {4, 2, 5};
  vector<int> baskets = {3, 5, 4};
  cout << Solution().numOfUnplacedFruits(fruits, baskets) << endl;
  return 0;
}
