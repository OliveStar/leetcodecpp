class MyStack {
    // 单队列实现
    Queue<Integer> q;
    int top_elem = 0;

    public MyStack() {
        q = new LinkedList<>();
    }
    
    /**添加元素到栈顶 */
    public void push(int x) {
        // x是队列的队尾，是栈的栈顶
        q.offer(x);
        top_elem = x;
    }
    
    /**删除栈顶元素并返回 */
    public int pop() {
        int size = q.size();
        // 留下队尾2个元素
        while(size > 2){
            q.offer(q.poll());
            size--;
        }
        // 记录新的队尾元素
        top_elem = q.peek();
        q.offer(q.poll());
        // 删除之前的队尾元素
        return q.poll();
    }
    
    /**返回栈顶元素 */
    public int top() {
        return top_elem;
    }
    
    /**判断栈是否为空 */
    public boolean empty() {
        return q.isEmpty();
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */