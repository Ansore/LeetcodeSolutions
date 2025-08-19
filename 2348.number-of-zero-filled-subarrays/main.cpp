#include <vector>

using namespace std;

/* timeout */
/*
class Solution {
public:
  long long zeroFilledSubarray(vector<int> &nums) {
    long long result = 0;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i; j < nums.size(); j++) {
        if (nums[j] == 0) {
          result++;
        } else {
          break;
        }
      }
    }
    return result;
  }
};
*/

class Solution {
public:
  long long zeroFilledSubarray(vector<int> &nums) {
    long long result = 0;
    long long n = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 0) {
        n++;
      } else {
        result += (n * (n + 1)) / 2;
        n = 0;
      }
    }
    result += (n * (n + 1)) / 2;
    return result;
  }
};
