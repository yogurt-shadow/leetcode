#include<iostream>
#include<vector>

using namespace std;

class Solution896 {
public:
    bool isMonotonic(vector<int>& A) {
        return isMonotonic1(A) || isMonotonic2(A);
    }

    bool isMonotonic1(vector<int>& A){
        for(int i = 0; i + 1 < A.size(); i++){
            if(A[i + 1] > A[i]){
                return false;
            }
        }
        return true;
    }

    bool isMonotonic2(vector<int>& A){
        for(int i = 0; i + 1 < A.size(); i++){
            if(A[i + 1] < A[i]){
                return false;
            }
        }
        return true;
    }
};