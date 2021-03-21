#include<iostream>
#include<vector>
using namespace std;

struct TrieNode{
    int cnt = 0;
    TrieNode* children[2]{};
};

class Solution5696 {
    vector<int> nums;
    TrieNode* root;

    int count(int x){
        int res = 0;
        for(auto ele: nums){
            res += dfs(root, 0, ele, 15, x);
        }
        return res;
    }

    int dfs(TrieNode* p, int now, int num, int k, int high){
        int cur = (num & (1 << k)) ? 1 : 0;
        int res = 0;
        if(p -> children[cur]){
            if((now ^ (1 << k)) - 1 <= high){
                res += p -> children[cur] -> cnt;
            }
            else{
                res += dfs(p -> children[cur], now, num, k - 1, high);
            }
        }
        if(p -> children[1 - cur] && (now ^ (1 << k)) <= high){
            res += dfs(p -> children[1 - cur], now ^ (1 << k), num, k - 1, high);
        }
        return res;
    }

public:
    int countPairs(vector<int>& nums, int low, int high) {
        root = new TrieNode();
        this -> nums = nums;
        for(auto num: nums){
            TrieNode* p = root;
            for(int k = 15; k >= 0; k--){
                int cur = (num & (1 << k)) ? 1 : 0;
                if(!p -> children[cur]){
                    p -> children[cur] = new TrieNode();
                }
                p = p -> children[cur];
                p -> cnt++;
            }
        }
        return (count(high) - count(low - 1)) / 2;
    }
};