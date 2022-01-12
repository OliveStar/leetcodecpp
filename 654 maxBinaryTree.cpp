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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, nums.size()-1);
    }

    TreeNode* build(vector<int>& nums, int lo, int hi){
        if(lo > hi) return nullptr;
        // 找到数组中的最大值和对应的索引
        int maxVal = -1;
        int index = 0;
        for(int i = lo; i <= hi;i++){
            if(nums[i] > maxVal){
                maxVal = nums[i];
                index = i;
            }
        }
        TreeNode *root = new TreeNode(maxVal);
        root->left = build(nums, lo, index-1);
        root->right = build(nums, index+1, hi);
        return root;
    }
};