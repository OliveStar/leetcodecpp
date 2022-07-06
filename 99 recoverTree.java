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
    /**
        算法：显式中序遍历
        二叉搜索树按照中序遍历，存到一个数组里，应该是单调递增的。
        我们再遍历数组，如果发现前一个数i比后一个数j大，就找到了不一致的数，我们应该会找到两个这样的数，第一个是i，第二个是j。
        时间复杂度：O(N),N为二叉树的搜索节点数，中序遍历需要O(N)，判断两个交换节点，最好情况O(1)，最坏情况O(N)。
        空间复杂度：O(N)，需要额外使用一个辅助数组
     */
    public void recoverTree(TreeNode root) {
        List<TreeNode> list = new ArrayList<TreeNode>();
        dfs(root, list);
        TreeNode x = null, y = null;
        for(int i = 0; i < list.size() - 1; i++){
            if(list.get(i).val > list.get(i+1).val){
                y = list.get(i+1);
                if(x == null){
                    x = list.get(i);
                }
            }
        }
        if(x != null && y != null){
            int tmp = x.val;
            x.val = y.val;
            y.val = tmp;
        }
    }

    void dfs(TreeNode root, List<TreeNode> list){
        if(root == null)
            return;
        dfs(root.left, list);
        list.add(root);
        dfs(root.right, list);
    }
}