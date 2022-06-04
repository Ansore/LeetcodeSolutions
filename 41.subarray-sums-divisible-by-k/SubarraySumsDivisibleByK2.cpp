#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// 前缀和 统计余数
class Solution {
	public:
		int subarraysDivByK(vector<int>& A, int K) {
			unordered_map<int, int> map = {{0,1}};
			int sum = 0;
			int result = 0;
			for(auto a : A) {
				sum += a;
				if(sum < 0) {
					sum = sum % K + K;
				}
				int mod = sum % K;
				result += map[mod];
				map[mod] ++;
			}
			return result;
		}
};

int main(int argc, char *argv[])
{
	//vector<int> A = {4, 5, 0, -2, -3, 1};
	vector<int> A = {-7, 2, 3, 0, -9};
	int k = 3;
	Solution s;
	cout << s.subarraysDivByK(A, k) << endl;
	return 0;
}
