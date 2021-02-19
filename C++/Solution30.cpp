#include<iostream>
#include<vector>

#include<unordered_map>
using namespace std;

class Solution30 {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(words.size() == 0){
            return vector<int>(0);
        }
        vector<int> result;
        unordered_map<string, int> map;
        for(auto ele: words){
            map[ele]++;
        }
        int len = words[0].length();
        int left = 0, right = len * words.size() - 1;
        while(right < s.length()){
            unordered_map<string, int> map2;
            for(int i = left; i <= right; i += len){
                string str = s.substr(i, len);
                map2[str]++;
            }
            bool match = true;
            for(auto ele: words){
                if(map2[ele] != map[ele]){
                    match = false;
                    break;
                }
            }
            if(match){
                result.push_back(left);
            }
            left++;
            right++;
        }
        return result;
    }
};

int main(){
    Solution30 s;
    string s1 = "a";
    vector<string> words = {"a"};
    vector<int> result = s.findSubstring(s1, words);
}