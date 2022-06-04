#include <iostream>

using namespace std;

class Solution {
public:
    bool divisorGame(int N) {
			int num = N;
			bool flag = false;
			int x = 1;
			while(x < num) {
				if(num%x == 0) {
					flag = !flag;
					num -= x;
					x = 1;
				} else {
					x ++;
				}
			}
			return flag;
    }
};

int main(int argc, char *argv[])
{
	Solution s;
	cout << s.divisorGame(3) << endl;
	return 0;
}
