#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
  double largestTriangleArea(vector<vector<int>> &points) {
    int n = points.size();
    double res = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
          int x1 = points[i][0], y1 = points[i][1];
          int x2 = points[j][0], y2 = points[j][1];
          int x3 = points[k][0], y3 = points[k][1];
          double a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
          double b = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
          double c = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
          double p = (a + b + c) / 2;
          double s = sqrt(p * (p - a) * (p - b) * (p - c));
          res = max(res, s);
        }
      }
    }
    return res;
  }
};
