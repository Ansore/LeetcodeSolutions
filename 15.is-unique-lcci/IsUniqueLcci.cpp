#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isUnique(string astr) {
		unordered_set<int> set;

		for(int i = 0; i < astr.size(); i ++) {
			if(set.count((int) astr[i])) {
				return false;
			}
			set.insert((int) astr[i]);
		}

		return true;
    }
};

int main(int argc, char *argv[])
{
	Solution s;
	cout << s.isUnique("asdu");
	return 0;
}
