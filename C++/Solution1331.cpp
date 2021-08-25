#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution1331 {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> copy(arr.begin(), arr.end());
        sort(arr.begin(), arr.end());
        int size = arr.size();
        unordered_map<int, int> mp;
        int index = 1;
        for(int i = 0; i < size; i++){
            if(mp.count(arr[i]) == 0){
                mp[arr[i]] = index;
                index ++;
            }
        }
        vector<int> ans(size);
        for(int i = 0; i < size; i++){
            ans[i] = mp[copy[i]];
        }
        return ans;
    }
};