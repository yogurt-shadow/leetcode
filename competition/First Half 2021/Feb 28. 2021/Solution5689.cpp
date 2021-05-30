#include<iostream>
#include<vector>

using namespace std;

class Solution5689 {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int index = 0;
        if(ruleKey == "color"){
            index = 1;
        }
        else if(ruleKey == "name"){
            index = 2;
        }
        int res = 0;
        for(auto ele: items){
            if(ele[index] == ruleValue){
                res++;
            }
        }
        return res;
    }
};