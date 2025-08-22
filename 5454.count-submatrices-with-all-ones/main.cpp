#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
  int numSubmat(vector<vector<int>> &mat) {
    int m = mat.size();
    int n = mat[0].size();
    int x = 0;
    int ret = 0;
    vector<vector<int>> left(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
      x = 0;
      for (int j = 0; j < n; j++) {
        if (mat[i][j] == 1)
          x++;
        else
          x = 0;
        left[i][j] = x;
      }
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        int minx = INT_MAX;
        for (int k = i; k >= 0; k--) {
          minx = min(left[k][j], minx);
          ret += minx;
        }
      }
    }
    return ret;
  }
};
