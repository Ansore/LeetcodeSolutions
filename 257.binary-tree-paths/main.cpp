#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  private:
    vector<string> res;
  public:
    vector<string> binaryTreePaths(TreeNode* root) {
      path(root, "");
      return res;
    }
    void path(TreeNode* node, string temp) {
      if(node == nullptr) return;
      if(node->left == nullptr && node->right == nullptr) {
        temp = temp + to_string(node->val);
        res.push_back(temp);
        temp = "";
      }
      temp = temp + to_string(node->val) + "->";
      if(node->left != nullptr) {
        path(node->left, temp);
      }
      if(node->right != nullptr) {
        path(node->right, temp);
      }
    }
};
