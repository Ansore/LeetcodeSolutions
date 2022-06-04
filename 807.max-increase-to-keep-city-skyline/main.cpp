#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxIncreaseKeepingSkyline(vector<vector<int>> &grid) {
    int n = grid.size();
    int r = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int v_max = grid[i][j];
        int h_max = grid[i][j];
        for (int k = 0; k < n; k++) {
          if (v_max < grid[i][k] && j != k) {
            v_max = grid[i][k];
          }
          if (h_max < grid[k][j] && i != k) {
            h_max = grid[k][j];
          }
        }
        r += (min(v_max, h_max) - grid[i][j]);
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
