#include <vector>

using namespace std;

class Solution {
public:
  int largestPerimeter(vector<int> &nums) {
    int n = nums.size();
    int res = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
          if ((nums[i] + nums[j] > nums[k]) && (nums[i] + nums[k] > nums[j]) &&
              (nums[j] + nums[k] > nums[i])) {
            int z = nums[i] + nums[j] + nums[k];
            if (z > res) {
              res = z;
            }
          }
        }
      }
    }
    return res;
  }
};
