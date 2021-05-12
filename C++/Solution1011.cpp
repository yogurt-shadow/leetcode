#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<stack>

using namespace std;
typedef long long ll;

class Solution1011 {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int m = -1;
        int sum = 0;
        for(auto ele: weights){
            m = max(m, ele);
            sum += ele;
        }
        int left = m;
        int right = sum;
        if(match(weights, left, D)){
            return left;
        }
        while(right - left > 1){
            int mid = (right -  left) / 2 + left;
            if(match(weights, mid, D)){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        return left;
    }

    bool match(vector<int>& weights, int load, int D){
        int day = 0;
        int index = 0;
        int cur = 0;
        while(index < weights.size()){
            if(cur + weights[index] <= load){
                index ++;
                cur += weights[index];
            }
            else{
                cur = weights[index];
                day ++;
                index ++;
            }
        }
        day ++;
        return day <= D;
    }
};