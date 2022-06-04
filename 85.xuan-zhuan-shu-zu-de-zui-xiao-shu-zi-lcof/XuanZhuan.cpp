#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		int minArray(vector<int>& numbers) {
			int l = 0;
			int r = numbers.size()-1;

			while(l < r) {
				int mid = (r-l)/2+l;
				if(numbers[mid] < numbers[r]) {
					r = mid;
				} else if(numbers[mid] > numbers[r]) {
					l = mid+1;
				} else {
					r --;
				}
			}
			return numbers[l];
		}
};

int main(int argc, char *argv[])
{
	vector<int> numbers = {3, 4, 5, 1, 2};
	Solution s;
	cout << s.minArray(numbers) << endl;
	return 0;
}
