#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
		bool hasPathSum(TreeNode* root, int sum) {
			if(root == nullptr) {
				return false;
			}
			if(root->left==nullptr && root->right == nullptr) {
				return sum == root->val;
			}
			return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
		}
};

int main(int argc, char *argv[])
{
	//TreeNode* node1 = new TreeNode(5);
	//TreeNode* node2 = new TreeNode(4);
	//TreeNode* node3 = new TreeNode(8);
	//TreeNode* node4 = new TreeNode(11);
	//TreeNode* node5 = new TreeNode(13);
	//TreeNode* node6 = new TreeNode(4);
	//TreeNode* node7 = new TreeNode(7);
	//TreeNode* node8 = new TreeNode(2);
	//TreeNode* node9 = new TreeNode(1);

	//node1->left = node2;
	//node1->right = node3;
	//node2->left = node4;
	//node3->left = node5;
	//node3->right = node6;
	//node6->right = node9;
	//node4->left = node7;
	//node6->right = node8;

	TreeNode* node1 = new TreeNode(1);
	TreeNode* node2 = new TreeNode(2);
	node1->left = node2;
	Solution s;

	cout << s.hasPathSum(node1, 1) << endl;
	return 0;
}
