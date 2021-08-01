#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

class Solution3 {
public:
    vector<ll> vec;
    long long minimumPerimeter(long long neededApples){
        ll cur = 0;
        for(ll i = 1; ;i++){
            cur += 12 * i * i;
            if(cur >= neededApples){
                return i;
            }
        }
    }
};

int main(){

    return 0;
}

/*
2784381467700
70896
*/