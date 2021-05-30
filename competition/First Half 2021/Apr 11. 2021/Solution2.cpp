#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

class Solution2 {
public:
    int findTheWinner(int n, int k) {
        int size = n;
        vector<int> vec(n + 1);
        int cur = 1;
        while(size > 1){
            int copy = k;
            while(copy > 1){
                cur++;
                if(cur > n){
                    cur -= n;
                }
                if(!vec[cur]){
                    copy--;
                }
            }
            vec[cur] = 1;
            //cout << cur << endl;
            size--;
            while(vec[cur]){
                cur++;
                if(cur > n){
                    cur -= n;
                }
            }
        }
        for(int j = 1; j <= n; j++){
            if(!vec[j]){
                return j;
            }
        }
        return -1;
    }
};