// 不限制使用long的解法
// 不限制算法使用 long，只是解释为什么在溢出时，返回 2^31-1
class Solution {
public:
    // 算法说明：
    // 第1步:
    // dividend和divisor均有正数和负数两种可能，当且仅当其中一者为负数时，结果为负。
    // 为了方便，我们可以先记录最终结果的正负号，然后将dividend和divisor都当成正数来处理；
    // 因为被除数和除数只为整数, 不会出现 被小数除 的情况, 所以结果的 数字部分 <= 被除数的数字部分
    // 唯一可能出现溢出的是 -2^31 / -1 = 2^31 会溢出32位有符号的整数部分，但如果我们都当成正数处理，就可以避免这种情况
    // 第2步：
    // 现在两者都满足x >= 0，然后利用dividend和divisor均为int，可以确定商的绝对值落在[0, dividend]范围内（当且仅当divisor是范围在[0,1]的浮点数时，答案大于dividend）
    // 假设商为x，我们可以通过二分法找到商
    // 大于x的数y满足y*divisor>dividend
    // 小于x的数y不满足y*divisor>dividend
    // y*divisor需要用到乘法，我们需要实现需要实现一个「不用乘法符号」的乘法实现（使用倍增乘法）
    int INF = INT_MAX;
    int divide(int dividend, int divisor) {
        long a = dividend, b = divisor;
        bool flag = false; // flag = true，商为负
        if((a < 0 && b > 0) || (a > 0 && b < 0)) flag = true;
        if(a < 0) a = -a;
        if(b < 0) b = -b;
        long l = 0, r = a;
        while(l < r){
            long mid = l + r + 1 >> 1; // +-和左移右移位运算符优先级相同
            if(mul(mid, b) <= a) l = mid;
            else r = mid - 1;
        }
        r = flag? -r : r;
        if(r < -INF - 1 || r > INF) return INF;
        return (int)r;
    }

    // 倍增乘法 a * k
    long mul(long a, long k){
        long ans = 0;
        while(k > 0){
            if((k & 1) == 1) ans += a;
            k >>= 1;
            a += a;
        }
        return ans;
    }
};