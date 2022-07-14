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
        算法：BFS + 双端队列
        按层数的奇偶，来决定每一层的输出顺序。根节点为第0层。偶数层从左往右，奇数层从右往左
        层次遍历的顺序依然是从左往右，结果的存储顺序用双端队列来控制
        维护一个变量isOrderLeft。
        isOrderLeft为true，说明从左往右遍历，节点插入双端队列的尾部
        isOrderLeft为false，说明从右往左遍历，节点插入双端队列的头部。
     */
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> ans = new LinkedList<List<Integer>>();
        if(root == null){
            return ans;
        }

        Queue<TreeNode> nodeQueue = new ArrayDeque<TreeNode>();
        nodeQueue.offer(root);
        boolean isOrderLeft = true;

        while(!nodeQueue.isEmpty()){
            Deque<Integer> levelList = new LinkedList<Integer>();
            int size = nodeQueue.size();
            for(int i = 0;i < size; i++){
                TreeNode curNode = nodeQueue.poll();
                if(isOrderLeft){
                    levelList.offerLast(curNode.val);
                }else{
                    levelList.offerFirst(curNode.val);
                }
                if(curNode.left != null){
                    nodeQueue.offer(curNode.left);
                }
                if(curNode.right != null){
                    nodeQueue.offer(curNode.right);
                }
            }
            ans.add(new LinkedList<Integer>(levelList));
            isOrderLeft = !isOrderLeft;
        }

        return ans;
    }
}