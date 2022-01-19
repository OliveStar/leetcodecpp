class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        int pre = 0;
        int cur = 1;
        int fn = 0;
        for(int i = 2; i <= n;i++){
            fn = pre + cur;
            pre = cur;
            cur = fn;
        }
        return fn;
    }
};