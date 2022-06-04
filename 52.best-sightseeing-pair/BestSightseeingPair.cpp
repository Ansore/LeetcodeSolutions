#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
		int maxScore = 0;
		for (int i = 0; i < A.size(); i ++) {
			for(int j = i+1; j < A.size(); j ++) {
				int score = A[i] + A[j] + i - j;
				if(score > maxScore) {
					maxScore = score;
				}
			}
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
