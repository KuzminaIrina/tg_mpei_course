https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
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
      TreeNode* Tree(vector<int>& nums, int start, int end){
        if(end<=start) return NULL;
        int midIdx=(end+start)/2;
        TreeNode* root=new TreeNode(nums[midIdx]);
        root->left=Tree(nums, start, midIdx);
        root->right=Tree(nums, midIdx+1,end);
        return root;
    }
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
    return Tree(num, 0, num.size());
    }
};
