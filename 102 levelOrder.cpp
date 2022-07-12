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
    // 算法：BFS
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root){
            return ret;
        }

        queue<TreeNode*> q;
        q.push(root); // 首先，根元素入队
        // 当队列不为空的时候
        // 求当前队列的长度si
        // 依次从队列中取si个元素进行拓展，然后进入下一次迭代
        // 由于si是第i层从左到右的节点，从si拓展得到si+1个元素，也是第i+1层从左到右的节点
        while(!q.empty()){
            int currentLevelSize = q.size();
            ret.push_back(vector<int>());
            for(int i = 0; i < currentLevelSize; i++){
                auto node = q.front();
                q.pop();
                ret.back().push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }

        return ret;
    }
};