#include<iostream>
#include<unordered_set>
#include<algorithm>
using namespace std;


class Solution5693 {
public:
    int secondHighest(string s) {
        unordered_set<int> st;
        for(auto ele: s){
            if(ele >= '0' && ele <= '9'){
                int x = ele - '0';
                if(st.count(x) == 0){
                    st.insert(x);
                }
            }
        }
        if(st.size() < 2){
            return -1;
        }
        vector<int> vec;
        for(auto ele: st){
            vec.push_back(ele);
        }
        sort(vec.begin(), vec.end());
        return vec[vec.size() - 2];
    }
};