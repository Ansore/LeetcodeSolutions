#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
	public:
		string decodeString(string s) {
			stack<string> stackStr;
			stack<int> stackNum;
			string cur = "";
			int num = 0;
			for(int i = 0; i < s.length(); i ++) {
				if(s[i] >= '0' && s[i] <= '9') {
					num = num * 10 + s[i] - '0';
				} else if(s[i] == '[') {
					stackNum.push(num);
					num = 0;
					stackStr.push(cur);
					cur.clear();
				} else if(s[i] == ']') {
					int k = stackNum.top();
					stackNum.pop();
					for(int j = 0; j < k; j ++) {
						stackStr.top() += cur;
					}
					cur = stackStr.top();
					stackStr.pop();
				} else {
					cur += s[i];
				}
			}
			return cur;
		}
};

int main(int argc, char *argv[])
{
	Solution s;
	cout << s.decodeString("3[a]2[b1[r]c]") << endl;
	return 0;
}
