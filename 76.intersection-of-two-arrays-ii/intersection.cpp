#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
	public:
		vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
			if(nums1.size() > nums2.size()) {
				intersect(nums2, nums1);
			}
			vector<int> res;
			if(nums1.empty() || nums2.empty()) {
				return res;
			}
			unordered_map<int, int> map;
			for(int num:nums1) {
				map[num] ++;
			}
			for(int num:nums2) {
				if(map.count(num)) {
					res.push_back(num);
					map[num] --;
				}
				if(map[num] == 0) {
					map.erase(num);
				}
			}
			return res;
		}
};

int main(int argc, char *argv[])
{
	return 0;
}
