#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<string>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution551 {
public:
    int absent = 0;
    int last = 0;

    bool checkRecord(string s) {
        for(auto ele: s){
            if(ele == 'A'){
                last = 0;
                absent ++;
                if(absent >= 2){
                    return false;
                }
            }
            else if(ele == 'L'){
                last ++;
                if(last == 3){
                    return false;
                }
            }
            else{
                last = 0;
            }
        }
        return true;
    }
};