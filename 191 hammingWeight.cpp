// 191.汉明重量
// 算法：n&(n-1)可以去掉二进制表示中的最后1个1，用一个循环不停消去1，直到n为0为止。
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res=0;
        while(n!=0){
            n = n&(n-1);
            res++;
        }
        return res;
    }
};