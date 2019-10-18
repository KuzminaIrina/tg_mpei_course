https://leetcode.com/problems/binary-tree-right-side-view/
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
    void recursion(TreeNode *root, int lvl, vector <int> &res) {
        if (root == NULL)
            return;
        if (res.size()<lvl)
            res.push_back(root->val);
        recursion(root->right, lvl+1, res);
        recursion(root->left, lvl+1, res);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        recursion(root, 1, res);
        return res;
    }
};
