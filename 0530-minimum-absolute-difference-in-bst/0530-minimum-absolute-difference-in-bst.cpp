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
    void traversal(TreeNode* root, vector<int>& vals) {
        if (!root) return;
        traversal(root->left, vals);
        vals.push_back(root->val);
        traversal(root->right, vals);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        int minimum = INT_MAX;
        vector<int> vals;
        traversal(root, vals);

        for (size_t i = 1; i < vals.size(); i++) {
            minimum = min(minimum, vals[i] - vals[i - 1]);
        }
        return minimum;
    }
};