/*
正则完全匹配
test case 1: s="aa" p="a"
test case 2: s="aa" p="a*"
test case 3: s="ab" p=".*"
test case 4: s="aab" p="c*a*b"
test case 5: s="mississippi" p="mis*is*p*."
test case 6: s="aa" p="a*aa"
test case 7: s="a" p="ab*c*"
test case 8: s="abc" p="a.*"
*/
class Solution {
    unordered_map<string, bool> memo;
public:
    bool isMatch(string s, string p) {
        // 指针 i,j从索引 0 开始移动
        return dp(s,0,p,0);
    }

    /* dp函数定义：
    若dp(s,i,p,j) = true, 则表示s[i…]可以匹配p[j…]
    若dp(s,i,p,j) = false, 则表示s[i…]无法匹配p[j…]
    */
    // 计算p[j…]是否匹配s[i…]
    bool dp(string& s, int i, string& p, int j){
        int m = s.size(),n = p.size();
        // base case 1：模式串p已经全部被匹配，如果本串恰好也匹配完，说明匹配成功
        if(j == n){
            return i == m;
        }
        // base case2：本串s已经全部被匹配，只要p[j…]能匹配空串，就算完成匹配
        if(i == m){
            // 如果能匹配空串，一定是字符和'*'成对儿出现
            if((n - j) % 2 == 1){
                return false;
            }
            // 检查是否为x*y*z*这种形式
            for(;j + 1 < n; j += 2){
                if(p[j + 1] != '*'){
                    return false;
                }
            }
            return true;
        }

        // 记录状态(i,j)，消除重叠子问题
        string key = to_string(i) + "," + to_string(j);
        if(memo.count(key)) return memo[key];

        bool res = false;

        if(s[i] == p[j] || p[j] == '.'){
            // 当前字符匹配
            if(j < n-1 && p[j+1] == '*'){
                // 1.1 通配符'*'匹配0次或多次
                res = dp(s,i,p,j+2) || dp(s,i+1,p,j);
            }else{
                // 1.2 通配符'.'常规匹配1次
                res = dp(s, i+1, p, j+1);
            }
        }else{
            // 当前字符不匹配
            if(j < n-1 && p[j+1] == '*'){
                // 2.1 通配符'*'匹配0次
                res = dp(s,i,p,j+2);
            }else{
                // 2.2 没有通配符'*' 无法继续匹配
                res = false;
            }
        }

        //将当前结果记录备忘录
        memo[key] = res;
        
        return res;
    }
};