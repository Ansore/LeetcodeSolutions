#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
  double soupServings(int n) {
    n = ceil((double)n / 25);
    if (n > 179) {
      return 1;
    }
    mem = vector<vector<double>>(n + 1, vector<double>(n + 1));
    return dfs(n, n);
  }

  double dfs(int a, int b) {
    if (a <= 0 && b <= 0) {
      return 0.5;
    }
    if (a <= 0) {
      return 1;
    }
    if (b <= 0) {
      return 0;
    }
    if (mem[a][b] > 0) {
      return mem[a][b];
    }
    mem[a][b] = 0.25 * (dfs(a - 4, b) + dfs(a - 3, b - 1) + dfs(a - 2, b - 2) +
                        dfs(a - 1, b - 3));
    return mem[a][b];
  }

private:
  vector<vector<double>> mem;
};
