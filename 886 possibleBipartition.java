// 如果把每个人都看做图中的节点，相互讨厌的关系看做图中的边，dislikes数组可以构成一幅图
// 互相讨厌的人不能放在同一组里，相当于图中的所有相邻节点都要放进两个不同的组
// 将问题转化为双色问题，用两种颜色着色所有节点，且相邻节点颜色都不同，按照颜色把这些节点分成两组
class Solution {
    private boolean ok = true;
    private boolean[] color;
    private boolean[] visited;

    public boolean possibleBipartition(int n, int[][] dislikes) {
        // 图节点编号为 1...n
        color = new boolean[n+1];
        visited = new boolean[n+1];
        // 转化成邻接表表示图结构
        List<Integer>[] graph = buildGraph(n, dislikes);

        for(int v = 1; v <= n; v++){
            if(!visited[v]){
                traverse(graph, v);
            }
        }

        return ok;
    }

    // 建图函数
    private List<Integer>[] buildGraph(int n, int[][] dislikes){
        // 图节点编号为 1...n
        List<Integer>[] graph = new LinkedList[n+1];
        for(int i = 1; i <= n; i++){
            graph[i] = new LinkedList<>();
        }
        for(int[] edge : dislikes){
            int v = edge[1];
            int w = edge[0];
            // 无向图相当于双向图
            // v->w
            graph[v].add(w);
            // w->v
            graph[w].add(v);
        }
        return graph;
    }

    // 和之前的traverse函数完全相同
    private void traverse(List<Integer>[] graph, int v){
        if(!ok) return;
        visited[v] = true;
        for(int w : graph[v]){
            if(!visited[w]){
                color[w] = !color[v];
                traverse(graph, w);
            }else{
                if(color[w] == color[v]){
                    ok = false;
                }
            }
        }
    }
}