#include <iostream>
#include <cmath>

using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
			if(l1 == nullptr) {
				return l2;
			}
			if(l2 == nullptr) {
				return l1;
			}
			long long num1 = l1->val;
			long long num2 = l2->val;

			ListNode* p1 = l1->next;
			int index = 1;
			while(p1 != nullptr) {
				num1 = num1 + pow(10, index)*p1->val;
				p1 = p1->next;
				index ++;
			}

			ListNode* p2 = l2->next;
			index = 1;
			while(p2 != nullptr) {
				num2 = num2 + pow(10, index)*p2->val;
				p2 = p2->next;
				index ++;
			}

			long long num3 = num1+num2;
			ListNode* head = new ListNode(num3%10);
			ListNode* res = head;
			num3 /= 10;
			while(num3 > 0) {
				ListNode* temp = new ListNode(num3%10);
				/* temp->next = res; */
				res->next = temp;
				res = temp;
				num3 /= 10;
			}
			return head;
		}
};

int main(int argc, char *argv[])
{
	ListNode* l11 = new ListNode(2);
	ListNode* l12 = new ListNode(4);
	ListNode* l13 = new ListNode(3);

	l11->next = l12;
	l12->next = l13;

	ListNode* l21 = new ListNode(5);
	ListNode* l22 = new ListNode(6);
	ListNode* l23 = new ListNode(4);

	l21->next = l22;
	l22->next = l23;

	Solution s;

	ListNode* res = s.addTwoNumbers(l11, l21);
	while(res != nullptr) {
		cout << res->val << " ";
		res = res->next;
	}
	cout << endl;
	return 0;
}
