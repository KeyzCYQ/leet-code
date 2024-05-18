/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode * Node, int Inv, int * Moves){
        if (Node->val > 1) Inv += Node->val - 1;

        if (Node->val == 0){
            Inv--;
        }
        
        int new_inv = Inv;

        if (Node->left) {
            new_inv = dfs(Node->left, Inv, Moves);
            *Moves += abs(Inv - new_inv);
            Inv = new_inv;
        }
        if (Node->right) {
            new_inv = dfs(Node->right, Inv, Moves);
            *Moves += abs(Inv - new_inv);
            Inv = new_inv;
        }

        return new_inv;
    }

    int distributeCoins(TreeNode* root) {
        int moves = 0;
        
        dfs(root, 0, &moves);

        return moves;
    }
};