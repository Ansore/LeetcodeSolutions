#include <iostream>

using namespace std;

class Solution {
	public:
		int lengthOfLastWord(string s) {
			int n = s.length();
			if(n == 0) {
				return 0;
			}
			while(s[n-1] == ' ') {
				n --;
				if(n <= 0) {
					return 0;
				}
			}
			int count = 0;
			for(int i = n - 1; i >= 0; i --) {
				if(s[i] != ' ') {
					count ++;
				} else {
					return count;
				}
			}
			return count;
		}
};

int main(int argc, char *argv[])
{
	Solution s;
	cout << s.lengthOfLastWord("a ") << endl;
	return 0;
}
