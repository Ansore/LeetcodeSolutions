#include <iostream>
#include <limits.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	private:
		int maxSum = INT_MIN;
	public:
		int maxPathSum(TreeNode* root) {
			maxGain(root);
			return maxSum;
		}
		int maxGain(TreeNode* node) {
			if(node == nullptr) {
				return 0;
			}

			// 递归计算左右子节点的最大贡献值
			// 只有在最大贡献值大于0时，才会选取对应子节点
			int leftGain = max(maxGain(node->left), 0);
			int rightGain = max(maxGain(node->right), 0);

			// 节点的最大路径和取决于该节点的值与该节点的左右子节点的最大贡献值
			int priceNewPath = node->val + leftGain + rightGain;

			// 更新答案
			maxSum = max(maxSum, priceNewPath);

			return node->val + max(leftGain, rightGain);
		}
};

int main(int argc, char *argv[])
{

	return 0;
}
