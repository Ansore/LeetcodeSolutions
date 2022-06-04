#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
	public:
		int getValue(char& c) {
			switch (c) {
				case '(':
					return 1;
				case ')':
					return -1;
				case '[':
					return 2;
				case ']':
					return -2;
				case '{':
					return 3;
				case '}':
					return -3;
				default:
					cout << "error" << endl;
					exit(1);
			}
		}
		bool isValid(string s) {
			if(s.size() == 0) {
				return true;
			}
			if(s.size() % 2 == 1) {
				return false;
			}
			int sum = 0;
			stack<int> charStack;
			for(int i = 0; i < s.size(); i ++) {
				if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
					int x = getValue(s[i]);
					charStack.push(x);
					sum += x;
				} else {
					if(charStack.size() == 0) {
						return false;
					} else {
						int temp = charStack.top();
						if(temp != -getValue(s[i])) {
							return false;
						}
						sum -= temp;
						charStack.pop();
					}
				}
			}
			if(sum != 0) {
				return false;
			}
			return true;
		}
};

int main(int argc, char *argv[])
{
	Solution s;
	cout << s.isValid("){") << endl;
	return 0;
}
