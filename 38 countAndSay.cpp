class Solution {
public:
    // 迭代生成字符串
    // 算法：将字符串分割为最小数量的组，每个组都由连续的最多相同字符组成
    // 所以只要按顺序遍历，更新计数变量，遇到与前面不一样的数字，就将分组统计结果加入到结果字符串中。
    // 字符串处理：用to_string函数将计数转化为字符串，还可以用sprintf或stringstream
    string countAndSay(int n) {
        if(n <= 0) return "";
        if(n == 1) return "1";

        string curStr = "1", newStr = "";
        // 迭代生成字符串的第n项
        for(int i = 0; i < n - 1; i++){
            int cnt = 1; // 每个新的外观数列项都需要重置计数变量
            // 内层循环遍历数列每1项的字符串
            for(int j = 1; j < curStr.size(); j++){
                if(curStr[j] == curStr[j-1]) cnt++;
                else{
                    newStr += to_string(cnt);
                    newStr += curStr[j-1];
                    cnt = 1;
                }
            }
            // 处理最后一组数
            newStr += to_string(cnt);
            newStr += curStr[curStr.size() - 1];
            curStr = newStr;
            newStr = "";
        }

        return curStr;
    }
};