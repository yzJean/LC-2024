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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        ans.clear();
        if (!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) { // O(n)
            size_t s = q.size();
            vector<int> level;
            for (size_t i = 0; i < s; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                level.push_back(node->val);
            }
            ans.push_back(level);
        };
        reverse(ans.begin(), ans.end()); // O(n), to be optimized
        return ans;
    }
};