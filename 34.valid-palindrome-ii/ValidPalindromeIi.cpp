#include <iostream>
#include <string>

using namespace std;

class Solution {
	public:
		bool valid(string s, int i, int j, bool isDeleted) {
			if(i >= j) {
				return true;
			}
			if(s[i] != s[j]) {
				if(isDeleted){
					return false;
				}
				isDeleted = true;
				return valid(s, i+1, j, isDeleted) || valid(s, i, j-1, isDeleted);
			}
			return valid(s, i + 1, j - 1, isDeleted);
		}
		bool validPalindrome(string s) {
			return valid(s, 0, s.length()-1, false);
		}
};

int main(int argc, char *argv[])
{
	Solution s;
	cout << s.validPalindrome("abc") << endl;
	return 0;
}
