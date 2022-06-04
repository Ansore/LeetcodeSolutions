#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
		TreeNode* build(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir) {

			if(pl>pr || il>ir) {
				return nullptr;
			}
			// 找到根节点
			TreeNode* root = new TreeNode(preorder[pl]);
			int mid = -1;
			for (int i = il; i < ir+1; i ++) {
				if(preorder[pl] == inorder[i]) {
					mid=i;
					break;
				}
			}
			root->left = build(preorder, inorder, pl+1, pl+(mid-il), il, mid-1);
			root->right = build(preorder, inorder, pl+(mid-il)+1, pr, mid+1, ir);
			
			return root;
		}
		TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
			return build(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
		}
};

void prebian(TreeNode* node) {
	cout << node->val << " ";
	if(node->left != nullptr) {
		prebian(node->left);
	}
	if(node->right != nullptr){
		prebian(node->right);
	}
}

int main(int argc, char *argv[])
{
	Solution s;
	vector<int> preorder = {3, 9, 20, 15, 7};
	vector<int> inorder = {9, 3, 15, 20, 7};

	TreeNode* tree = s.buildTree(preorder, inorder);
	prebian(tree);
	return 0;
}
