#include <iostream>
#include <vector>

using namespace std;

// 空间优化， 修改原数组
class Solution {
	public:
		int minPathSum(vector<vector<int>>& grid) {
			int m = grid.size();
			if(m <= 0) {
				return 0;
			}
			int n = grid[0].size();

			for(int i = 1; i < n; i ++) {
				grid[0][i] = grid[0][i-1] + grid[0][i];
			}
			for(int i = 1; i < m; i ++) {
				grid[i][0] = grid[i-1][0] + grid[i][0];
			}
			for(int i = 1; i < m; i ++) {
				for(int j = 1; j < n; j ++) {
					grid[i][j] = min(grid[i-1][j] + grid[i][j], grid[i][j-1]+grid[i][j]);
				}
			}
			return grid[m-1][n-1];
		}
};

int main(int argc, char *argv[])
{
	vector<vector<int>> nums = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
	Solution s;
	cout << s.minPathSum(nums) << endl;
	return 0;
}
