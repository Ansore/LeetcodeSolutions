#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
	public:
		bool isInterleave(string s1, string s2, string s3) {
			int n = s1.size();
			int m = s2.size();
			int t = s3.size();
			if(m+n != t) {
				return false;
			}
			auto dp = vector<vector<int>>(s1.size()+1, vector<int>(s2.size()+1, false));
			dp[0][0] = true;
			for (int i = 0; i <= n; i ++) {
				for(int j = 0; j <= m; j ++) {
					int p = i+j-1;
					if(i > 0) {
						dp[i][j] |= (dp[i - 1][j] && s1[i - 1] == s3[p]);
						/* dp[i][j] |= (dp[i-1][j] && s1[i-1] == s3[p]); */
					}
					if(j > 0) {
						dp[i][j] |= (dp[i][j-1] && s2[j-1] == s3[p]);
					}
				}
			}
			return dp[n][m];
		}
};

int main(int argc, char *argv[])
{
	return 0;
}
