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
    void Dfs(TreeNode* node, string path, vector<string>& res) {
        path += to_string(node->val); // pre-order search
        if (node->right == nullptr && node->left == nullptr) { // the leaves
            res.push_back(path);
        }
        if (node->left) {
            Dfs(node->left, path + "->", res); // In C++: " path + "->" " creates a temporary string object and pass it into the function. This temporary object does not have impacts on " path " itself becasue it is temporary.
        }
        if (node->right) {
            Dfs(node->right, path + "->", res);
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        ans.clear();
        string path;
        Dfs(root, path, ans);
        return ans;
    }
};