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
			string longstString = strs[0];
			//longstString.erase(0, longstString.length());
			for(int j = 1; j < strs.size(); j ++) {
				if(longstString.length() == 0 || strs[j].length() == 0) {
					return "";
				}
				for(int i = 0; i < longstString.length(); i ++) {
					if(longstString[i] != strs[j][i]) {
						longstString.erase(i, longstString.length());
						break;
					}
					// 如果遍历到str最后一位
					if(i > strs[j].length()-1 && strs[j].length() < longstString.length()) {
						longstString.erase(i+1, longstString.length());
					}
				}
			}
			return longstString;
		}
};

int main(int argc, char *argv[])
{
	Solution s;
	vector<string> strs = {"ca", "a"};
	cout << s.longestCommonPrefix(strs) << endl;
	return 0;
}
