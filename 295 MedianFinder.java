// 求数据流的中位数
// 构造两个优先队列，一个是大顶堆small，从小到大存储较小的一半数据，一个是小顶堆large，从大到小存储较大的一半数据
// 中位数通过大顶堆和小顶堆顶部元素计算出来：如果n是偶数，两个堆的堆顶元素的平均数就是中位数；如果n是奇数，元素多的那个堆的堆顶元素就是中位数
// 限制条件：1.两个堆中的元素之差不能超过1；2.large堆的堆顶元素要大于等于small堆的堆顶元素


class MedianFinder {

    // 小顶堆，相当于从大到小的有序数组
    private PriorityQueue<Integer> large;
    // 大顶堆，相当于从小到大的有序数组
    private PriorityQueue<Integer> small;

    public MedianFinder() {
        // 小顶堆
        large = new PriorityQueue<>();
        // 大顶堆
        small = new PriorityQueue<>((a,b) -> {
            return b-a;
        });
    }
    
    public void addNum(int num) {
        // 不是直接向数据少的堆里添加数，而是加进堆里后，利用堆的特性挤出堆顶元素
        // 这样可以保证large堆的堆顶元素大于等于small堆的堆顶元素
        if(small.size() >= large.size()){
            small.offer(num);
            large.offer(small.poll());
        }else{
            large.offer(num);
            small.offer(large.poll());
        }
    }
    
    public double findMedian() {
        // 如果元素不一样多，多的那个堆的堆顶元素就是中位数
        if(large.size() < small.size()){
            return small.peek();
        }else if(large.size() > small.size()){
            return large.peek();
        }
        // 如果元素一样多，两个堆堆顶元素的平均数是中位数
        return (large.peek() + small.peek()) / 2.0;
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */