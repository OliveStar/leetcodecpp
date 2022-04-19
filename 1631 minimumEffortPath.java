class Solution {
    // 把二维数组中每个(x,y)坐标看做一个节点，上下左右坐标就是相邻节点
    // 它对应的值和相邻坐标对应的值之差的绝对值就是题目说的“体力消耗”，相当于边的权重
    // 本题评价路径长短的标准不再是路径经过的权重综合，而是路径经过的权重最大值
    
    // 方向数组，上下左右的坐标偏移量
    int[][] dirs = new int[][]{{0,1},{1,0},{0,-1},{-1,0}};
    // 返回坐标(x,y)的上下左右相邻坐标
    List<int[]> adj(int[][] matrix, int x, int y){
        int m = matrix.length, n = matrix[0].length;
        // 存储相邻节点
        List<int[]> neighbors = new ArrayList<>();
        for(int[] dir : dirs){
            int nx = x + dir[0];
            int ny = y + dir[1];
            if(nx >= m || nx < 0 || ny >= n || ny < 0){
                // 索引越界
                continue;
            }
            neighbors.add(new int[]{nx, ny});
        }
        return neighbors;
    }

    // Dijkstra算法，计算(0,0)到(m-1, n-1)的最小体力消耗
    public int minimumEffortPath(int[][] heights) {
        int m = heights.length, n = heights[0].length;
        // 定义：从(0,0)到(i,j)的最小体力消耗是effortTo[i][j]
        int[][] effortTo = new int[m][n];
        // dp table 初始化为正无穷
        for(int i = 0; i < m; i++){
            Arrays.fill(effortTo[i], Integer.MAX_VALUE);
        }
        // base case，起点到起点的最小消耗就是0
        effortTo[0][0] = 0;

        // 优先级队列，effortFromStart 较小的排在前面
        Queue<State> pq = new PriorityQueue<>((a,b) -> {
            return a.effortFromStart - b.effortFromStart;
        });

        // 从起点(0,0)开始进行BFS
        pq.offer(new State(0,0,0));

        while(!pq.isEmpty()){
            State curState = pq.poll();
            int curX = curState.x;
            int curY = curState.y;
            int curEffortFromStart = curState.effortFromStart;

            // 到达终点提前结束
            if(curX == m-1 && curY == n-1){
                return curEffortFromStart;
            }

            if(curEffortFromStart > effortTo[curX][curY]){
                continue;
            }

            // 将(curX, curY)的相邻坐标装入队列
            for(int[] neighbor : adj(heights, curX, curY)){
                int nextX = neighbor[0];
                int nextY = neighbor[1];
                // 计算从(curX, curY) 达到(nextX, nextY)的消耗
                int effortToNextNode = Math.max(
                    effortTo[curX][curY],
                    Math.abs(heights[curX][curY] - heights[nextX][nextY])
                );
                // 更新dp table
                if(effortTo[nextX][nextY] > effortToNextNode){
                    effortTo[nextX][nextY] = effortToNextNode;
                    pq.offer(new State(nextX, nextY, effortToNextNode));
                }
            }
        }
        // 正常情况不会达到这个return
        return -1;
    }
}

class State{
    // 矩阵中的一个位置
    int x, y;
    // 从起点(0,0)到当前位置的最小体力消耗（距离）
    int effortFromStart;

    State(int x, int y, int effortFromStart){
        this.x = x;
        this.y = y;
        this.effortFromStart = effortFromStart;
    }
}