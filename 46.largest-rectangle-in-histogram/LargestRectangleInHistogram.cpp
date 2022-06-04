#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		int largestRectangleArea(vector<int>& heights) {
			int result = 0;
			for(int i = 0; i < heights.size(); i ++) {
				int he = heights[i];
				int j = i - 1;
				int times = 1;
				while(j >= 0 && heights[j] >= he) {
					times ++;
					j --;
				}
				j = i + 1;
				while(j < heights.size() && heights[j] >= he) {
					times ++;
					j ++;
				}
				int area = times * he;
				result = area>result? area : result;
			}
			return result;
		}
};

int main(int argc, char *argv[])
{
	vector<int> nums = {2, 2, 5, 6, 2, 3};
	Solution s;
	cout << s.largestRectangleArea(nums) << endl;
	return 0;
}

