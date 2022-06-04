#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

			ListNode* res = new ListNode(0);
			ListNode* cur = res;
			bool flag = false;
			while(l1!=nullptr || l2!=nullptr || flag) {
				int num1=0;
				int num2=0;
				if(l1 != nullptr) {
					num1 = l1->val;
				}
				if(l2 != nullptr) {
					num2 = l2->val;
				}

				int num3 = num1 + num2;
				if(flag) {
					num3 ++;
					flag = false;
				}
				if(num3 >= 10) {
					num3 %= 10;
					flag = true;
				}
				cout << num3 << endl;
				ListNode* temp = new ListNode(num3);
				cur->next = temp;
				cur = temp;

				if(l1 != nullptr) {
					l1 = l1->next;
				}
				if(l2 != nullptr) {
					l2 = l2->next;
				}
			}
			return res->next;
		}
};

int main(int argc, char *argv[])
{
	ListNode* l11 = new ListNode(1);
	ListNode* l12 = new ListNode(8);
	/* ListNode* l13 = new ListNode(3); */

	l11->next = l12;
	/* l12->next = l13; */

	ListNode* l21 = new ListNode(0);
	/* ListNode* l22 = new ListNode(6); */
	/* ListNode* l23 = new ListNode(4); */

	/* l21->next = l22; */
	/* l22->next = l23; */

	/* ListNode* l11 = new ListNode(2); */
	/* ListNode* l12 = new ListNode(4); */
	/* ListNode* l13 = new ListNode(3); */

	/* l11->next = l12; */
	/* l12->next = l13; */

	/* ListNode* l21 = new ListNode(5); */
	/* ListNode* l22 = new ListNode(6); */
	/* ListNode* l23 = new ListNode(4); */

	/* l21->next = l22; */
	/* l22->next = l23; */
	Solution s;

	ListNode* res = s.addTwoNumbers(l11, l21);
	while(res != nullptr) {
		cout << res->val << " ";
		res = res->next;
	}
	cout << endl;
	return 0;
}
