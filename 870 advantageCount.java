class Solution {
    // 田忌赛马加强版，算法策略：打得赢就打，打不赢就跑
    public int[] advantageCount(int[] nums1, int[] nums2) {
        int n = nums1.length;
        // 给 nums2 降序排序
        // nums2中元素的顺序不能改变，因为计算结果的顺序依赖nums2的顺序，所以不能直接对nums2进行排序，而是利用其他数据结构来辅助
        PriorityQueue<int[]> maxpq = new PriorityQueue<>(
            (int[] pair1, int[] pair2) -> {
                return pair2[1] - pair1[1];
            }
        );
        for(int i = 0; i < n; i++){
            maxpq.offer(new int[] {i, nums2[i]});
        }
        // 给nums1升序排序
        Arrays.sort(nums1);

        // nums1[left]是最小值，nums1[right]是最大值
        int left = 0, right = n-1;
        int[] res = new int[n];
        while(!maxpq.isEmpty()){
            int[] pair = maxpq.poll();
            // maxval是nums2中的最大值，i是对应索引
            int i = pair[0], maxval = pair[1];
            if(maxval < nums1[right]){
                // 如果nums1[right]能胜过maxval，那就自己上
                res[i] = nums1[right];
                right--;
            }else{
                // 否则用最小值换掉nums2的较大值
                res[i] = nums1[left];
                left++;
            }
        }
        return res;
    }
}