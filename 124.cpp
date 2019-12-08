https://leetcode.com/problems/binary-tree-maximum-path-sum/
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
    int res;
public:
    int depth(TreeNode *root){
        if(root==NULL) return 0;
        int a=depth(root->left), b=depth(root->right);
        res=max(res,a+b+root->val);
        return max(0,max(a, b)+root->val);
    }
    int maxPathSum(TreeNode *root) {
        if(root==NULL)
            return 0;
        res=root->val;
        depth(root);
        return res;
    }
};
