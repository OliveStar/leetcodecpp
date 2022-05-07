class ExamRoom {
    // 算法：二叉平衡树
    // 将端点p映射到以p为左端点的线段
    private Map<Integer, int[]> startMap;
    // 将端点p映射到以p为右端点的线段
    private Map<Integer, int[]> endMap;
    // 根据线段长度从小到大存放所有线段
    private TreeSet<int[]> pq;
    private int N;

    public ExamRoom(int n) {
        this.N = n;
        startMap = new HashMap<>();
        endMap = new HashMap<>();
        pq = new TreeSet<>((a, b) -> {
            // 算出两个线段的长度
            int distA = distance(a);
            int distB = distance(b);
            // 如果长度相同，就比较索引
            if(distA == distB)
                return b[0] - a[0];
            // 长度更长的更大，排后面
            return distA - distB;
        }
        );
        // 在有序集合中先放一个虚拟线段
        addInterval(new int[]{-1, N});
    }
    
    /** 去除一个线段 */
    private void removeInterval(int[] intv){
        pq.remove(intv);
        startMap.remove(intv[0]);
        endMap.remove(intv[1]);
    }

    /** 增加一个线段 */
    private void addInterval(int[] intv){
        pq.add(intv);
        startMap.put(intv[0], intv);
        endMap.put(intv[1], intv);
    }

    /** 计算一个线段的长度 */
    private int distance(int[] intv){
        int x = intv[0];
        int y = intv[1];
        if(x == -1) return y;
        if(y == N) return N - 1 - x;
        // 中点到端点的长度，计算与最近的邻居之间的距离
        return (y - x) / 2;
    }

    public int seat() {
        // 从有序集合拿出最长的线段
        int[] longest = pq.last();
        int x = longest[0];
        int y = longest[1];
        int seat;
        if(x == -1){
            // 情况一：队头没有人入座
            seat = 0;
        }else if(y == N){
            // 情况二：队尾没有人入座
            seat = N - 1;
        }else{
            // 情况三：头尾都有人
            seat = (y - x) / 2 + x;
        }
        // 将最长的线段分成两段
        int[] left = new int[]{x, seat};
        int[] right = new int[]{seat, y};
        removeInterval(longest);
        addInterval(left);
        addInterval(right);
        return seat;
    }
    
    public void leave(int p) {
        // 将p左右的线段找出来
        int[] right = startMap.get(p);
        int[] left = endMap.get(p);
        // 合并两个线段成为一个线段
        int[] merged = new int[] {left[0], right[1]};
        removeInterval(left);
        removeInterval(right);
        addInterval(merged);
    }
}

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(n);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */