#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution804 {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string mp[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", 
                        "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", 
                        "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
        unordered_set<string> st;
        for(auto ele: words){
            string cur;
            for(auto ele2: ele){
                cur += mp[ele2 - 'a'];
            }
            if(st.count(cur) == 0){
                st.insert(cur);
            }
        }
        return st.size();
    }
};