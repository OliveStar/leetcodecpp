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
 // 解法1：时间复杂度O(N)，空间复杂度为O(N)，需要额外空间备忘录的读写操作时间
class Solution {
    Map<TreeNode, Integer> memo = new HashMap<>();
    public int rob(TreeNode root) {
        if(root == null) return 0;
        // 利用备忘录消除重叠子问题
        if(memo.containsKey(root))
            return memo.get(root);
        // 抢root，然后去下下家
        int do_rob = root.val + (root.left == null? 0 : (rob(root.left.left) + rob(root.left.right)))+(root.right == null? 0 : (rob(root.right.left) + rob(root.right.right)));
        // 不抢root，然后去下家
        int not_rob = rob(root.left) + rob(root.right);
        
        int res = Math.max(do_rob, not_rob);
        memo.put(root, res);
        return res;
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