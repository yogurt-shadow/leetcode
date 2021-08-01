#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>

using namespace std;

class Solution1652 {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int size = code.size();
        vector<int> pre(size);
        if (k == 0){
            return pre;
        }
        int sum = 0;
        if(k > 0){
            for(int i = 1; i <= k; i++){
                sum += code[i];
            }
            pre[0] = sum;
            for(int i = 1; i < size; i++){
                sum -= code[i];
                sum += code[(i + k) % size];
                pre[i] = sum;
            }
        }
        else{
            k = -k;
            for(int i = size - 2; i >= size - 1 - k; i--){
                sum += code[i];
            }
            pre[size - 1] = sum;
            for(int i = size - 2; i >= 0; i--){
                sum -= code[i];
                int other = i - k;
                sum += (other >= 0 ? code[other] : code[size + other]);
                pre[i] = sum;
            }
        }
        return pre;
    }
};

int main(){
    cout << (-1 % 3) << endl;
    return 0;
}