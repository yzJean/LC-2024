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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        ans.clear();
        if (!root) return ans;

        queue<TreeNode* > q;
        q.push(root);
        while (!q.empty()) {
            size_t s = q.size();
            for (size_t i = 0; i < s; i++) {
                auto node = q.front();
                q.pop();
                if (i == s - 1) ans.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        };
        return ans;
    }
};