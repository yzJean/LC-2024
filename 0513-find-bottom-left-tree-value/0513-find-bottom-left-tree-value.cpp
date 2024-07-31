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
    void Dfs(TreeNode* node, int curr_depth, int& ans, int& max_depth) {
        if (!node->left && !node->right) {
            if (curr_depth > max_depth) {
                max_depth = curr_depth;
                ans = node->val;
            }
            return;
        }

        if (node->left) Dfs(node->left, curr_depth + 1, ans, max_depth); // backtracking: curr_depth
        if (node->right) Dfs(node->right, curr_depth + 1, ans, max_depth); // backtracking: curr_depth
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        int ans = root->val;
        int max_depth = INT_MIN;
        Dfs(root, 0, ans, max_depth);
        return ans;
    }
};