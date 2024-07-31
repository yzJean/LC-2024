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
    void Dfs(TreeNode* node, int targetSum, vector<vector<int>>& res, vector<int> path) {
        path.push_back(node->val);
        if (!node->left && !node->right) {
            int sum = 0;
            for (auto&& val: path) {
                sum += val;
            }
            if (sum == targetSum) {
                res.push_back(path);
            }
            return;
        }

        if (node->left) {
            Dfs(node->left, targetSum, res, path);
            // path.pop_back(); // No need it anymore because the path variable is copied by value
        }

        if (node->right) {
            Dfs(node->right, targetSum, res, path);
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
        Dfs(root, targetSum, ans, path);
        return ans;
    }
};