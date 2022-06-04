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
    int depth(TreeNode* node) {
      if(node == nullptr) return 0;
      int lh = depth(node->left);
      int rh = depth(node->right);
      if(lh >= 0 && rh >= 0 && abs(lh-rh) <= 1) return max(lh, rh) + 1;
      else return -1;
    }
    bool isBalanced(TreeNode* root) {
      return depth(root) >= 0;
    }
};

int main(int argc, char *argv[])
{
  return 0;
}
