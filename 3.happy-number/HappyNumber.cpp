#include <iostream>

using namespace std;

class Solution {
	public:

		int getSumOfSquares(int n) {
			int divisor = n / 10;
			int remainder = n % 10;
			int sum = 0;
			while(remainder != 0 || divisor != 0) {
				sum += (remainder*remainder);
				remainder = divisor % 10;
				divisor = divisor / 10;
			}
			return sum;
		}

		bool isHappy(int n) {

			// 最大循环次数
			int maxNum = 100000;
			int sum = n;
			for(int count = 0; count < maxNum; count ++) {
				if(sum == 1) {
					return true;
				}
				sum = getSumOfSquares(sum);
			}

			return false;
		}
};

int main(int argc, char *argv[])
{
	Solution s;
	cout << s.isHappy(19);

	return 0;
}
