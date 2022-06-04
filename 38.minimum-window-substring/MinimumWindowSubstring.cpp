#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
	public:
		string minWindow(string s, string t) {
			unordered_map<char, int> map;
			for(auto c:t){
				map[c] ++;
			}

			int left = 0, cnt = 0, maxlen = s.size() + 1, start = left;

			for(int i = 0; i < s.size(); i ++) {
				if(--map[s[i]] >= 0) {
					cnt ++;
				}
				while(cnt == t.size()) {
					if(maxlen>i-left+1) {
						maxlen = i - left + 1;
						start = left;
					}
					if(++map[s[left]] > 0) {
						cnt --;
					}
					left++;
				}
			}

			return maxlen==s.size()+1?"":s.substr(start, maxlen);
		}
};

int main(int argc, char *argv[])
{
	Solution s;
	cout << s.minWindow("ADOBECODEBANC", "ABC") << endl;
	return 0;
}
