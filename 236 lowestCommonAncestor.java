/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        // base case
        if(root == null) return null;
        if(root == p || root == q) return root;

        TreeNode left = lowestCommonAncestor(root.left, p, q);
        TreeNode right = lowestCommonAncestor(root.right, p, q);

        // 情况1：如果p和q都在以root为根的树中，那么left和right一定分别是p和q
        if(left != null && right != null){
            return root;
        }   

        // 情况2：如果p和q都不在以root为根的树中，直接返回null
        if(left == null && right == null){
            return null;
        }

        // 情况3：如果p和q只有一个存在于root为根的树中，函数返回该节点
        return left == null? right : left;
    }
}