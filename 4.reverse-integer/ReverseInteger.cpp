#include <iostream>

using namespace std;

class Solution {
	public:
		int reverse(int x) {
			int divisor = x / 10;
			int remainder = x % 10;
			int result = 0;

			while(remainder !=0 || divisor != 0) {
				cout << result << endl;
				result = result * 10 + remainder;
				remainder = divisor % 10;
				divisor = divisor / 10;
			}

			return result;
		}
};

int main(int argc, char *argv[])
{
	Solution s;
	cout << s.reverse(-123);
	return 0;
}
