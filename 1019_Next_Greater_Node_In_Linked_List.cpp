https://leetcode.com/problems/next-greater-node-in-linked-list/
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
    vector<int> nextLargerNodes(ListNode* head) {
ListNode *x = head, *prev = nullptr, *nxt;
 while(x)
 {
     nxt = x->next;
     x->next = prev;
     prev = x;
     x = nxt;
 }

 x = prev;
 stack<int> s;
 vector<int>res;
 while(x)
 {
     while(!s.empty() && s.top() <= x->val)
      s.pop();
       if(s.empty())
        res.push_back(0);
       else
        res.push_back(s.top());
     s.push(x->val);
     x = x->next;
 }
 reverse(res.begin(), res.end());
 return res;
    }
};
