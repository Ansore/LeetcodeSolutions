#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int findBestValue(vector<int>& arr, int target) {
		sort(arr.begin(), arr.end());
		int n = arr.size();
		vector<int> pre(n+1);
		for (int i = 1; i <= n; ++i) {
			pre[i] = pre[i-1] + arr[i-1];
		}

		int r = *max_element(arr.begin(), arr.end());
		int ans = 0;
		int diff = target;
		for (int i = 1; i <= r; ++i) {
			auto iter = lower_bound(arr.begin(), arr.end(), i);
			int cur = pre[iter-arr.begin()] + (arr.end()-iter) * i;
			if(abs(cur - target) < diff) {
				ans = i;
				diff = abs(cur-target);
			}
		}
		return ans;
	}
};

int main(int argc, char *argv[])
{
	vector<int> arr = {60864,25176,27249,21296,20204};
	int target = 56803;
	Solution s;
	cout << s.findBestValue(arr, target) << endl;
	return 0;
}
