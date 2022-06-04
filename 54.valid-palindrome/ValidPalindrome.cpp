#include <iostream>
#include <string>

using namespace std;

class Solution {
	public:
		bool isPalindrome(string s) {
			if(s.length() == 0) {
				return true;
			}
			string str;
			for (int i = 0; i < s.length(); ++i) {
				if(isdigit(s[i]) || isalpha(s[i])) {
					str += tolower(s[i]);
				}
			}
			int left = 0;
			int right = str.length() - 1;
			while(left < right) {
				if(str[left] != str[right]) {
					return false;
				}
				left ++;
				right --;
			}
			return true;
		}
};

int main(int argc, char *argv[])
{
	Solution s;
	cout << s.isPalindrome("A9 man, a plan, a canal:Panama") << endl;
	return 0;
}
