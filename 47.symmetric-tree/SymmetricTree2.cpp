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
		bool check(TreeNode* p, TreeNode* q) {
			if(q == nullptr && p == nullptr) return true;
			if(q == nullptr || p == nullptr) return false;
			return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
		}
		bool isSymmetric(TreeNode* root) {
			return check(root, root);
		}
};

int main(int argc, char *argv[])
{
	TreeNode* node1 = new TreeNode(5);
	TreeNode* node2 = new TreeNode(4);
	TreeNode* node3 = new TreeNode(1);
	TreeNode* node4 = new TreeNode(1);
	TreeNode* node5 = new TreeNode(4);
	TreeNode* node6 = new TreeNode(2);
	TreeNode* node7 = new TreeNode(2);

	node1->left = node2;
	node1->right = node3;
	//node2->left = node4;
	node2->right = node4;
	//node3->left = node6;
	node3->right = node5;
	node4->left = node6;
	node5->left = node7;

	Solution s;
	cout << s.isSymmetric(node1) << endl;
	return 0;
}
