#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		int subarraysDivByK(vector<int>& A, int K) {
			int res = 0;
			int n = A.size();
			for(int i = 0; i < n; i ++) {
				for(int j = i; j < n; j ++) {
					int sum = 0;
					for(int m = i; m <= j; m ++) {
						sum += A[m];
					}
					if(sum % K == 0) {
						res ++;
					}
				}
			}
			return res;
		}
};

int main(int argc, char *argv[])
{
	//vector<int> A = {4, 5, 0, -2, -3, 1};
	vector<int> A = {1};
	int k = 5;
	Solution s;
	cout << s.subarraysDivByK(A, k) << endl;
	return 0;
}
