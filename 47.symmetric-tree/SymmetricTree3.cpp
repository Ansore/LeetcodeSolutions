#include <iostream>
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
		bool isSymmetric(TreeNode* root) {
			queue<TreeNode*> qe;
			qe.push(root);
			qe.push(root);
			while(!qe.empty()) {
				TreeNode* p = qe.front();
				qe.pop();
				TreeNode* q = qe.front();
				qe.pop();

				if(p == nullptr && q == nullptr) continue;
				if(p == nullptr || q == nullptr) return false;
				if(p->val != q->val) return false;

				qe.push(p->left);
				qe.push(q->right);

				qe.push(p->right);
				qe.push(q->left);
			}
			return true;
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
