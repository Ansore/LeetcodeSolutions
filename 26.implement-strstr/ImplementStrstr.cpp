#include <iostream>
#include <string>

using namespace std;

class Solution {
	public:
		bool isEqual(string haystack, string needle, int i) {
			for(int j = 1; j < needle.size(); j ++) {
				if((i+j > haystack.size()) || (!(haystack[i+j] == needle[j]))) {
					return false;
				}
			}
			return true;
		}
		int strStr(string haystack, string needle) {
			if(needle.length() == 0) {
				return 0;
			}
			for(int i = 0; i < haystack.length(); i ++) {
				if(haystack[i] == needle[0] && isEqual(haystack, needle, i)) {
					return i;
				}
			}
			return -1;
		}
};

int main(int argc, char *argv[])
{
	Solution s;
	cout << s.strStr("aaaaaaa", "bba") << endl;
	return 0;
}
