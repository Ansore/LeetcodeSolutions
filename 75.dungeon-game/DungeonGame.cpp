#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		int calculateMinimumHP(vector<vector<int>>& dungeon) {
			int n = dungeon.size();
			int m = dungeon[0].size();

			vector<vector<int>> dp(n, vector<int>(m, 0));

			dp[n-1][m-1] = 1-dungeon[n-1][m-1];

			for(int i=n-1; i >= 0; i --) {
				for(int j=m-1; j >= 0; j --) {
					if(i!=n-1 && j!=m-1) {
						dp[i][j] = min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j];
					} else if(i != n-1) {
						dp[i][j] = dp[i+1][j]-dungeon[i][j];
					} else if(j != m-1) {
						dp[i][j] = dp[i][j+1]-dungeon[i][j];
					}
					if(dp[i][j] < 1) {
						dp[i][j] = 1;
					}
				}
			}
			return dp[0][0];
		}
};

int main(int argc, char *argv[])
{

	vector<vector<int>> nums = {{0, 0}};
	Solution s;
	cout << s.calculateMinimumHP(nums) << endl;
	return 0;
}
