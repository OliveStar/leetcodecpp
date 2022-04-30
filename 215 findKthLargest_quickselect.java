class Solution {
    // 快速选择解法
    // 快排的partition函数会将nums[p]排到正确的位置，把p和k比较
    // 如果p < k，说明第k大的元素在nums[p+1..hi]中
    // 如果p > k，说明第k大的元素在nums[lo..p-1]中
    // 时间复杂度：O(N)，不洗牌最差是O(N^2)
    // 空间复杂度：O(1)
    public int findKthLargest(int[] nums, int k) {
        // 随机打乱数组
        shuffle(nums);
        int lo = 0, hi = nums.length-1;
        // 索引转化，第k个最大的元素，就是nums升序排序后索引为len(nums)-k的元素
        k = nums.length-k;
        while(lo <= hi){
            // 在nums[lo..hi]中选一个分界点
            int p = partition(nums, lo, hi);
            if(p < k){
                // 第k大的元素在nums[p+1..hi]中
                lo = p + 1;
            }else if(p > k){
                // 第k大的元素在nums[lo..p-1]中
                hi = p - 1;
            }else{
                // 找到第k大元素
                return nums[p];
            }
        }
        return -1;
    }

    int partition(int[] nums, int lo, int hi){
        if(lo == hi) return lo;
        // 将nums[lo]作为默认分界点pivot
        int pivot = nums[lo];
        // j = hi+1 因为while中会先执行--
        int i = lo, j = hi+1;
        while(true){
            // 保证nums[lo..i]都小于pivot
            while(nums[++i] < pivot){
                if(i == hi) break;
            }
            // 保证nums[j..hi]都大于pivot
            while(nums[--j] > pivot){
                if(j == lo) break;
            }
            if(i >= j) break;
            // 如果走到这里，一定有：
            // nums[i] > pivot && nums[j] < pivot
            // 所以需要交换nums[i]和nums[j]
            // 保证nums[lo..i] < pivot < nums[j..hi]
            swap(nums, i, j);
        }

        // 将pivot值交换到正确的位置
        swap(nums, j, lo);
        // 现在nums[lo..j-1] < nums[j] < nums[j+1..hi]
        return j;
    }

    // 交换数组中的两个元素
    void swap(int[] nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    // 对数组元素进行随机打乱
    void shuffle(int[] nums){
        int n = nums.length;
        Random rand = new Random();
        for(int i = 0; i < n; i++){
            // 从i到最后随机选一个元素
            int r = i + rand.nextInt(n-i);
            swap(nums, i, r);
        }
    }
}