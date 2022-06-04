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
		void inorder(TreeNode* node, vector<int>& v) {
			if(node->left != nullptr) {
				inorder(node->left, v);
			}
			v.push_back(node->val);
			if(node->right != nullptr) {
				inorder(node->right, v);
			}
		}
		bool isValidBST(TreeNode* root) {
			cout << "-----";
			if(root == nullptr) {
				return true;
			}
			vector<int> in;
			inorder(root, in);
			cout << in.size() << endl;
			for(int i = 1; i < in.size(); i ++) {
				cout << in[i-1] << endl;
				if(in[i-1] >= in[i]) {
					return false;
				}
			}
			return true;
		}
};

int main(int argc, char *argv[]) {
	TreeNode* t1 = new TreeNode(10);
	TreeNode* t2 = new TreeNode(5);
	TreeNode* t3 = new TreeNode(15);
	TreeNode* t4 = new TreeNode(6);
	TreeNode* t5 = new TreeNode(20);
	TreeNode* t6 = new TreeNode(1);
	TreeNode* t7 = new TreeNode(1);

	t1->left = t2;
	t1->right=t3;
	t3->left=t4;
	t3->right=t5;

	Solution s;

	s.isValidBST(t1);
	return 0;
}
