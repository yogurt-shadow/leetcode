#include<iostream>
#include<vector>

using namespace std;

class Jianzhi48 {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.length();
        if(size == 0){
            return 0;
        }
        int left = 0, right = 0, len = 0;
        vector<int> freq(128);
        freq[s[0]]++;
        while(right < size){
            if(match(freq)){
                len = max(len, right - left + 1);
                right++;
                if(right < size){
                    freq[s[right]]++;
                }
            }
            else{
                freq[s[left]]--;
                left++;
            }
        }
        return len;
    }

    bool match(vector<int>& freq){
        for(auto ele: freq){
            if(ele > 1){
                return false;
            }
        }
        return true;
    }
};