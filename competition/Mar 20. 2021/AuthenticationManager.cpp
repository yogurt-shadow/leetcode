#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
using namespace std;

class AuthenticationManager {
public:
    int duration;
    unordered_map<string, int> map;

    AuthenticationManager(int timeToLive) {
        duration = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        map[tokenId] = currentTime;
    }
    
    void renew(string tokenId, int currentTime) {
        if(map.count(tokenId) == 0 || map[tokenId] + duration <= currentTime){
            return;
        }
        map[tokenId] = currentTime;
    }
    
    int countUnexpiredTokens(int currentTime) {
        int res = 0;
        for(auto ele: map){
            if(ele.second + duration > currentTime){
                res++;
            }
        }
        return res;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */