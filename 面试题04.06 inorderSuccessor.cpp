/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    /*
    // 简化版算法，只找值，不存路径
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(root == NULL){
            return NULL;
        }

        TreeNode* node = root; // 当前节点
        TreeNode* next = NULL; // 当前节点的中序后继
        // 搜索整棵树，找到p值节点
        while(node->val != p->val){
            if(node->val < p->val){
                node = node->right;
            }else{
                next = node;
                node = node->left;
            }
        }

        // 找到了p值节点，再找它的中序后继
        // 有右子树，找右子树，没有就返回当前子树的根，作为中序后继
        if(node->right != NULL){
            node = node->right; 
            // 右子树的左子树的叶子节点是中继节点
            while(node->left != NULL){
                node = node->left;
            }
            return node;
        }else{
            return next;
        }
    }
    */
    // 既找值，也存路径
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(root == NULL){
            return NULL;
        }
        stack<TreeNode*> st;
        st.push(root);
        while(st.top()->val != p->val){
            TreeNode* node = st.top();
            if(node->val > p->val){
                st.push(node->left);
            }else{
                st.push(node->right);
            }
        }

        TreeNode* node = st.top();
        if(node->right != NULL){
            st.push(node->right);
            while(st.top()->left != NULL){
                st.push(st.top()->left);
            }
        }else{
            st.pop();
            while(!st.empty() && st.top()->right == node){
                node = st.top();
                st.pop();
            }
        }

        if(st.empty()){
            return NULL;
        }

        return st.top();
    }
};