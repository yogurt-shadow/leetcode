#include<iostream>
#include<vector>

using namespace std;

class Solution1004 {
public:
    int longestOnes(vector<int>& A, int K) {
        int size = A.size();
        int left = 0, right = 0;
        int count = A[0];
        int len = 0;
        while(right < size){
            if(count + K >= right - left + 1){
                len = max(len, right - left + 1);
                right++;
                if(right < size && A[right] == 1){
                    count++;
                }
            }
            else{
                if(A[left] == 1){
                    count--;
                }
                left++;
            }
        }
        return len;
    }
};