https://leetcode.com/problems/find-bottom-left-tree-value/
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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> queue1;
            int res;
        if (!root) return res;
         queue1.push(root);
        int count=1;
        vector<int> tmp;
        while(! queue1.empty())
        {
                tmp.push_back( queue1.front()->val);
                if ( queue1.front()->left)  queue1.push( queue1.front()->left);
                if ( queue1.front()->right)  queue1.push( queue1.front()->right);
                 queue1.pop();
                count--;
                if (!count)
                {
                        count= queue1.size();
                        res=tmp[0];
                        tmp.clear();
                }
        }
        return res;
    }
};
