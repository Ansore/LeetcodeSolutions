#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
			vector<int> rec;
			for(auto& row : matrix) {
				for(int it : row) {
					rec.push_back(it);
				}
			}
			sort(rec.begin(), rec.end());
			return rec[k-1];
    }
};

int main(int argc, char *argv[]) {
	return 0;
}
