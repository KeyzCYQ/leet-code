class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        
        int last = -INT_MAX;
        int mult = 1;
        int last_level = 0;
        while(!q.empty()){
            TreeNode *current = q.front().first;
            int level = q.front().second;
            q.pop();

            if (current->left) q.push(make_pair(current->left, level + 1));
            if (current->right) q.push(make_pair(current->right, level + 1));

            if (level%2 == 0) mult = 1;
            else mult = -1;

            cout<<current->val<<" ";

            if (last_level < level) last = -INT_MAX;
            last_level = level;

            if (last >= mult * current->val || level%2 == current->val%2) return false;
            else last = mult * current->val;
        }

        return true;
    }
};