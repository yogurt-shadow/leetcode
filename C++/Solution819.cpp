#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<string>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution819 {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        string str = "";
        unordered_map<string, int> mp;
        for(auto ele: paragraph){
            if((ele >= 'a' && ele <= 'z')){
                str += ele;
            }
            else if(ele >= 'A' && ele <= 'Z'){
                str += ('a' + (ele - 'A'));
            }
            else{
                if(str != ""){
                    mp[str] ++;
                    str = "";
                }
            }
        }
        if(str != ""){
            mp[str] ++;
        }
        unordered_set<string> st;
        for(auto ele: banned){
            st.insert(ele);
        }
        int m = 0;
        string ans;
        for(auto ele: mp){
            if(st.count(ele.first)){
                continue;
            }
            if(ele.second > m){
                ans = ele.first;
                m = ele.second;
            }
        }
        return ans;
    }
};