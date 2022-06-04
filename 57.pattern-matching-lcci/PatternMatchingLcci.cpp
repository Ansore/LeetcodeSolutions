#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool patternMatching(string pattern, string value) {
		int countA = 0;
		int countB = 0;
		for(auto c : pattern) {
			if(c == 'a') {
				countA ++;
			} else {
				countB ++;
			}
		}
		if(countA < countB) {
			swap(countA, countB);
			for(char& ch : pattern) {
				ch = (ch == 'a'?'b':'a');
			}
		}
		if(value.empty()) {
			return countB == 0;
		}
		if(pattern.empty()) {
			return false;
		}
		for(int lenA = 0; countA * lenA <= value.size(); lenA ++) {
			int rest = value.size() - countA * lenA;
			if((countB==0 && rest == 0) || (countB!=0 && rest%countB==0)) {
				int lenB = (countB==0?0:rest/countB);
				int pos = 0;
				bool correst = true;
				string valueA, valueB;
				for(char ch:pattern) {
					if(ch=='a') {
						string sub = value.substr(pos, lenA);
						if(!valueA.size()) {
							valueA = move(sub);
						} else if(valueA != sub) {
							correst = false;
							break;
						}
						pos += lenA;
					} else {
						string sub = value.substr(pos, lenB);
						if(!valueB.size()) {
							valueB = move(sub);
						} else if(valueB != sub) {
							correst = false;
							break;
						}
						pos += lenB;
					}
				}
				if(correst && valueA != valueB) {
					return true;
				}
			}
		}

		return false;
    }
};

int main(int argc, char *argv[])
{
	Solution s;
	cout << s.patternMatching("abba", "dogcatcatdog") << endl;
	cout << s.patternMatching("", "") << endl;
	return 0;
}
