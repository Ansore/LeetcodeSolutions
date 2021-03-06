#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
	public:
		bool isMatch(string s, string p) {
			int m = s.length();
			int n = p.length();

			vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));

			dp[0][0] = true;

			for(int i = 1; i <= n; i ++) {
				if(p[i-1] == '*') dp[0][i] = true;
				else break;
			}
			for(int i = 1; i <= m; i ++) {
				for(int j = 1; j <= n; j ++) {
					if(p[j-1] == '*') {
						dp[i][j] = dp[i][j-1] || dp[i-1][j];
					} else {
						if(p[j-1]=='?' || s[i-1]==p[j-1]) {
							dp[i][j] = dp[i-1][j-1];
						} else {
							dp[i][j] = false;
						}
					}
				}
			}
			return dp[m][n];
		}
};

int main(int argc, char *argv[])
{
	Solution s;
	cout << s.isMatch("aa", "*") << endl;
	return 0;
}
