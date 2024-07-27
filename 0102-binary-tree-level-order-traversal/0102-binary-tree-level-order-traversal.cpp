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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        ans.clear();
        if (!root) return ans;
        int level = 0, prev_level = -1;
        queue<pair<TreeNode*, int>> elems;
        elems.push(make_pair(root, level));
        vector<int> level_nodes;
        level_nodes.clear();
        while (!elems.empty()) {
            auto node_level = elems.front();
            auto node = node_level.first;
            elems.pop();
            if (prev_level != node_level.second) {
                if (prev_level != -1) {
                    ans.push_back(level_nodes);
                }
                level_nodes.clear();
                level++;
            }
            level_nodes.push_back(node->val);
            prev_level = node_level.second;
            if (node->left) elems.push(make_pair(node->left, level));
            if (node->right) elems.push(make_pair(node->right, level));
        };
        // push back the final results
        if (!level_nodes.empty()) ans.push_back(level_nodes);
        return ans;
    }
};