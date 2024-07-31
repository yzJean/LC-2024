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
    TreeNode* Dfs(const vector<int>& nums, int start, int end) {
        if (start >= end) {
            return nullptr;
        }
        // int max_val_idx = distance( nums.begin() + start, max_element(nums.begin() + start, nums.begin() + end ) ); // TODO:
        int max_val_idx = start;
        for (int i = start + 1; i < end; i++) {
            if (nums[i] > nums[max_val_idx]) max_val_idx = i;
        }
        TreeNode* node = new TreeNode(nums[max_val_idx]);
        node->left = Dfs(nums, start, max_val_idx);
        node->right = Dfs(nums, max_val_idx + 1, end);
        return node;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return Dfs(nums, 0, nums.size());
    }
};
/*
 0 1 2 3 4 5
[3,2,1,6,0,5]
       i
if (indx_start > indx_end) {
    return nullptr;
}
root: 6
root->left = Dfs(index_beg, index_i - 1)
root->right = Dfs(index_i + 1, index_end)
return root;
*/