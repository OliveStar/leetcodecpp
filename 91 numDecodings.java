class Solution {
    // 算法：动态规划
    public int numDecodings(String s) {
        int n = s.length();
        // 题目存在前导零，往字符串头部追加空格作为哨兵，既可以避免讨论前导零，也能使下标从1开始，简化f[i-1]等负数下标的判断
        s = " " + s;
        char[] cs = s.toCharArray();
        int[] f = new int[n+1];
        f[0] = 1;
        for(int i = 1; i <= n; i++){
            // a：代表【当前位置】单独形成item
            // b：代表【当前位置】与【前一位置】共同形成item
            int a = cs[i] - '0', b = (cs[i-1] - '0') * 10 + (cs[i] - '0');
            // 如果a属于有效值，那么f[i]可以由f[i-1]转移过来
            if(1 <= a && a <= 9) f[i] = f[i-1];
            // 如果b属于有效值，那么f[i]可以由f[i-2]或者f[i-1]&f[i-2]转移过来
            if(10<= b && b <= 26) f[i] += f[i-2];
        }
        return f[n];
    }
}