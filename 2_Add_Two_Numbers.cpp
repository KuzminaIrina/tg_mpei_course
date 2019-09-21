// https://leetcode.com/problems/add-two-numbers
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode node(0);
    ListNode* p1 = l1;
    ListNode* p2 = l2;
    ListNode* parent =&node;
    int N = 0;

    while (p1 || p2 || N) {
        int d1 = p1 ? p1->val : 0;
        int d2 = p2 ? p2->val : 0;
        if (p1) p1 = p1->next;
        if (p2) p2 = p2->next;
        N += d1 + d2;
        ListNode* node = new ListNode(N % 10);
        parent->next = node;
        parent = node;
        N /= 10;
    }

    return node.next;
}
};
