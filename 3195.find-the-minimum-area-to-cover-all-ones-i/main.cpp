#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int minimumArea(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    int i = 0, j = 0, li = -1, lj = -1, ri = -1, rj = -1;
    while (i < m && j < n) {
      for (int k = i; k < m; k++) {
        if (grid[k][j] == 1) {
          li = i;
        }
      }

      for (int k = j; k < n; k++) {
        if (grid[i][k] == 1) {
          lj = j;
        }
      }

      if (li == -1 && i < m)
        j++;
      if (lj == -1 && j < n)
        i++;
    cout << "li:" << li << " lj:" << lj << " ri:" << ri << " rj:" << rj << endl;

      cout << i << " " << m << " " << j << endl;
      if (li != -1 && lj != -1) {
        break;
      }
    }
    cout << "li:" << li << " lj:" << lj << " ri:" << ri << " rj:" << rj << endl;
    if (li == -1 || lj == -1) {
      return 0;
    }
    i = m - 1;
    j = n - 1;
    while (i >= 0 && j >= 0) {
      for (int k = m - 1; k >= 0; k--) {
        if (grid[k][j] == 1) {
          ri = i;
        }
      }

      for (int k = n - 1; k >= 0; k--) {
        if (grid[i][k] == 1) {
          rj = j;
        }
      }

      if (ri == -1 && i >= 0)
        j--;
      if (rj == -1 && j >= 0)
        i--;
      if (ri != -1 && rj != -1) {
        break;
      }
    }
    return (ri - li + 1) * (rj - lj + 1);
  }
};

int main(int argc, char *argv[]) {
  vector<vector<int>> grid = {{1}, {1}};
  cout << Solution().minimumArea(grid) << endl;
  return 0;
}
