#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

	bool isOne(vector<vector<char>>& matrix, int sx, int sy, int ex, int ey) {
		for(int i = sx; i < ex; i ++) {
			for(int j = sy; j < ey; j ++) {
				if(matrix[i][j] == '0') {
					return false;
				}
			}
		}
		return true;
	}

	int getMaxAddIndex(vector<vector<char>>& matrix, int x, int y) {
		int addIndex = 0;
		for (int index = 1; index < matrix.size()-x+1 && index < matrix[x].size()-y+1; index ++) {
			if(isOne(matrix, x, y, x+index, y+index)) {
				addIndex ++;
			}
		}
		return addIndex;
	}

    int maximalSquare(vector<vector<char>>& matrix) {
		if(matrix.size() == 0 || matrix[0].size() == 0) {
			return 0;
		}
		int maxAddIndex = 0;
		for(int i = 0; i < matrix.size() - maxAddIndex+1; i ++) {
			for (int j = 0; j < matrix[i].size() - maxAddIndex+1; j ++) {
				cout << matrix[i][j] << " ";
				if(matrix[i][j] == '1') {
					int temp = getMaxAddIndex(matrix, i, j);
					if(temp > maxAddIndex) {
						maxAddIndex = temp;
					}
				}
			}
			cout << endl;
		}
		return maxAddIndex * maxAddIndex;
    }
};

int main(int argc, char *argv[])
{
	Solution s;
	vector<vector<char> > matrix = {{'1','0','1','0','0'},{'1','1','1','1','1'},{'1','1','1','1','1'},{'1','1','1','1','1'}};
	cout << s.maximalSquare(matrix) << endl;
	return 0;
}
