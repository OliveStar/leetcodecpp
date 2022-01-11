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
    vector<int> list;
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == nullptr) return list;
        traverse(root);
        return list;
    }
    void traverse(TreeNode *root){
        if(root == nullptr) return;
        list.push_back(root->val);
        traverse(root->left);
        traverse(root->right);
    }
};