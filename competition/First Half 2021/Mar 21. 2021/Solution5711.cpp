#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution5711 {
public:
    int maxValue(int n, int index, int maxSum) {
        int left = 1; 
        int right = maxSum;
        if(satisfy(n, index, maxSum, right)){
            return right;
        }
        while(right - left > 1){
            int mid = (left + right) / 2;
            if(satisfy(n, index, maxSum, mid)){
                left = mid;
            }
            else{
                right = mid;
            }
        }
        return left;
    }

    bool satisfy(int n, int index, int maxSum, int num){
        long long sum = 0;
        long long number = num;
        int left = index - (number - 1);
        if(left < 0){
            sum += (2 * number - 1 - index) * index / 2;
        }
        else{
            int len = index - left;
            sum += (2 * number - 1 - len) * len / 2;
            sum += index - len;
        }
        int right = index + (number - 1);
        if(right >= n){
            int len = n - 1 - index;
            sum += (2 * number - 1 - len) * len / 2;
        }
        else{
            int len = right - index;
            sum += (2 * number - 1 - len) * len / 2;
            sum += n - 1 - index - len;
        }
        sum += num;
        return sum <= maxSum;
    }
};