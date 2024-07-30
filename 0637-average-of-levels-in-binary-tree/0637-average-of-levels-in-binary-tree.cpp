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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        ans.clear();
        if (!root) return ans;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int s = q.size(); // level
            double sum = 0.0;
            for (size_t i = 0; i < s; i++) {
                auto node = q.front();
                q.pop();
                sum += double(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ans.push_back(sum/s);
        };
        return ans;
    }
};