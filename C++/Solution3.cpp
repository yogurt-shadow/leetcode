#include<iostream>
#include<vector>
#include<map>
#include<unordered_set>

using namespace std;

class Solution3 {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0){
            return 0;
        }
        int left = 0;
        int right = 0;
        unordered_set<char> have;
        have.insert(s[0]);
        int max_len = 1;
        while(right + 1 < s.length()){
            right += 1;
            char cur = s[right];
            while(have.find(cur) != have.end()){
                have.erase(s[left]);
                left += 1;
            }
            have.insert(cur);
            max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
};

int main(){
    string test = "pwwkew";
    Solution3 s;
    cout << s.lengthOfLongestSubstring(test);
    return 0;
}