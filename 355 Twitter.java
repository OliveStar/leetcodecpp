class Twitter {
    private static int timestamp = 0;
    
    private static class Tweet{
        private int id;
        private int time;
        private Tweet next;

        // 需要传入推文内容(id)和发文时间
        public Tweet(int id, int time){
            this.id = id;
            this.time = time;
            this.next = null;
        }
    }

    // static int timestamp = 0
    private static class User{
        private int id;
        public Set<Integer> followed;
        // 用户发表的推文链表头结点
        public Tweet head;

        public User(int userId){
            followed = new HashSet<>();
            this.id = userId;
            this.head = null;
            // 关注一下自己
            follow(id);
        }

        public void follow(int userId){
            followed.add(userId);
        }

        public void unfollow(int userId){
            // 不可以取关自己
            if(userId != this.id)
                followed.remove(userId);
        }

        public void post(int tweetId){
            Tweet twt = new Tweet(tweetId, timestamp);
            timestamp++;
            // 将新建的推文插入链表头
            // 越靠前的推文time值越大
            twt.next = head;
            head = twt;
        }
    }

    // 我们需要一个映射将userId和User对象对应起来
    private HashMap<Integer, User> userMap = new HashMap<>();

    public Twitter() {

    }
    
    /** user发表一条tweet动态 */
    public void postTweet(int userId, int tweetId) {
        // 若userId不存在，则新建
        if(!userMap.containsKey(userId))
            userMap.put(userId, new User(userId));
        User u = userMap.get(userId);
        u.post(tweetId);
    }

   
    /** 返回该user关注的人（包括他自己）最近的动态id，最多10条，而且这些动态必须按从新到旧的时间线顺序排列 */
    public List<Integer> getNewsFeed(int userId) {
        List<Integer> res = new ArrayList<>();
        if(!userMap.containsKey(userId)) return res;
        // 关注列表的用户 Id
        Set<Integer> users = userMap.get(userId).followed;
        // 自动通过time属性从大到小排序，容量为users的大小
        PriorityQueue<Tweet> pq = new PriorityQueue<>(users.size(), (a, b) -> (b.time - a.time));

        // 先将所有链表头节点插入优先级队列
        for(int id : users){
            Tweet twt = userMap.get(id).head;
            if(twt == null) continue;
            pq.add(twt);
        }

        while(!pq.isEmpty()){
            // 最多返回10条就够了
            if(res.size() == 10) break;
            // 弹出time值最大的（最近发表的）
            Tweet twt = pq.poll();
            res.add(twt.id);
            // 将下一篇 Tweet 插入进行排序
            if(twt.next != null)
                pq.add(twt.next);
        }

        return res;
    }
    
     /** follower关注followee */
    public void follow(int followerId, int followeeId) {
        // 若follower不存在，则新建
        if(!userMap.containsKey(followerId)){
            User u = new User(followerId);
            userMap.put(followerId, u);
        }
        // 若followee不存在，则新建
        if(!userMap.containsKey(followeeId)){
            User u = new User(followeeId);
            userMap.put(followeeId, u);
        }
        userMap.get(followerId).follow(followeeId);
    }

    /** follower 取关 followee，如果Id不存在则什么都不做 */
    public void unfollow(int followerId, int followeeId){
        if(userMap.containsKey(followerId)){
            User flwer = userMap.get(followerId);
            flwer.unfollow(followeeId);
        }
    }
}

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * List<Integer> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */