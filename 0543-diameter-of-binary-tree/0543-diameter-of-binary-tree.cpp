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
private:
    int Dfs(TreeNode* node, int& diameter) {
        if (!node) {
            return -1;
        }
        int left_h = Dfs(node->left, diameter);
        int right_h = Dfs(node->right, diameter);
        diameter = max(diameter, 2 + left_h + right_h);

        return 1 + max(left_h, right_h);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = INT_MIN;
        Dfs(root, diameter);
        return diameter;
    }
};