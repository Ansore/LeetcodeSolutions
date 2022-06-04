#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
	public:
		string longestCommonPrefix(vector<string>& strs) {
			if(strs.size() == 0) {
				return "";
			}
			int length = strs[0].size();
			for (int i = 0; i < length; ++i) {
				char c = strs[0][i];
				for(int j = 1; j < strs.size(); j ++) {
					if(i == strs[j].size() || strs[j][i] != c) {
						return strs[0].substr(0, i);
					}
				}
			}
			return strs[0];
		}
};

int main(int argc, char *argv[])
{
	Solution s;
	vector<string> strs = {"ca", "cacc"};
	cout << s.longestCommonPrefix(strs) << endl;
	return 0;
}
