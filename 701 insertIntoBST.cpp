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
    // 将值插入二叉搜索树。 返回插入后二叉搜索树的根节点
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr) return new TreeNode(val);
        // 输入数据保证，不会插入原始二叉搜索树中已有的节点。不必考虑相等的情况
        if(root->val < val)
            root->right = insertIntoBST(root->right, val);
        if(root->val > val)
            root->left = insertIntoBST(root->left, val);
        return root;
    }
};