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
    int minDepth(TreeNode* root) {
      if(root == nullptr) return 0;
      int left = minDepth(root->left);
      int right = minDepth(root->right);
      return left==0 || right==0 ? 1+left+right : min(left, right)+1;
    }
};

int main(int argc, char *argv[])
{
  return 0;
}
