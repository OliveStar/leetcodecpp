/* 暴力求解法
class Solution {
    int base = 1337;
    // 计算a的k次方然后与base求模的结果
    // 使用模幂公式避免溢出 (a*b)%k = (a%k)(b%k)%k
    int mypow(int a, int k){
        // 对因子求模
        a %= base;
        int res = 1;
        for(int i = 0; i < k; i++){
            // 可能溢出
            res *= a;
            // 对乘法结果求模
            res %= base;
        }
        return res;
    }
public:
    int superPow(int a, vector<int>& b){
        // 递归的base case
        if(b.empty()) return 1;
        // 取出最后一个数
        int last = b.back();
        b.pop_back();
        // 将原问题化简，缩小规模递归求解
        int part1 = mypow(a, last);
        int part2 = mypow(superPow(a, b), 10);
        // 合并出结果，每次乘法都要求模
        return (part1 * part2) % base;
    }
};
*/

/* 递归法高效求幂
class Solution{
        // 递归快速求幂：把问题规模减半，复杂度log(N)级别
        // a^b = a * a^(b-1)，b为奇数
        // (a^(b/2))^2，b为偶数
        int base = 1337;
        // 计算a的k次方然后与base求模的结果
        // 使用模幂公式避免溢出 (a*b)%k = (a%k)(b%k)%k
        int mypow(int a, int k){
            if(k == 0) return 1;
            a %= base;
            if(k % 2 == 1){
                // k是奇数
                return (a * mypow(a, k-1)) % base;
            }else{
                // k是偶数
                int sub = mypow(a, k / 2);
                return (sub * sub) % base;
            }
        }   

    public:
        int superPow(int a, vector<int>& b){
            // 递归的base case
            if(b.empty()) return 1;
            // 取出最后一个数
            int last = b.back();
            b.pop_back();
            // 将原问题化简，缩小规模递归求解
            int part1 = mypow(a, last);
            int part2 = mypow(superPow(a, b), 10);
            // 合并出结果，每次乘法都要求模
            return (part1 * part2) % base;
        }
};
*/

// 快速幂算法
class Solution{
        // 快速幂公式，复杂度log(N)级别
        int base = 1337;
        // 计算x的n次方然后与base求模的结果
        // 使用模幂公式避免溢出 (a*b)%k = (a%k)(b%k)%k
        int qpow(int x, int n){
            int res = 1;
            while(n){
                if(n & 1) res = ((res % base) * (x % base)) % base;
                x = (x % base) * (x % base) % base;
                n >>= 1;
            }
            return res;
        }   

    public:
        int superPow(int a, vector<int>& b){
            // 递归的base case
            if(b.empty()) return 1;
            // 取出最后一个数
            int last = b.back();
            b.pop_back();
            // 将原问题化简，缩小规模递归求解
            int part1 = qpow(a, last);
            int part2 = qpow(superPow(a, b), 10);
            // 合并出结果，每次乘法都要求模
            return (part1 * part2) % base;
        }
};