#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<stack>
using namespace std;

class Solution77 {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> store;
        fill(res, store, n, k, 0, 1);
        return res;
    }

    void fill(vector<vector<int>>& res, vector<int>& store, int n, int k, int size, int index){
        if(size == k){
            vector<int> copy(store.begin(), store.end());
            res.push_back(copy);
            return;
        }
        for(int i = index; i <= n; i++){
            store.push_back(i);
            fill(res, store, n, k, size + 1, i + 1);
            store.pop_back();
        }
    }
};