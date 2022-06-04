#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
		if(days.size() == 0 || costs.size() == 0) {
			return 0;
		}

		int dpSize = days[days.size() - 1] + 1;
		int dp[dpSize];
		for(int i = 0; i < dpSize; i ++) {
			dp[i] = 0;
		}
		for(int i = 0; i < days.size(); i ++) {
			dp[days[i]] = INT32_MAX;
		}
		cout << " -----------" << endl;

		for(int i = 1; i < dpSize; i ++) {
			if(dp[i] == 0) {
				dp[i] = dp[i-1];
				continue;
			}

			int n1 = dp[i-1] + costs[0];
			int n7 = i > 7 ? dp[i-7] + costs[1] : costs[1];
			int n30 = i > 30 ? dp[i-30] + costs[2] : costs[2];

			dp[i] = min(n1, min(n7, n30));

			//cout << dp[i] << " ";
		}

		return dp[dpSize-1];
    }
};

int main(int argc, char *argv[])
{
	Solution s;
	vector<int> days = {1, 4, 6, 7, 8, 20};
	vector<int> costs = {2, 7, 15};
	int result = s.mincostTickets(days, costs);
	cout << result << endl;
	return 0;
}
