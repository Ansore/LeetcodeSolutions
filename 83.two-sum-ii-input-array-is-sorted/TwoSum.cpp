#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		vector<int> twoSum(vector<int>& numbers, int target) {
			int l = 0;
			int r = numbers.size()-1;
			while(l < r) {
				if(numbers[l] + numbers[r] == target) {
					return {l+1, r+1};
				} else if(numbers[l] + numbers[r] < target) {
					l ++;
				} else {
					r --;
				}
			}
			return {};
		}
};

int main(int argc, char *argv[]) {
	vector<int> numbers = {2, 7, 11, 15};
	Solution s;
	vector<int> res = s.twoSum(numbers, 9);
	for(auto r:res) {
		cout << r << " ";
	}
	cout << endl;
	return 0;
}
