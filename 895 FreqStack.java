class FreqStack {
    // 记录FreqStack中元素的最大频率
    int maxFreq = 0;
    // 记录FreqStack中每个val对应的出现频率（VF表）
    HashMap<Integer, Integer> valToFreq = new HashMap<>();
    // 记录频率freq对应的val列表（FV表）
    HashMap<Integer, Stack<Integer> > freqToVals = new HashMap<>();

    public FreqStack() {

    }
    
    public void push(int val) {
        // 修改VF表：val对应的freq加一
        int freq = valToFreq.getOrDefault(val, 0) + 1;
        valToFreq.put(val, freq);
        // 修改FV表：在freq对应的列表加上val
        freqToVals.putIfAbsent(freq, new Stack<>());
        freqToVals.get(freq).push(val);
        // 更新 maxFreq
        maxFreq = Math.max(maxFreq, freq);
    }
    
    public int pop() {
        // 修改FV表：pop出一个maxFreq对应的元素v
        Stack<Integer> vals = freqToVals.get(maxFreq);
        int v = vals.pop();
        // 修改VF表：v对应的freq减一
        int freq = valToFreq.get(v) - 1;
        valToFreq.put(v, freq);
        // 更新maxFreq
        if(vals.isEmpty()){
            // 如果 maxFreq对应的元素空了
            maxFreq--;
        }
        return v;
    }
}

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(val);
 * int param_2 = obj.pop();
 */