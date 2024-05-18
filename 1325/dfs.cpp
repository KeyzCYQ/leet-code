class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (root->left) root->left = removeLeafNodes(root->left, target);
        if (root->right) root->right = removeLeafNodes(root->right, target);

        if (!root->left && !root->right && target == root->val) return nullptr;
        return root;
    }
};