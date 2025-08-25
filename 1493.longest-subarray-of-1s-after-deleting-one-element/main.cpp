#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int longestSubarray(vector<int> &nums) {
    int max = 0, temp = 0, r_max = 0;
    bool del_flag = false;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 1) {
        temp++;
        if (del_flag) {
          r_max++;
        }
      } else {
        if (!del_flag) {
          del_flag = true;
          r_max = 0;
          continue;
        } else {
          temp = r_max;
          r_max = 0;
        }
      }
      if (max < temp) {
        max = temp;
      }
    }
    if (!del_flag)
      max--;
    return max;
  }
};

int main(int argc, char *argv[]) {
  vector<int> v1 = {0, 1, 1, 1, 0, 1, 1, 0, 1};
  cout << Solution().longestSubarray(v1) << endl;
  return 0;
}
