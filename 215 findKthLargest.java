class Solution {
    // 二叉堆解法
    // 构造小顶堆，留下最大的k个元素，堆顶元素是堆中最小的元素，即第k个最大的元素
    // 时间复杂度：O(NLogK)
    // 空间复杂度：O(K)
    public int findKthLargest(int[] nums, int k) {
        // Java语言默认构造的小顶堆，堆顶是最小元素
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int e : nums){
            // 每个元素都要过一遍二叉堆
            pq.offer(e);
            // 堆中元素多于k个时，删除堆顶元素
            if(pq.size() > k){
                pq.poll();
            }
        }
        // pq中剩下的是nums中k个最大元素
        // 堆顶是最小的那个，即第k个最大元素
        return pq.peek();
    }
}