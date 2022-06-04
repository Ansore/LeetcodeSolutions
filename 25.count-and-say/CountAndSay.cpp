#include <iostream>
#include <string>

using namespace std;

class Solution {
	public:
		string countAndSay(int n) {
			if(n == 1) {
				return "1";
			}
			string s;
			string str = countAndSay(n-1);

			char c = str[0];
			int count = 0;
			for(int i = 0; i < str.size(); i ++) {
				if(str[i] != c) {
					s += to_string(count) + c;
					count = 1;
					c = str[i];
				} else {
					count ++;
				}
			}

			s += to_string(count) + c;
			return s;
		}
};

int main(int argc, char *argv[])
{
	Solution s;
	cout << s.countAndSay(10) << endl;
	return 0;
}
