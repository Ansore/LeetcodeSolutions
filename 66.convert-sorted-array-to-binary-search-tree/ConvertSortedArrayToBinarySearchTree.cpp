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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildTree(nums, 0, nums.size()-1);
    }

		TreeNode* buildTree(vector<int>& nums, int low, int heigh) {
			if(low > heigh) {
				return nullptr;
			}
			int mid = low + (heigh - low) / 2;
			TreeNode* root = new TreeNode(nums[mid]);
			root->left = buildTree(nums, low, mid-1);
			root->right = buildTree(nums, mid+1, heigh);
			return root;
		}
};

int main(int argc, char *argv[])
{
	vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
	Solution s;
	TreeNode* root = s.sortedArrayToBST(nums);
	return 0;
}
