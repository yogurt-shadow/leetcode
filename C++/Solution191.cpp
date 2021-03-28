#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution191 {
public:
    int hammingWeight(uint32_t n) {
        int x = 0;
        for(int i = 31; i >= 0; i--){
            int cur = n & (1 << i);
            if(cur){
                x++;
            }
        }
        return x;
    }
};

int main(){
    uint32_t x = 12312;
    cout << (x & 1) << endl;
    return 0;
}