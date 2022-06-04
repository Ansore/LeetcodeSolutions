#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
	public:
		int findTheLongestSubstring(string s) {
			int ans = 0;
			int status = 0;
			int n = s.length();

			// 32位 (0000)_2 ~ (1111)_2 存储 a,e,i,o,u出现的次数
			vector<int> pos(1<<5, -1);
			pos[0] = 0;

			for(int i = 0; i < n; i ++) {
				if(s[i]=='a') {
					status ^= 1 << 0;
				} else if(s[i]=='e') {
					status ^= 1 << 1;
				} else if(s[i] == 'i') {
					status ^= 1 << 2;
				} else if(s[i] == 'o') {
					status ^= 1 << 3;
				} else if(s[i] == 'u') {
					status ^= 1 << 4;
				}

				if(~pos[status]) {
					ans = max(ans, i + 1 - pos[status]);
				} else {
					pos[status] = i + 1;
				}
			}

			return ans;
		}
};

int main(int argc, char *argv[])
{
	Solution s;
	cout << s.findTheLongestSubstring("eleetminicoworoep") << endl;
	return 0;
}
