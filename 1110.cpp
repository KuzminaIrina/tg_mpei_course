https://leetcode.com/problems/delete-nodes-and-return-forest/
class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& _toDelete) {
        for (int i = 0; i < _toDelete.size(); i++) {
            toDelete.insert(_toDelete[i]);
        }
        traverse(root, true);
        return result;
    }
private:
    unordered_set<int> toDelete;
    vector<TreeNode*> result;
    void traverse(TreeNode* root, bool isNewForest) {
        if (!root) {
            return;
        }
        bool toBeDeleted = toDelete.count(root->val);
        if (!toBeDeleted && isNewForest) {
            result.emplace_back(root);
        }
        if (root->left && toDelete.count(root->left->val)) {
            traverse(root->left->left, true);
            traverse(root->left->right, true);
            root->left = nullptr;
        } else {
            traverse(root->left, toBeDeleted);
        }
        if (root->right && toDelete.count(root->right->val)) {
            traverse(root->right->left, true);
            traverse(root->right->right, true);
            root->right = nullptr;
        } else {
            traverse(root->right, toBeDeleted);
        }
    }
};
