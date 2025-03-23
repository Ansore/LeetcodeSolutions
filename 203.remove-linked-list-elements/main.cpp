#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *node = nullptr, *prev = head, *result = nullptr;
        while(prev && (prev->val == val)) {
            prev = prev->next;
        }
        if (prev == nullptr) {
            return nullptr;
        }
        result = prev;
        node = prev->next;
        while(node) {
            if (node->val == val) {
                prev->next = node->next;
            } else {
                prev = prev->next;
            }
            node = prev->next;
        }
        return result;
    }
};

int main (int argc, char *argv[]) {
    ListNode l1 = ListNode(6);
    ListNode l2 = ListNode(7);
    ListNode l3 = ListNode(6);
    ListNode l4 = ListNode(7);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = nullptr;
    Solution s;
    ListNode *node = s.removeElements(&l1, 7);
    while(node) {
        cout << node->val << endl;
        node = node->next;
    }
    return 0;
}
