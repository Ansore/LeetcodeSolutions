#include <iostream>
#include <string>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
		TreeNode* recoverFromPreorder(string S) {
			stack<TreeNode*> treeStack;
			TreeNode* root = nullptr;

			int index = 0;
			int level = 0;

			while(index < S.size()) {
				if(S[index] == '-') {
					index ++;
					level ++;
					continue;
				}

				// 字符转数字
				int val = 0;
				while(index < S.length() && S[index] != '-') {
					val = val * 10 + S[index] - '0';
					index ++;
				}

				// 如果层级低于现在的层级，那么说明是上面某一级的右节点
				while(level < treeStack.size() && treeStack.size() > 0) {
					treeStack.pop();
				}

				// 确定节点层级后，要么是根，要么是别人的子节点
				TreeNode* tempNode = new TreeNode(val);
				if(treeStack.size() <= 0) {
					root = tempNode;
					treeStack.push(root);
				} else if(treeStack.top()->left == nullptr) {
					treeStack.top()->left = tempNode;
					treeStack.push(treeStack.top()->left);
				} else if(treeStack.top()->right == nullptr) {
					treeStack.top()->right = tempNode;
					treeStack.push(treeStack.top()->right);
				}
				// 清空层级
				level = 0;
			}
			return root;
		}
};

int main(int argc, char *argv[])
{
	Solution s;
	cout << s.recoverFromPreorder("1-2--3--4-5--6--7")->val << endl;
	return 0;
}
