#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(-1), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

 using namespace std;

int insertNode(TreeNode * current_node, int value, int i, int level){
    int inserted = 0;
    double a = level - log2(i + 1);
    if (level - log2(i + 1) <= 0 && current_node->val == -1){
        current_node->val = value;
        inserted = 1;
    } else if (level - log2(i + 1) <= 0 && !inserted) {
        if (current_node->left == NULL && level - log2(i + 1) + 1<= 0){
            current_node->left = new TreeNode();
        }
        if (!(inserted = insertNode(current_node->left, value, i, level + 1))){
            if (current_node->right == NULL && level - log2(i + 1) + 1<= 0){
                current_node->right = new TreeNode();
            }
            inserted = insertNode(current_node->right, value, i, level + 1);
        }
    }

    return inserted;
}

void fillTree(TreeNode * root, int * values, int n){

    for (int i = 0; i < n; i++){
        insertNode(root, values[i], i, 0);
    }

}

class Solution {
public:
    void rec(TreeNode ** node, int val, int depth, int current_depth){
        if (depth == 1){
            TreeNode * new_node = new TreeNode(val, *node, nullptr);
            *node = new_node;
            return;
        } else if (current_depth == depth - 1){
            TreeNode * l_new_node = new TreeNode(val, (*node)->left, nullptr);
            TreeNode * r_new_node = new TreeNode(val, nullptr, (*node)->right);
            (*node)->left = l_new_node;
            (*node)->right = r_new_node;

            return;
        }

        if ((*node)->left){
            rec(&(*node)->left, val, depth, current_depth + 1);
        }
        if ((*node)->right){
            rec(&((*node)->right), val, depth, current_depth + 1);
        }
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        rec(&root, val, depth, 1);

        return root;
    }
};

int main(){
    TreeNode root;
    int test[] = {4,2,6,3,1,5};
    int val = 1;
    int depth = 1;
    int n = sizeof(test)/sizeof(int);

    fillTree(&root, test, n);

    cout << Solution().addOneRow(&root, val, depth);

    return 0;
}