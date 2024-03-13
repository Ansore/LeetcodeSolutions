struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class FindElements {
private:
  TreeNode *root;

public:
  void initNode(TreeNode *node) {
    if (node == nullptr) {
      return;
    }
    if (node->left != nullptr) {
      node->left->val = 2 * node->val + 1;
    }
    if (node->right != nullptr) {
      node->right->val = 2 * node->val + 2;
    }
    initNode(node->left);
    initNode(node->right);
  }
  FindElements(TreeNode *root) {
    root->val = 0;
    this->root = root;
    initNode(root);
  }

  bool findNode(int target, TreeNode *node) {
    if (node == nullptr) {
      return false;
    }
    if (node->val == target) {
      return true;
    }
    return findNode(target, node->left) | findNode(target, node->right);
  }

  bool find(int target) { return findNode(target, this->root); }
};
