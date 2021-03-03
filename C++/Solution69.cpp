#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution69 {
public:
    int mySqrt(int x) {
        if(x <= 1){
            return x;
        }
        int lower = 1, upper = x;
        while(upper - lower > 1){
            int mid = (upper - lower) / 2 + lower;
            long long middle = mid;
            middle = middle * middle;
            if(middle == x){
                return mid;
            }
            if(middle < x){
                lower = mid;
            }
            else{
                upper = mid;
            }
        }
        return lower;
    }
};