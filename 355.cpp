https://leetcode.com/problems/design-twitter/
class Twitter {
public:
    map<int, map<int, int>> user_follows;
    vector<pair<int, int>> all;
    Twitter() {   }

    void postTweet(int userId, int tweetId) {
        all.push_back(make_pair(userId, tweetId));
    }


    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        for (auto& twit : all)
        {
            if (twit.first == userId || user_follows[userId].find(twit.first) != user_follows[userId].end())
            {
                res.push_back(twit.second);
            }
        }
        std::reverse(res.begin(),res.end());
        if (res.size() > 10)
            res.resize(10);
        return res;
    }


    void follow(int followerId, int followeeId) {
        user_follows[followerId][followeeId] = 1;
    }


    void unfollow(int followerId, int followeeId) {
        if (user_follows.find(followerId) != user_follows.end())
        {
            user_follows[followerId].erase(followeeId);
        }
    }
};
