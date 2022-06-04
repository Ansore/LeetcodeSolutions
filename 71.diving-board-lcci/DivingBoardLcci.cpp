#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		vector<int> divingBoard(int shorter, int longer, int k) {
			if(k == 0) {
				return {0};
			}
			if(shorter == longer) {
				return {shorter*k};
			}
			vector<int> res(k+1, 0);
			for (int i = 0; i < k+1; ++i) {
				res[i] = longer*i + shorter*(k-i);
			}
			return res;
		}
};

int main(int argc, char *argv[])
{
	Solution s;
	vector<int> res = s.divingBoard(1, 2, 3);
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << endl;
	}
	return 0;
}
