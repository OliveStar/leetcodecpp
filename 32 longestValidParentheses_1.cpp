class Solution {
public:
    // 算法1：括号匹配问题，用栈数据结构来处理。
    // 遍历字符串，如果当前字符是'('，将该字符下标进栈，以便后续匹配用
    // 如果当前字符是')'，根据栈顶元素进行判断
    // 栈顶元素如果是'('，表明出现了匹配的括号对，将栈顶元素出栈
    // 栈顶元素如果是')'，表明不能构成匹配的括号对，同样将下标进栈。
    // 遍历完整个字符串之后，栈中剩下的元素即是不能匹配的括号位置
    // 每两个相邻下标相减即是他们之间的匹配括号对长度，
    // 通过比较即可得出最长匹配括号对长度
    // 需要注意开始和最后匹配的括号对不要漏掉，如果最后栈空表明整个字符串都匹配括号对了。
    int longestValidParentheses(string s) {
        int maxLen = 0;
        int preIdx, curIdx;
        stack<int> stk;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || stk.empty())
                stk.push(i);
            else if(s[stk.top()] == '(')
                stk.pop();
            else
                stk.push(i);
        }

        preIdx = s.size();
        while(!stk.empty()){
            curIdx = stk.top();
            stk.pop();
            maxLen = max(maxLen, preIdx - curIdx - 1);
            swap(preIdx, curIdx);
        }
        maxLen = max(maxLen, preIdx);
        return maxLen;
    }
};