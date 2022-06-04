#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxIncreaseKeepingSkyline(vector<vector<int>> &grid) {
    int n = grid.size();
    vector<int> r_max(n);
    vector<int> c_max(n);
    int r = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        r_max[i] = max(r_max[i], grid[i][j]);
        c_max[j] = max(c_max[j], grid[i][j]);
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        r += min(r_max[i], c_max[j]) - grid[i][j];
      }
    }
    return r;
  }
};

int main() {
  Solution s;
  vector<vector<int>> grid = {
      {3, 0, 8, 4}, {2, 4, 5, 7}, {9, 2, 6, 3}, {0, 3, 1, 0}};
  cout << s.maxIncreaseKeepingSkyline(grid) << endl;

  return 0;
}
