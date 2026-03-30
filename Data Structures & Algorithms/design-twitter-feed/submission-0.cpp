class Twitter {
public:

    int timestamp;
    unordered_map<int, vector<pair<int,int>>> tweets;
    unordered_map<int, unordered_set<int>> follows;

    Twitter() {
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> q;
        for(auto t: tweets[userId]) {
            q.push(t);
        }
        for(int f: follows[userId]) {
            for(auto t: tweets[f]) {
                q.push(t);
            }
        }
        vector<int> res;
        int count = 10;
        while(!q.empty() && count > 0) {
            res.push_back(q.top().second);
            q.pop();
            count--;
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId) {
            follows[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if(follows[followerId].count(followeeId)) {
            follows[followerId].erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */