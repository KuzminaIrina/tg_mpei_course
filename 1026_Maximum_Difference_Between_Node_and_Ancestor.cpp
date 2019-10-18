https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
       int maxAncestorDiff(TreeNode* r, int mn = 5000, int mx = 0) {
        return r ? max(maxAncestorDiff(r->left, min(mn, r->val), max(mx, r->val)),
        maxAncestorDiff(r->right, min(mn, r->val), max(mx, r->val))) : mx - mn;
    }
};
