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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        ans.clear();
        if (!root) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            size_t s = q.size();
            int max_val = INT_MIN;
            for (size_t i = 0; i < s; i++) {
                auto node = q.front();
                q.pop();
                max_val = max(max_val, node->val);
                if (node->right) q.push(node->right);
                if (node->left) q.push(node->left);
            }
            ans.push_back(max_val);
        };
        return ans;
    }
};