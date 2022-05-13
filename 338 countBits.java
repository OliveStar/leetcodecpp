class Solution {
    // 算法1：位运算
    // 性质：n&(n-1)消除数字 n 的二进制表示中的低位 1
    // n的二进制表示中1的个数就是n&(n-1)的二进制表示中1的个数再加1
    // 利用位运算可以减少时间复杂度。如果用哈希表存储，暴力遍历。例如20，要查8次，位运算只要比较2次。
    
    public int[] countBits(int n) {
        int[] bits = new int[n+1]; // 备忘录数组，避免重复计算
        for(int i = 1; i <= n; i++){
            bits[i] = bits[i&(i-1)] + 1;
        }
        return bits;
    }

    // 算法2：奇偶性
    // 性质：数字非奇即偶，奇数比前一个偶数多1。4=100，5=101；6=110，7=111
    // 偶数n的二进制表示中1的个数和n/2中1的个数是一样的
    // 12 = 1100 -> 6 = 110 -> 3 = 11
    // 通过判断数字是奇数还是偶数，快速获得
    /*
    public int[] countBits(int n) {
        int[] bits = new int[n+1]; // 备忘录数组，避免重复计算
        for(int i = 1; i <= n; i++){
            bits[i] = ((i&1) == 1? bits[i-1]+1 : bits[i >> 1]);
        }
        return bits;
    }*/
}