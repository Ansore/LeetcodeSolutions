#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
		vector<vector<int>> levelOrder(TreeNode* root) {
			vector<vector<int>> result;
			if(root == nullptr) {
				return result;
			}
			queue<TreeNode*> qe;
			qe.push(root);
			while(!qe.empty()) {
				vector<int> ve;
				int nums = qe.size();
				for(int i = 0; i < nums; i ++) {
					TreeNode* t = qe.front();
					ve.push_back(t->val);
					if(t->left != nullptr) {
						qe.push(t->left);
					}
					if(t->right != nullptr) {
						qe.push(t->right);
					}
					qe.pop();
				}
				result.push_back(ve);
			}
			return result;
		}
};

int main(int argc, char *argv[])
{
	
	return 0;
}
