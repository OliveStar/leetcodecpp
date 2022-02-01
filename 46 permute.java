class Solution {
    List<List<Integer>> res = new LinkedList<>();
    
    /* 主函数，输入一组不重复的数字，返回它们的全排列 */
    public List<List<Integer>> permute(int[] nums) {
        // 记录「路径」
        LinkedList<Integer> trace = new LinkedList<Integer>();
        backtrace(nums, trace);
        return res;
    }

    // 路径：记录在 trace 中
    // 选择列表：nums 中不存在于 trace 的那些元素
    // 结束条件：nums 中的元素全都在 trace 中出现
    void backtrace(int[] nums, LinkedList<Integer> trace){
        // 触发结束条件
        if(trace.size() == nums.length){
            res.add(new LinkedList(trace));
            return;
        }

        for(int i = 0; i < nums.length; i++){
            // 排除不合法的选择
            if(trace.contains(nums[i]))
                continue;
            // 做选择
            trace.add(nums[i]);
            // 进入下一层决策树
            backtrace(nums, trace);
            // 取消选择
            trace.removeLast();
        }
    }
}