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
    void Dfs(TreeNode* node, vector<string>& path, vector<string>& res) {
        path.push_back(to_string(node->val)); // pre-order search
        if (node->right == nullptr && node->left == nullptr) { // the leaves
            string root2leaf_path;
            for (size_t i = 0; i < path.size() - 1; i++) {
                root2leaf_path += path[i];
                root2leaf_path += "->";
            }
            root2leaf_path += path[path.size() - 1];
            res.push_back(root2leaf_path);
        }
        if (node->left) {
            Dfs(node->left, path, res);
            path.pop_back(); // pop out the used element
        }
        if (node->right) {
            Dfs(node->right, path, res);
            path.pop_back(); // pop out the used element
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        ans.clear();
        vector<string> path; // TODO: to be optimized
        Dfs(root, path, ans);
        return ans;
    }
};