#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* result = NULL;
		ListNode* head;

		if(l1 == nullptr && l2 == nullptr) {
			return NULL;
		}
		if(l1 == nullptr && l2 != nullptr) {
			return l2;
		}
		if(l1 != nullptr && l2 == nullptr) {
			return l1;
		}

		if(l1->val < l2->val) {
			result = l1;
			l1 = l1->next;
		} else {
			result = l2;
			l2 = l2->next;
		}

		head = result;

		while(l1 != nullptr && l2 != nullptr) {
			if(l1->val < l2->val) {
				result->next = l1;
				l1 = l1->next;
			} else {
				result->next = l2;
				l2 = l2->next;
			}
			result = result->next;
		}

		if(l1 != nullptr) {
			result->next = l1;
		}

		if(l2 != nullptr) {
			result->next = l2;
		}

		return head;
    }
};

int main(int argc, char *argv[])
{
	ListNode* l11 = new ListNode(1);
	ListNode* l12 = new ListNode(2);
	ListNode* l13 = new ListNode(4);
	ListNode* l21 = new ListNode(1);
	ListNode* l22 = new ListNode(3);
	ListNode* l23 = new ListNode(4);

	l11->next = l12;
	l12->next = l13;

	l21->next = l22;
	l22->next = l23;

	Solution s;
	ListNode* r = s.mergeTwoLists(l11, l21);

	while(r!=nullptr) {
		cout << r->val << endl;
		r = r->next;
	}
	return 0;
}
