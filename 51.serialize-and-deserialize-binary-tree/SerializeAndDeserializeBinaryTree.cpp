#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Codec {
	public:

		// Encodes a tree to a single string.
		string serialize(TreeNode* root) {
			queue<TreeNode*> q;
			if(root != nullptr) {
				q.push(root);
			}
			string res;
			while(!q.empty()) {
				TreeNode* temp = q.front();
				q.pop();
				if(temp != nullptr) {
					res += to_string(temp->val)+",";
					q.push(temp->left);
					q.push(temp->right);
				} else {
					res += "null,";
				}
			}
			return res;
		}

		// Decodes your encoded data to tree.
		TreeNode* deserialize(string data) {
			if(data.size()==0){
				return nullptr;
			}
			auto vals = split(data);
			queue<TreeNode*> q;
			if(vals[0] == "null") return nullptr;
			q.push(new TreeNode(stoi(vals[0])));
			TreeNode* res = q.front();
			for (int i = 1; i < vals.size();) {
				if(vals[i] != "null") {
					auto p = new TreeNode(stoi(vals[i]));
					q.push(p);
					q.front()->left = p;
				}
				i ++;
				if(vals[i] != "null") {
					auto p = new TreeNode(stoi(vals[i]));
					q.push(p);
					q.front()->right=p;
				}
				i ++;
				q.pop();
			}
			return res;
		}

		vector<string> split(string& data) {
			int start = 0;
			vector<string> res;
			while(true) {
				auto end = data.find(',', start);
				if(end == string::npos)break;
				res.push_back(data.substr(start, end-start));
				start = end+1;
			}
			return move(res);
		}
};

int main(int argc, char *argv[])
{
	TreeNode* node1 = new TreeNode(1);
	TreeNode* node2 = new TreeNode(2);
	TreeNode* node3 = new TreeNode(3);
	TreeNode* node4 = new TreeNode(4);
	TreeNode* node5 = new TreeNode(5);

	node1->left = node2;
	node1->right = node3;
	node3->left = node4;
	node3->right = node5;

	Codec codec;
	cout << codec.serialize(nullptr) << endl;

	cout << codec.deserialize(codec.serialize(node1))->val << endl;

	return 0;
}
