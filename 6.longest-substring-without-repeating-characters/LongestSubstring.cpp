#include <iostream>
#include <string>
#include <hash_set>

using namespace std;
using namespace __gnu_cxx;

class Solution {
	public:
		int lengthOfLongestSubstring(string s) {
			int length = s.length();
			hash_set<int> hs;
			int maxLength = 0;
			int currentLength = 0;

			if(s.empty()){
				return 0;
			}

			for(int i = 0; i < length; i ++) {
				for(int j = i; j < length; j ++){
					if(hs.find((int) s[j]) != hs.end()){
						// 已经出现这个元素了
						hs.clear();
						if(maxLength < currentLength) {
							maxLength = currentLength;
						}
						currentLength = 0;
						break;
					} else {
						// 未出现这个元素
						currentLength ++;
						hs.insert((int) s[j]);
						// 如果最大元素还没有初始化
						if(maxLength == 0) {
							maxLength ++;
						}
					}
				}
			}
			return maxLength;
		}
};

int main(int argc, char *argv[])
{
	string s = "dvdf";
	Solution solution;
	cout << solution.lengthOfLongestSubstring(s) << endl;
	return 0;
}
