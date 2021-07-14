#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

class Solution274 {
public:
    int hIndex(vector<int>& citations) {
        int res = 0;
        sort(citations.begin(), citations.end());
        for(int i = citations.size() - 1; i >= 0; i--){
            int cur = citations[i];
            res = max(res, min(cur, (int) citations.size() - i));
        }
        return res;
    }
};