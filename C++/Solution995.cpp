#include<iostream>
#include<vector>

using namespace std;

class Solution995 {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int count = 0, flip = 0;
        int size = A.size();
        vector<int> reverse(size);
        for(int i = 0; i < size; i++){
            flip = flip ^ reverse[i];
            if(flip == A[i]){
                if(i + K - 1 >= size){
                    return -1;
                }
                if(i + K - 1 < size - 1){
                    reverse[i + K] = reverse[i + K] ^ 1;
                }
                count++;
                flip = flip ^ 1;
            }
        }
        return count;
    }
};