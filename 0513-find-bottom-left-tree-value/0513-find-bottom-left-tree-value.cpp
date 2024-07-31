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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans = root->val;
        while(!q.empty()) {
            size_t s = q.size();
            bool is_last_row = true;
            for (size_t i = 0; i < s; i++) {
                auto node = q.front();
                q.pop();
                if (i == 0) ans = node->val;
                is_last_row = is_last_row && (!node->right && !node->left);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (is_last_row) {
                break;
            }
        };
        return ans;
    }
};
/*
queue<TreeNode*> q: 2



*/