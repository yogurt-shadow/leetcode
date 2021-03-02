#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution66 {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        vector<int> res(size + 1);
        int carry = 0;
        int sum = digits[size - 1] + 1;
        if(sum >= 10){
            carry = 1;
        }
        res[size] = sum % 10;
        for(int i = size - 2; i >= 0; i--){
            sum = digits[i] + carry;
            if(sum >= 10){
                carry = 1;
            }
            else{
                carry = 0;
            }
            res[i + 1] = sum % 10;
        }
        if(carry == 1){
            res[0] = 1;
            return res;
        }
        else{
            return vector<int>(res.begin() + 1, res.end());
        }
    }
};