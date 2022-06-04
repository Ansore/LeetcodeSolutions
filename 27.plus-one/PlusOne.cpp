#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		vector<int> plusOne(vector<int>& digits) {
			int n = digits.size() - 1;
			while(n >= 0) {
				if(n == 0 && digits[0] == 9) {
					digits.insert(digits.begin(), 0);
					n ++;
				}
				if(digits[n] != 9) {
					digits[n] ++;
					return digits;
				} else {
					if(digits[n-1] != 9) {
						digits[n] = 0;
						digits[n-1] ++;
						return digits;
					} else {
						digits[n] = 0;
						n --;
					}
				}
			}
			return digits;
		}
};

int main(int argc, char *argv[])
{
	Solution s;
	vector<int> v = {1, 9, 9, 9};
	vector<int> r = s.plusOne(v);
	for(int i = 0; i < r.size(); i ++) {
		cout << r[i] << " ";
	}
	cout << endl;
	return 0;
}
