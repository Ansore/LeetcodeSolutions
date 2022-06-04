#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int main(int argc, char *argv[])
{
	queue<TreeNode*> q;
	q.push(nullptr);
	q.push(nullptr);
	q.push(nullptr);
	cout << q.size() << endl;
	q.pop();
	cout << q.size() << endl;
	
	return 0;
}
