class Solution {
/*
    算法：将x的乘积(ret)每次翻番，同时将计数(cnt)翻倍
    cnt的二倍超出n时，重新计算pow(x, n-cnt)，ret*pow(n-cnt)就是最终结果
    n为负数时，用1除以相反数的计算结果
    边界情况：n的测试数据有INT_MIN，中间结果需要用long long 来表示
*/
    double getMyPow(double x, long long n){
        if(n < 0) return 1/getMyPow(x, abs(n));
        if(n == 0) return 1;
        long long cnt = 1;
        double ret = x;
        while(cnt * 2 <= n){
            ret *= ret;
            cnt *= 2;
        }
        return ret * getMyPow(x, n - cnt);
    }
public:
    double myPow(double x, int n) {
         return getMyPow(x, n);
    }
};