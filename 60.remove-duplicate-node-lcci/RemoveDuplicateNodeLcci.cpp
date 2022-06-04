#include <iostream>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
		if(head == nullptr || head->next == nullptr) {
			return head;
		}
		unordered_set<int> set;
		set.insert(head->val);
		ListNode* p = head;
		while(p->next != nullptr) {
			if(set.find(p->next->val) == set.end()) {
				// 不存在
				set.insert(p->next->val);
				p = p->next;
			} else {
				// 存在
				ListNode* temp = p->next;
				p->next = p->next->next;
				delete temp;
			}
		}
		return head;
    }
};

int main(int argc, char *argv[])
{
	ListNode* node1 = new ListNode(1);
	ListNode* node2 = new ListNode(2);
	ListNode* node3 = new ListNode(3);
	ListNode* node4 = new ListNode(3);
	ListNode* node5 = new ListNode(2);
	ListNode* node6 = new ListNode(1);
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;

	Solution s;
	ListNode* res = s.removeDuplicateNodes(node1);
	//cout << res->next->val << endl;
	while(res != nullptr) {
		cout << res->val << " ";
		//cout << "---";
		res = res->next;
	}
	//cout << endl;
	return 0;
}
