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
		ListNode* deleteDuplicates(ListNode* head) {
			if(head == nullptr) {
				return nullptr;
			}
			ListNode* p = head;
			if(p->next == nullptr) {
				return head;
			}
			unordered_set<int> set;
			ListNode* pre = p;
			set.insert(p->val);
			p = p->next;
			while(p != nullptr) {
				if(set.find(p->val) == set.end()) {
					set.insert(p->val);
					pre = p;
					p = p->next;
				} else {
					ListNode* temp = p;
					p = p->next;
					pre->next = p;
					delete temp;
				}
			}
			return head;
		}
};

int main(int argc, char *argv[])
{
	ListNode* node1 = new ListNode(1);
	ListNode* node2 = new ListNode(1);
	ListNode* node3 = new ListNode(2);
	ListNode* node4 = new ListNode(3);
	ListNode* node5 = new ListNode(3);
	ListNode* node6 = new ListNode(1);
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;

	Solution s;
	ListNode* result = s.deleteDuplicates(node1);
	while(result != nullptr) {
		cout << result->val << " ";
		result = result->next;
	}
	cout << endl;
	return 0;
}
