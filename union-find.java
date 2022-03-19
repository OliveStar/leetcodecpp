/**
 * 并查集数据结构实现要点
 * 用parent数组记录每个节点的父节点，用parent存储一个森林
 * 用size数组记录每棵树的重量，目的是让union后树依然拥有平衡性，而不会退化成链表，影响操作效率
 * 在find函数中进行路径压缩，保证任意树的高度保持在常数，使得union和connected API的时间复杂度为O(1)
 * 时间复杂度：find O(logN)，union，connected O(1)
 */
class UF{
    // 记录连通分量个数
    private int count;
    // 存储若干棵树
    private int[] parent; // parent[x]表示x所在的子树的根节点
    // 记录树的“重量”，用于路径压缩
    private int[] size; // size[x]表示根节点为x的树的节点数

    public UF(int n){
        this.count = n;
        parent = new int[n];
        size = new int[n];
        for(int i = 0; i < n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    /**将p和q连通 */
    public void union(int p, int q){
        int rootP = find(p);
        int rootQ = find(q);
        if(rootP == rootQ)
            return;
        
        // 小树接到大树下面，较平衡
        if(size[rootP] > size[rootQ]){
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        }else{
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }
        count--;
    }

    /**判断p和q是否互相连通 */
    public boolean connected(int p, int q){
        int rootP = find(p);
        int rootQ = find(q);
        // 处于同一棵树上的节点，相互连通
        return rootP == rootQ;
    }

    /**返回节点x的根节点 */
    private int find(int x){
        while(parent[x] != x){
            // 进行路径压缩
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    public int count(){
        return count;
    }
}