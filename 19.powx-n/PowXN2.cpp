#include <iostream>
#include <float.h>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
			if(x==1.0 || n == 0) {
				return 1;
			}
			if(x==-1.0) {
				return n%2==0?1:-1;
			}
			long num = n;
			if(num < 0) {
				x = 1/x;
				num = -num;
			}
			double res = 1;
			while(num) {
				if(num & 1) {
					res *= x;
				}
				x *= x;
				num >>= 1;
			}
			return res;
    }
};

int main(int argc, char *argv[])
{
	Solution s;
	cout << s.myPow(2.0, 10) << endl;;
	return 0;
}
