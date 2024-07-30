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
    int Dfs(TreeNode* node, bool& is_balanced) { // calculate the tree height
        if (!node || !is_balanced) {
            return -1;
        }
        int left_h = Dfs(node->left, is_balanced);
        int right_h = Dfs(node->right, is_balanced);
        if (abs(left_h - right_h) > 1) {
            is_balanced = false;
            return -1; // TODO: think about why
        }

        return 1 + max(left_h, right_h);
    }

public:
    bool isBalanced(TreeNode* root) {
        bool is_balanced = true;
        Dfs(root, is_balanced);
        return is_balanced;
    }
};