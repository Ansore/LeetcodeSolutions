#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		int minimumTotal(vector<vector<int>>& triangle) {
			int n = triangle.size();
			for (int i = n-2; i >= 0; i --) {
				for(int j = 0; j < triangle[i].size(); j ++) {
					triangle[i][j] = min(triangle[i+1][j], triangle[i+1][j+1]) + triangle[i][j];
				}
			}
			return triangle[0][0];
		}
};

int main(int argc, char *argv[])
{
	vector<vector<int>> nums = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
	Solution s;
	cout << s.minimumTotal(nums) << endl;
	return 0;
}
