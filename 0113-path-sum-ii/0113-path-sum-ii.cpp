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
    int sum_;
    void Dfs(TreeNode* node, int targetSum, vector<vector<int>>& res, vector<int> path) {
        sum_ += node->val;
        path.push_back(node->val);
        if (!node->left && !node->right) {
            if (sum_ == targetSum) {
                res.push_back(path);
            }
            return;
        }

        if (node->left) {
            Dfs(node->left, targetSum, res, path);
            sum_ -= node->left->val;
            // path.pop_back(); // No need it anymore because the path variable is copied by value
        }

        if (node->right) {
            Dfs(node->right, targetSum, res, path);
            sum_ -= node->right->val;
            // path.pop_back(); // No need it anymore because the path variable is copied by value
        }

    };
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        ans.clear();
        if (!root) { return ans; }
        vector<int> path;
        path.clear();
        sum_ = 0;
        Dfs(root, targetSum, ans, path);
        return ans;
    }
};