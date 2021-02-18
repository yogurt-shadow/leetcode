#include<iostream>
#include<vector>

#include<algorithm>
using namespace std;

bool cmp(int x, int y){
    return abs(x) > abs(y);
}

class Solution1005 {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end(), cmp);
        for(int i = 0; i < A.size(); i++){
            if(A[i] < 0 && K > 0){
                A[i] = -A[i];
                K--;
            }
        }
        int sum = 0;
        for(auto ele: A){
            sum += ele;
        }
        return K % 2 == 0 ? sum : sum - 2 * A[A.size() - 1];
    }
};