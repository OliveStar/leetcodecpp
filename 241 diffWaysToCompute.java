class Solution {
    // 时间复杂度：等价于算式所有的合法括号组合，卡特兰数
    // 备忘录,优化重复计算：1+1+1+1+1，不同括号添加方式，同样数字的结果，剪枝
    HashMap<String, List<Integer>> memo = new HashMap<>();
    public List<Integer> diffWaysToCompute(String expression) {
        // 避免重复计算
        if(memo.containsKey(expression)){
            return memo.get(expression);
        }

        List<Integer> res = new LinkedList<>();
        for(int i = 0; i < expression.length(); i++){
            char c = expression.charAt(i);
            // 扫描算式 input 中的运算符
            if(c == '-' || c == '*' || c == '+'){
                /** 分 */
                // 以运算符为中心，分割成两个字符串，分别递归计算
                List<Integer> left = diffWaysToCompute(expression.substring(0,i));
                List<Integer> right = diffWaysToCompute(expression.substring(i+1));
                /** 治 */
                // 通过子问题的结果，合成原问题的结果
                for(int a : left)
                    for(int b : right)
                        if(c == '+')
                            res.add(a + b);
                        else if(c == '-')
                            res.add(a - b);
                        else if(c == '*')
                            res.add(a * b);
            }
        }

        // base case
        // 如果res为空，说明算式是一个数字，没有运算符
        if(res.isEmpty()){
            res.add(Integer.parseInt(expression));
        }

        // 将结果添加进备忘录
        memo.put(expression, res);
        return res;
    }
}