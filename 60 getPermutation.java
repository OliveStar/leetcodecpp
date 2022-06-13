class Solution {
    // 算法：模拟法
    /**
        1.把候选数放在一个 有序列表 里，从左到右根据「剩下的数的阶乘数」确定每一位填谁，公式：
            k / (后面几位的阶乘数) 的值 = 候选数组的下标；
        2. 选出一个数以后，k 就需要减去相应跳过的阶乘数的倍数；
        3. 已经填好的数需要从候选列表里删除，注意保持列表的有序性（因为排列的定义是按照字典序）；
        4. 由于这里考虑的是下标，第 k 个数，下标为 k - 1，一开始的时候，k--。
    **/
    // 数据结构：每次选出一个数，就将这个数从列表里面拿出。这个列表需要支持频繁的删除操作，因此使用双链表。在 Java 中 LinkedList 就是使用双链表实现的。
    // 时间复杂度：O(N^2)，空间复杂度：O(N)， N为数组长度
    public String getPermutation(int n, int k) {
        // 在n个数字的全排列中找到下标为k-1的数，因此k先减1
        k--;

        int[] factorial = new int[n];
        factorial[0] = 1;
        // 先算出所有的阶乘值
        for(int i = 1; i < n; i++){
            factorial[i] = factorial[i - 1] * i;
        }

        List<Integer> nums = new LinkedList<>();
        for(int i = 1; i <= n; i++){
            nums.add(i);
        }

        StringBuilder sb = new StringBuilder();

        // i表示剩余的数字个数，初始化为n - 1
        for(int i = n - 1; i >= 0; i--){
            int index = k / factorial[i];
            sb.append(nums.remove(index));
            k -= index * factorial[i];
        }

        return sb.toString();
    }
}