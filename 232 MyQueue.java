class MyQueue {
    private Stack<Integer> s1, s2;
    public MyQueue() {
        s1 = new Stack<>();
        s2 = new Stack<>();
    }
    /* 添加元素到队尾 */
    public void push(int x) {
        s1.push(x);
    }
    
    /* 删除队头元素并返回 */
    public int pop() {
        // 先调用peek()保证s2非空
        peek();
        return s2.pop();
    }
    
    /* 返回队头元素 */
    public int peek() {
        if(s2.isEmpty()){
            // 把s1元素压入s2
            while(!s1.isEmpty())
                s2.push(s1.pop());
        }
        return s2.peek();
    }
    
    public boolean empty() {
        return s1.isEmpty() && s2.isEmpty();
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */