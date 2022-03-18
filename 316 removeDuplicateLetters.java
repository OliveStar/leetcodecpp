// 数组去重最难的一类题，解题思路是数组+单调栈
// 1.通过inStack这个布尔数组做到栈stk中不存在重复元素
// 2.顺序遍历字符串s，通过栈这种顺序结构的push/pop操作记录结果字符串（可以处理刚刚插入的字符），保证了字符出现的顺序和s中出现的顺序一致
// 3.用单调栈的思路，配合计数器count不断pop掉不符合最小字典序的字符，保证了最终得到的结果字典许最小
class Solution {
    public String removeDuplicateLetters(String s) {
        Stack<Character> stk = new Stack<>();
        // 维护一个计数器记录字符串中字符的数量
        // 因为输入为ASCII字符，大小256够用了
        int[] count = new int[256];
        for(int i = 0; i < s.length(); i++){
            count[s.charAt(i)]++;
        }

        boolean[] inStack = new boolean[256];
        for(char c : s.toCharArray()){
            // 每遍历过一个字符，都将对应的计数减一
            count[c]--;
            if(inStack[c]) continue;
            while(!stk.isEmpty() && stk.peek() > c){
                // 若之后不存在栈顶元素了，则停止pop
                if(count[stk.peek()] == 0){
                    break;
                }
                // 若之后还有，则可以pop
                inStack[stk.pop()] = false;
            }
            stk.push(c);
            inStack[c] = true;
        }

        StringBuilder sb = new StringBuilder();
        while(!stk.empty()){
            sb.append(stk.pop());
        }
        return sb.reverse().toString();
    }
}