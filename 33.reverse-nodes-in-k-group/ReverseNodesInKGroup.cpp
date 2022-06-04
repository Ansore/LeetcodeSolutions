#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
	public:
		void reverse(ListNode* pre, ListNode* head, ListNode* end, ListNode* next) {
			//ListNode* firstNode = nullptr;
			//if(pre == nullptr) {
			//firstNode = end;
			//}
			end->next = nullptr;
			ListNode* p1 = head;
			ListNode* p2 = head->next;
			ListNode* p3 = nullptr;

			while(p2 != nullptr) {
				p3 = p2->next;
				p2->next = p1;
				p1 = p2;
				p2 = p3;
			}
			if(pre != nullptr)
				pre->next = p1;
			head->next = next;
		}

		ListNode* reverseKGroup(ListNode* head, int k) {

			if(k==0 || k == 1 || head == nullptr) {
				return head;
			}

			int cur = 1;
			ListNode* result = nullptr;
			ListNode* p = head;

			ListNode* preP = nullptr;
			ListNode* startP = head;
			ListNode* nextP = nullptr;

			//s.reverse(nullptr, n1, n2, n3);
			//s.reverse(n1, n3, n4, n5);
			//s.reverse(n3, n5, n6, n7);
			for (int i = 1; p != nullptr; i ++) {
				if(i%k == 0) {
					cout << "--" << p->val << endl;
					ListNode* originP = startP;
					nextP = p->next;
					reverse(preP, startP, p, p->next);
					if(result == nullptr) {
						result = p;
					}
					preP = startP;
					startP = nextP;
					p = originP;
					if(p == nullptr) {
						break;
					}
				}
				p = p->next;
			}

			return result == nullptr? head : result;
		}
};

int main(int argc, char *argv[])
{
	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(3);
	ListNode* n4 = new ListNode(4);
	ListNode* n5 = new ListNode(5);
	ListNode* n6 = new ListNode(6);
	ListNode* n7 = new ListNode(7);

	//n1->next = n2;
	//n2->next = n3;
	//n3->next = n4;
	//n4->next = n5;
	//n5->next = n6;
	//n6->next = n7;

	Solution s;

	//s.reverse(nullptr, n1, n2, n3);
	//s.reverse(n1, n3, n4, n5);
	//s.reverse(n3, n5, n6, n7);

	ListNode* temp = s.reverseKGroup(n1, 2);
	//ListNode* temp = n2;
	while(temp != nullptr) {
		cout << temp->val << " ";
		temp = temp->next;
	}
	cout << endl;
	return 0;
}
