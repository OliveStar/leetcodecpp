class Solution {
public:
    // 算法：以左括号为基准，通过维护对右括号的需求数need，来计算最小的插入次数
    int minAddToMakeValid(string s) {
        // res记录左括号的插入次数
        int res = 0;
        // need变量记录右括号的需求量
        int need = 0;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                // 对右括号的需求 +1
                need++;
            }
            
            if(s[i] == ')'){
                // 对右括号的需求 -1
                need--;
                // need == -1意味着右括号太多了
                if(need == -1){
                    need = 0;
                    // 需插入一个左括号
                    res++;
                }
            }
        }
        return res + need;
    }
};