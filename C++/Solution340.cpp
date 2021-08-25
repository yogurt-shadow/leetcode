#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<map>
using namespace std;


class Solution340 {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> mp;
        int left = 0;
        int ans = 0;
        for(int right = 0; right < s.length(); right++){
            mp[s[right]]++;
            while(mp.size() > k){
                mp[s[left]]--;
                if(mp[s[left]] == 0){
                    mp.erase(s[left]);
                }
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

int main(){
    unordered_map<char, int> mp = {{'1', 2}, {'2', 3}};
    mp.erase('1');
    cout << mp.size() << endl;
    return 0;
}