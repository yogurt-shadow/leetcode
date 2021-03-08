#include<iostream>
#include<vector>

using namespace std;

class Solution131 {
public:
    vector<vector<int>> dp;
    int size;
    string str;
    vector<vector<string>> partition(string s) {
        size = s.length();
        str = s;
        dp.resize(size, vector<int>(size));
        for(int i = 0; i < size; i++){
            dp[i][i] = 1;
            if(i + 1 < size){
                if(s[i] == s[i + 1]){
                    dp[i][i + 1] = 1;
                }
            }
        }
        for(int len = 3; len <= size; len++){
            for(int left = 0; left + len - 1 < size; left++){
                int right = left + len - 1;
                if(s[left] == s[right]){
                    dp[left][right] = dp[left + 1][right - 1];
                }
            }
        }
        vector<vector<string>> res;
        vector<string> store;
        fill(res, store, 0);
        return res;
    }

    void fill(vector<vector<string>>& res, vector<string>& store, int index){
        if(index >= size){
            res.push_back(store);
            return;
        }
        for(int i = index; i < size; i++){
            if(dp[index][i]){
                store.push_back(str.substr(index, i - index + 1));
                fill(res, store, i + 1);
                store.pop_back();
            }
        }
    }
};