#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
			vector<bool> res;
			int maxNum = 0;
			for(int i = 0; i < candies.size(); i ++) {
				if(candies[i] > maxNum) maxNum = candies[i];
			}
			for(int i = 0; i < candies.size(); i ++) {
				if(candies[i] + extraCandies >= maxNum) {
					res.push_back(true);
				} else {
					res.push_back(false);
				}
			}
			return res;
		}
};

int main(int argc, char *argv[])
{
	vector<int> candies = {4, 2, 1, 1, 3};
	Solution s;
	vector<bool> re = s.kidsWithCandies(candies, 1);
	for(int i = 0; i < re.size(); i ++) {
		cout << re[i] << " ";
	}
	return 0;
}
