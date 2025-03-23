#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         stack<ListNode*> s;
//         ListNode *node = head, *r = nullptr;
//         if (!node) {
//             return nullptr;
//         }
//         while(node) {
//             s.push(node);
//             r = node;
//             node = node->next;
//         }
//         node = s.top();
//         s.pop();
//         while(s.size() > 0) {
//             node->next = s.top();
//             s.pop();
//             node = node->next;
//         }
//         node->next = nullptr;
//         return r;
//     }
// };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr, *cur = head;
        while (cur != nullptr) {
            ListNode *n = cur->next;
            cur->next = prev;
            prev = cur;
            cur = n;
        }
        return prev;
    }
};
int main (int argc, char *argv[]) {
    ListNode l1 = ListNode(1);
    ListNode l2 = ListNode(2);
    ListNode l3 = ListNode(3);
    ListNode l4 = ListNode(4);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = nullptr;
    Solution s;
    ListNode *node = s.reverseList(&l1);
    while(node) {
        cout << node->val << endl;
        node = node->next;
    }
    return 0;
}
