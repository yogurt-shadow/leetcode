#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution748 {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        unordered_map<char, int> mp;
        for(auto ele: licensePlate){
            if(ele >= 'a' && ele <= 'z'){
                mp[ele]++;
            }
            else if(ele >= 'A' && ele <= 'Z'){
                mp[ele - 'A' + 'a']++;
            }
        }
        string ans = "";
        for(auto word: words){
            unordered_map<char, int> cur;
            for(auto ele: word){
                cur[ele]++;
            }
            bool match = true;
            for(auto ele: mp){
                if(cur[ele.first] < ele.second){
                    match = false;
                    break;
                }
            }
            if(match){
                if(ans == "" || word.length() < ans.length()){
                    ans = word;
                }
            }
        }
        return ans;
    }
};