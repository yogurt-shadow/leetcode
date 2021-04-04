#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution190 {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for(int i = 0; i <= 31; i++){
            int cur = n & (1 << i) ? 1 : 0;
            res = res | (cur << (31 - i));
        }
        return res;
    }
};