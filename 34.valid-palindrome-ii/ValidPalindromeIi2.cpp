#include <iostream>
#include <string>

using namespace std;

class Solution {
	public:
		bool validSubString(string s, int i, int j) {
			while(i < j) {
				if(s[i] != s[j]) {
					return false;
				}
				i ++;
				j --;
			}
			return true;
		}
		bool validPalindrome(string s) {
			int i = 0, j = s.length()-1;
			while(i < j) {
				if(s[i] != s[j]) {
					return validSubString(s, i+1, j) || validSubString(s, i, j-1);
				}
				i ++;
				j --;
			}
			return true;
		}
};

int main(int argc, char *argv[])
{
	Solution s;
	cout << s.validPalindrome("absa") << endl;
	return 0;
}

