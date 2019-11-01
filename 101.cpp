https://leetcode.com/problems/symmetric-tree/
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
  bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    return isSymmetric_helper(root->left, root->right);
}
bool isSymmetric_helper(TreeNode* r1, TreeNode* r2) {
    if (r1==NULL && r2==NULL) return true;
    if (r1==NULL || r2==NULL) return false;
    if (r1->val != r2->val) return false;
    return isSymmetric_helper(r1->left, r2->right) && isSymmetric_helper(r1->right, r2->left);
}
};
