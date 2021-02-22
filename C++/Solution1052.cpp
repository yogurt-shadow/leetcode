#include<iostream>
#include<vector>

using namespace std;

class Solution1052 {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int days = customers.size();
        int sum = 0;
        for(int i = 0; i < days; i++){
            if(grumpy[i] == 0){
                sum += customers[i];
            }
        }
        int left = 0, right = X - 1;
        int cur = 0;
        for(int i = left; i <= right; i++){
            if(grumpy[i] == 1){
                cur += customers[i];
            }
        }
        int max_num = cur;
        while(right + 1 < days){
            right++;
            if(grumpy[right] == 1){
                cur += customers[right];
            }
            if(grumpy[left] == 1){
                cur -= customers[left];
            }
            left++;
            max_num = max(max_num, cur);
        }
        return max_num + sum;
    }
};