#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
  private:
    TreeNode *t1, *t2, *pre;
  public:
    void recoverTree(TreeNode* root) {
      inorder(root);
      int temp = t1->val;
      t1->val = t2->val;
      t2->val = temp;
    }
    void inorder(TreeNode* root) {
      if(root == nullptr) {
        return;
      }
      inorder(root->left);
      if(pre != nullptr && pre->val > root->val) {
        if(t1 == nullptr) {
          t1 = pre;
        }
        t2 = root;
      }
      pre = root;
      inorder(root->right);
    }
};
