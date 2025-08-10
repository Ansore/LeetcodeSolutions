#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> productQueries(int n, vector<vector<int>> &queries) {
    vector<int> powers;
    vector<int> result;
    for (int i = 0; i < n; i++) {
      if (((n >> i) & 0x1) == 0x1) {
        powers.push_back((int)pow(2, i));
      }
    }
    for (auto que : queries) {
      int sum = 0;
      for (int i = que[0]; i <= que[1]; i++) {
        sum *= powers[i];
      }
      sum %= 1000000007;
      result.push_back(sum);
    }
    return result;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<int>> v1 = {{0, 1}, {2, 2}, {0, 3}};
  cout << Solution().productQueries(15, v1).size() << endl;
  return 0;
}
