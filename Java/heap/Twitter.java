import java.util.List;
import java.util.LinkedList;

import java.util.Map;
import java.util.HashMap;

import java.util.Set;
import java.util.HashSet;

class Twitter {
    List<user_tweet> tweet_set;
    Map<Integer, Set<Integer>> map;

    private class user_tweet{
        int user;
        int tweet;
        public user_tweet(int user, int tweet){
            this.user = user;
            this.tweet = tweet;
        }

        public int user(){
            return user;
        }

        public int tweet(){
            return tweet;
        } 
    }

    /** Initialize your data structure here. */
    public Twitter() {
        tweet_set = new LinkedList<>();
        map = new HashMap<>();
    }
    
    /** Compose a new tweet. */
    public void postTweet(int userId, int tweetId) {
        tweet_set.add(new user_tweet(userId, tweetId));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    public List<Integer> getNewsFeed(int userId) {
        List<Integer> result = new LinkedList<>();
        for(int i = tweet_set.size() - 1; i >= 0; i--){
            if(tweet_set.get(i).user() == userId || map.containsKey(userId) && map.get(userId).contains(tweet_set.get(i).user())){
                result.add(tweet_set.get(i).tweet());
                if(result.size() == 10){
                    return result;
                }
            }
        }
        return result;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    public void follow(int followerId, int followeeId) {
       if(!map.containsKey(followerId)){
        map.put(followerId, new HashSet<>());
       }

       map.get(followerId).add(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    public void unfollow(int followerId, int followeeId) {
        if(map.containsKey(followerId) && map.get(followerId).contains(followeeId)){
        map.get(followerId).remove(followeeId);
    }
    }

    public static void main(String[] args){
        Twitter twitter = new Twitter();
        twitter.postTweet(1, 4);
        twitter.postTweet(2, 5);
        twitter.unfollow(1, 2);
        List<Integer> output = twitter.getNewsFeed(1);


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