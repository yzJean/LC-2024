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
    vector<int> results;
    int maxCount = INT_MIN;
    int count = 0;
    TreeNode* pre;

    void traverse(TreeNode* node) {
        if (!node) return;

        traverse(node->left);
        if (!pre) {
            count = 1;
        } else if (pre->val == node->val) {
            count++;
        } else {
            count = 1;
        }
        pre = node;

        if (count == maxCount) {
            results.push_back(node->val);
        } else if (count > maxCount) {
            maxCount = count;
            results.clear();
            results.push_back(node->val);
        }
        traverse(node->right);

    }

public:
    vector<int> findMode(TreeNode* root) {
        maxCount = INT_MIN;
        count = 0;
        results.clear();
        pre = nullptr;
        traverse(root);
        return results;
    }
};