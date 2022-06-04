#include <iostream>

using namespace std;

class Solution {
public:
    int sumNums(int n) {
		return n == 0 ? 0 : n + sumNums(n-1);
    }
};

int main(int argc, char *argv[])
{
	Solution s;
	cout << s.sumNums(9) << endl;
	return 0;
}
