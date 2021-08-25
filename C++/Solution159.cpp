#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution159 {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> mp;
        int ans = 0;
        int left = 0;
        for(int right = 0; right < s.length(); right++){
            mp[s[right]]++;
            while(mp.size() > 2){
                mp[s[left]] --;
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
    unordered_map<int, int> mp = {{1, 2}, {2, 3}};
    cout << mp.size() << endl;
    mp.erase(2);
    cout << mp.size() << endl;
    return 0;
}