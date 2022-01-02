class Solution {
public:
    // 第9题 首尾循环比较的解法
    bool isPalindrome(int x) {
        if(x == 0) return true; // 0是回文数
        if(x < 0 || x % 10 == 0) return false; // 负数和10的倍数不是回文数
        int div = 1;
        while(x/div >= 10) div *= 10; // 获得能取得最高位数字的除数
        while(x>0){
            if(x/div != x%10) return false; // 比较最高位和最低位
            x %= div; // 剔除最高位
            x /= 10; // 剔除最低位
            div /= 100;
        }
        return true;
    }
};