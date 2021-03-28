#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution5715 {
public:
    int reinitializePermutation(int n) {
        vector<int> perm(n);
        for(int i = 0; i < n; i++){
            perm[i] = i;
        }
        int res = 1;
        vector<int> copy(perm.begin(), perm.end());
        perm = action(perm);
        while(!match(perm, copy)){
            res++;
            perm = action(perm);
        }
        return res;
    }

    vector<int> action(vector<int>& vec){
        vector<int> res(vec.size());
        for(int i = 0; i < vec.size(); i++){
            if(i % 2 == 0){
                res[i] = vec[i / 2];
            }
            else{
                res[i] = vec[vec.size() / 2 + (i - 1) / 2];
            }
        }
        return res;
    }

    bool match(vector<int>& vec1, vector<int>& vec2){
        for(int i = 0; i < vec1.size(); i++){
            if(vec1[i] != vec2[i]){
                return false;
            }
        }
        return true;
    }
};