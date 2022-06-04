#include <iostream>

using namespace std;

class Solution {
	public:
		unsigned reverse(int x) {
			int divisor = x / 10;
			int remainder = x % 10;
			unsigned result = 0;

			while(remainder !=0 || divisor != 0) {
				result = result * 10 + remainder;
				remainder = divisor % 10;
				divisor = divisor / 10;
			}

			return result;
		}
		bool isPalindrome(int x) {
			unsigned reverseNumber = 0;
			if(x < 0 || (x != 0 && x%10 == 0)) {
				return false;
			}

			reverseNumber = reverse(x);
			if(reverseNumber == x) {
				return true;
			}
			return false;
		}
};

int main(int argc, char *argv[])
{
	Solution s;
	cout << s.isPalindrome(2147483647) << endl;
	return 0;
}
