https://leetcode.com/problems/odd-even-linked-list/
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
  ListNode* oddEvenList(ListNode* head)
  {
   if(!head)
    return head;
   ListNode* first = head;
   ListNode* sec = head->next;
   ListNode* tmp = sec;
   while((sec) && (sec->next))
   {
    first->next = sec->next;
    first = first->next;
    sec->next = first->next;
    sec = sec->next;
   }
   first->next = tmp;
  return head;
  }
};
