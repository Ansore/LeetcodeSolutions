#include <iostream>
#include <float.h>

using namespace std;

class Solution {
	public:
		double myPow(double x, int n) {
			if(n == 0 || x == 1.0) {
				return 1;
			}
			if(x == -1.0) {
				return n%2==1?-1.0:1.0;
			}
			long num = n;
			if(num < 0) {
				x = 1 / x;
				num = -num;
			}
			long double result = x;
			for(int i = 1; i < num; i ++) {
				result *= x;
				if(result >0 && result < DBL_MIN) {
					return 0;
				}
			}
			return result;
		}
};

int main(int argc, char *argv[])
{
	Solution s;
	cout << s.myPow(-1.0, 300000000);
	//cout << DBL_MIN;
	return 0;
}
