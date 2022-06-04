#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
		int maxScore = 0;
		int mx = A[0];
		for (int i = 1; i < A.size(); i ++) {
			maxScore = max(maxScore, mx+A[i]-i);
			mx = max(mx, A[i]+i);
		}
		return maxScore;
    }
};

int main(int argc, char *argv[])
{
	vector<int> nums = {8, 1, 5, 2, 6};
	Solution s;
	cout << s.maxScoreSightseeingPair(nums) << endl;
	return 0;
}
