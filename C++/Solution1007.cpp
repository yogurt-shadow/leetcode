#include<iostream>
#include<vector>

using namespace std;

class Solution1007 {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int result = INT_MAX;
        int x = A[0];
        if(check(A, B, x)){
            int cur1 = 0, cur2 = 0;
            for(auto ele: A){
                if(ele != x){
                    cur1++;
                }
            }
            for(auto ele: B){
                if(ele != x){
                    cur2++;
                }
            }
            result = min(result, min(cur1, cur2));
        }
        int y = B[0];
        if(check(A, B, y)){
            int cur1 = 0, cur2 = 0;
            for(auto ele: A){
                if(ele != y){
                    cur1++;
                }
            }

            for(auto ele: B){
                if(ele != y){
                    cur2++;
                }
            }
            result = min(result, min(cur1, cur2));
        }
        return result == INT_MAX ? -1 : result;
    }

    bool check(vector<int>& v1, vector<int>& v2, int x){
        for(int i = 0; i < v1.size(); i++){
            if(v1[i] != x && v2[i] != x){
                return false;
            }
        }
        return true;
    }
};