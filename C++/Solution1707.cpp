#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;


struct TrieNode{
    int val = INT_MAX;
    TrieNode* children[2]{};
};

class Solution1707 {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        TrieNode* root = new TrieNode();
        for(auto num: nums){
            TrieNode* p = root;
            for(int i = 30; i >= 0; i--){
                int cur = (num & (1 << i)) ? 1 : 0;
                if(!p -> children[cur]){
                    p -> children[cur] = new TrieNode();
                }
                p = p -> children[cur];
                p -> val = min(p -> val, num);
            }
        }
        vector<int> res;
        for(auto query: queries){
            TrieNode* p = root;
            int m = query[1], x = query[0];
            int ans = 0;
            bool finish = true;
            for(int i = 30; i >= 0; i--){
                if(x & (1 << i)){
                    if(p -> children[0] && p -> children[0] -> val <= m){
                        ans ^= (1 << i);
                        p = p -> children[0];
                    }
                    else if(!p -> children[1] || p -> children[1] -> val > m){
                        res.push_back(-1);
                        finish = false;
                        break;
                    }
                    else{
                        p = p -> children[1];
                    }
                }
                else{
                    if(p -> children[1] && p -> children[1] -> val <= m){
                        ans ^= (1 << i);
                        p = p -> children[1];
                    }
                    else if(!p -> children[0] || p -> children[0] -> val > m){
                        res.push_back(-1);
                        finish = false;
                        break;
                    }
                    else{
                        p = p -> children[0];
                    }
                }
            }
            if(finish){
                res.push_back(ans);
            }
        }
        return res;
    }
};