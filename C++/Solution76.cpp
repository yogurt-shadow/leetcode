#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<stack>
using namespace std;

class Solution76 {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> map, store;
        for(auto ele: t){
            store[ele]++;
        }
        int left = 0, right = t.length() - 1;
        for(int i = left; i <= right; i++){
            map[s[i]]++;
        }
        int start = 0, end = 0, len = s.length() + 1;
        while(right < s.length()){
            if(match(map, store)){
                //cout << left << right << endl;
                if(right - left + 1 < len){
                    start = left;
                    end = right;
                    len = right - left + 1;
                }
                map[s[left]]--;
                left++;
            }
            else{
                if(right + 1 < s.length()){
                    map[s[right + 1]]++;
                }
                right++;
            }
        }
        if(len == s.length() + 1){
            return "";
        }
        return s.substr(start, len);
    }

    bool match(unordered_map<char, int>& map, unordered_map<char, int>& store){
        for(auto ele: store){
            if(map[ele.first] < store[ele.first]){
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution76 s;
    string str1 = "ADOBECODEBANC", str2 = "ABC";
    cout << s.minWindow(str1, str2) << endl;
    return 0;
}