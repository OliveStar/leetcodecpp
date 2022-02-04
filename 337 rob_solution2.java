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
 // 解法2：时间复杂度O(N)，空间复杂度为函数堆栈空间，不需要额外备忘录空间的解法
class Solution {
    public int rob(TreeNode root) {
        int[] res = dp(root);
        return Math.max(res[0],res[1]);
    }

    /* 返回一个大小为2的数组arr
    arr[0] 表示不抢root的话，得到的最大钱数
    arr[1] 表示抢root的话，得到的最大钱数 */
    int[] dp(TreeNode root){
        if(root == null)
            return new int[]{0,0};
        int[] left = dp(root.left);
        int[] right = dp(root.right);
        // 抢root，左右子树节点不能抢
        int rob = root.val + left[0] + right[0];
        // 不抢root，左右子树节点可抢可不抢，取决于收益大小
        int not_rob = Math.max(left[0], left[1]) + Math.max(right[0], right[1]);

        return new int[]{not_rob, rob};
    }
}