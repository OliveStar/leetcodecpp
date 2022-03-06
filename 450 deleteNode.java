/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode deleteNode(TreeNode root, int key) {
        if(root == null) return null;
        if(root.val == key){
            // 情况1：要删除的节点刚好是末端节点，两个子节点都为空，直接删除
            if(root.left == null && root.right == null)
                return null;
            // 情况2：节点只有1个非空子节点，让这个孩子接替自己的位置
            if(root.left == null) return root.right;
            if(root.right == null) return root.left;
            // 情况3：节点两个子节点都非空，为了保持BST的性质，必须找到右子树的最小的节点，或左子树的最大的节点，来接替自己
            if(root.left != null && root.right != null){
                // 找到右子树的最小节点
                TreeNode minNode = getMin(root.right);
                // 删除右子树最小的节点
                root.right = deleteNode(root.right, minNode.val);
                // 用右子树最小的节点替换root
                minNode.left = root.left;
                minNode.right = root.right;
                root = minNode;
            }
        }else if(root.val > key){
            root.left = deleteNode(root.left, key);
        }else if(root.val < key){
            root.right = deleteNode(root.right, key);
        }
        return root;
    }

    TreeNode getMin(TreeNode node){
        // BST最左边的就是最小的
        while(node.left != null) node = node.left;
        return node;
    }
}