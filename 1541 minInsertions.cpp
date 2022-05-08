class Solution {
public:
    int minInsertions(string s) {
        // res记录左括号的插入次数
        // need记录需右括号的需求量
        int res = 0, need = 0;

        for(int i = 0; i < s.size(); i++){
            // 一个左括号对应两个右括号
            if(s[i] == '('){
                need += 2;
                // 当遇到左括号时，若对右括号的需求量为奇数，需要插入1个右括号
                // 右括号的需求必须为偶数
                if(need % 2 == 1){
                    // 插入一个右括号
                    res++;
                    // 对右括号的需求减一
                    need--;
                }
            }

            if(s[i] == ')'){
                need--;
                // 说明右括号太多了
                if(need == -1){
                    // 需要插入一个左括号
                    res++;
                    // 同时，对右括号的需求变为1
                    need = 1;
                }
            }
        }

        return res + need;
    }
};