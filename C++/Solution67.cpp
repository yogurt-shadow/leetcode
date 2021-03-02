#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution67 {
public:
    string addBinary(string a, string b) {
        while(a.length() > b.length()){
            b = '0' + b;
        }
        while(a.length() < b.length()){
            a = '0' + a;
        }
        string res = "";
        int carry = 0;
        for(int i = a.length() - 1; i >= 0; i--){
            int sum = a[i] - '0' + b[i] - '0' + carry;
            if(sum >= 2){
                carry = 1;
                res = ((char) (sum - 2 + '0')) + res;
            }
            else{
                carry = 0;
                res = ((char) (sum + '0')) + res;
            }
        }
        if(carry == 1){
            res = "1" + res;
        }
        return res;
    }
};