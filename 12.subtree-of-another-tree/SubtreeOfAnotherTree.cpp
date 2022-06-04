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
		bool isEqual(TreeNode* s, TreeNode* t) {
			if(s == nullptr && t == nullptr) {
				return true;
			}
			if(!t || !s) {
				return false;
			}
			if(s->val == t->val) {
				return isEqual(s->left, t->left) && isEqual(s->right, t->right);
			} else {
				return false;
			}
		}
		bool isSubtree(TreeNode* s, TreeNode* t) {

			if(isEqual(s, t)) {
				return true;
			}
			if(s->left != nullptr && isSubtree(s->left, t)) {
				return true;
			}
			if(s->right != nullptr && isSubtree(s->right, t)) {
				return true;
			}
			return false;
		}
};

int main(int argc, char *argv[])
{
	
	return 0;
}
