#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(-1), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

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

struct string_val
{
    string s;
    int val;
};


class Solution {

public:
    void rec(TreeNode * node, string * s, string current_s){
        current_s = char(node->val + 'a') + current_s;
        if (!node->left && !node->right){
            if (*s == "") *s = current_s;
            else if (current_s < *s) *s = current_s;
            return;
        }
        if (node->left) rec(node->left, s, current_s);
        if (node->right) rec(node->right, s, current_s);
    }

    string smallestFromLeaf(TreeNode* root) {
        string s = "";
        string current_s = "";

        rec(root, &s, current_s);

        return s;
    }
};

int main(){
    TreeNode root;
    int test[] = {0,1,2,3,4,3,4};
    int n = sizeof(test)/sizeof(int);

    fillTree(&root, test, n);

    cout << Solution().smallestFromLeaf(&root);

    return 0;
}