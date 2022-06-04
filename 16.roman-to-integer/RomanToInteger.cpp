#include <iostream>

using namespace std;

class Solution {
	public:
		int getValue(char& c) {
			switch (c) {
				case 'I':
					return 1;
				case 'V':
					return 5;
				case 'X':
					return 10;
				case 'L':
					return 50;
				case 'C':
					return 100;
				case 'D':
					return 500;
				case 'M':
					return 1000;
				default:
					cout << "error" << endl;
					exit(1);
			}
		}
		int romanToInt(string s) {
			if(s.size() == 0) {
				return 0;
			}
			int preNum = getValue(s[0]);
			int sum = 0;
			for(int i = 1; i < s.size(); i ++) {
				int num = getValue(s[i]);
				if(preNum < num) {
					sum -= preNum;
				} else {
					sum += preNum;
				}
				preNum = num;
			}
			sum += preNum;
			return sum;
		}
};

int main(int argc, char *argv[])
{
	Solution s;
	cout << s.romanToInt("MCMXCIV");
	return 0;
}
