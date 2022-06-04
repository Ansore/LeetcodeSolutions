#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
  private:
    set<vector<int>> res;
    vector<int> temp;
  public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
      dfs(0, nums);
      return vector<vector<int>>(res.begin(), res.end());
    }
    void dfs(int cur, vector<int>& nums) {
      if(temp.size() >= 2) res.insert(temp);
      for(int i = cur; i < nums.size(); i ++) {
        if(!temp.empty() && temp.back() > nums[i]) continue;
        temp.push_back(nums[i]);
        dfs(i+1, nums);
        temp.pop_back();
      }
    }
};

int main(int argc, char *argv[])
{
  Solution s;
  vector<int> nums = {4, 6, 7, 7};
  vector<vector<int>> res = s.findSubsequences(nums);
  for(int i = 0; i < res.size(); i ++) {
    for(int j = 0; j < res[i].size(); j ++) {
      cout << res[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
