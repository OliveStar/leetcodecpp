class Solution {
    public int findMinArrowShots(int[][] points) {
        if(points.length == 0) return 0;
        // 按end升序排序
        /* 数据容易溢出
        Arrays.sort(points, new Comparator<int[]>(){
            public int compare(int[] a, int[] b){
                return a[1] - b[1];
            }
        });*/
        Arrays.sort(points, (o1,o2)->{
            if(o1[1]>o2[1]) return 1;
            if(o1[1]<o2[1]) return -1;
            return 0;
        });
        // 至少有一个区间不相交
        int count = 1;
        // 排序后，第一个区间就是x
        int x_end = points[0][1];
        for(int[] interval : points){
            int start = interval[0];
            // 擦边就会射爆气球，所以边界不能重叠
            if(start > x_end){
                // 找到下一个选择的区间了
                count++;
                x_end = interval[1];
            }
        }
        return count;
    }
}