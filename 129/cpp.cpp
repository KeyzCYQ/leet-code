#include "iostream"

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(-1), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return rec(root, 0);
    }

    int rec(TreeNode * node, int current){
        current = current * 10 + node->val;
        if (node->left == NULL && node->right == NULL){
            return current;
        }

        int sum = 0;

        if (node->left) sum += rec(node->left, current);
        if (node->right) sum += rec(node->right,current);

        return  sum;
    }
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

int main(){
    TreeNode root;
    int test[] = {4,9,0,5,1};
    int n = sizeof(test)/sizeof(int);

    fillTree(&root, test, n);

    cout << Solution().sumNumbers(&root);

    return 0;
}