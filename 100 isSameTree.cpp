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
    // 算法：深度优先搜索
    // 两个二叉树相同，当前仅当两个二叉树的结构完全相同，且所有对应节点的值相同
    // 时间复杂度：O(min(m,n))，其中m和n分别是两个二叉树的节点数。对两个二叉树同时进行深度优先搜索，只有当两个二叉树中的对应节点都不为空时才会访问到该节点，因此被访问到的节点数不会超过较小的二叉树的节点数。
    // 空间复杂度：O(min(m,n))，其中m和n分别是两个二叉树的节点数。空间复杂度取决于递归调用的层数，递归调用的层数不会超过较小的二叉树的最大高度，最坏情况下，二叉树的高度等于节点数。
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // 如果两个二叉树都为空，则两个二叉树相同
        if(p == nullptr && q == nullptr){
            return true;
        }else if(p == nullptr || q == nullptr){
            // 如果两个二叉树中有且只有一个为空，则两个二叉树一定不相同
            return false;
        }else if(p->val != q->val){
            // 如果两个二叉树都不为空，判断他们的根节点是否相同，若不相同，则两个树一定不相同
            return false;
        }else{
            // 如果根节点相同，则递归地判断左子树和右子树是否相同
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
    }
};