#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 *
 * 中序遍历不行
 * 中序遍历不能确认一棵二叉树的形状
 * 例如[5,4,1,null,1,null,4,2,null,2,null]
 * 就会出错
 *
 *
 */
class Solution {
	public:
		void inorder(TreeNode* node, vector<int>& nums) {
			if(node == nullptr) {
				// 填充子树
				nums.push_back(-8888);
				return;
			}
			if(node->left == nullptr && node->right == nullptr) {
				nums.push_back(node->val);
				return;
			}
			inorder(node->left, nums);
			nums.push_back(node->val);
			inorder(node->right, nums);
		}

		bool isSymmetric(TreeNode* root) {
			vector<int> nums;
			inorder(root, nums);
			int i = 0, j = nums.size() - 1;

			for(int m = 0; m < nums.size(); m ++) {
				cout << nums[m] << " ";
			}
			cout << endl;
			while(i < j) {
				if(nums[i] != nums[j]) {
					return false;
				}
				i ++;
				j --;
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
