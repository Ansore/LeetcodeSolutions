#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// 前缀和
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

		unordered_map<int, int> map;
		map[0] = 1;
		int res = 0;
		int pre = 0;
		for(int i = 0; i < nums.size(); i ++) {
			pre += nums[i];
			if(map.find(pre-k) != map.end()) {
				res += map[pre-k];
			}
			map[pre] ++;
		}
		return res;
    }
};

int main(int argc, char *argv[])
{
	vector<int> nums = {1,1,1, 2};
	int k = 2;
	Solution s;
	cout << s.subarraySum(nums, k) << endl;
	return 0;
}
