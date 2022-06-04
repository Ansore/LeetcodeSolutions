#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
		if(x == 1 || x == 0) {
			return x;
		}
		int left = 0;
		int right = x / 2 + 1;
		while(left < right) {
			int mid = (right - left) / 2 + left;
			if(x / mid == mid || ((x / mid > mid) && (x / (mid + 1) < (mid + 1)))) {
				return mid;
			} else {
				if(x / mid > mid) {
					left = mid;
				} else {
					right = mid;
				}
			}
		}
		return -1;
    }
};

int main(int argc, char *argv[])
{
	Solution s;
	cout << s.mySqrt(8);
	return 0;
}
