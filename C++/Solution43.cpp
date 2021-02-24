#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution43 {
public:
    string multiply(string num1, string num2) {
        int size1 = num1.length(), size2 = num2.length();
        vector<int> answer(size1 + size2);
        for(int i = size2 - 1; i >= 0; i--){
            int carry = 0;
            for(int j = size1 - 1; j >= 0; j--){
                int cur = (num1[j] - '0') * (num2[i] - '0') + answer[i + j + 1] + carry;
                carry = cur / 10;
                answer[i + j + 1] = cur % 10;
            }
            if(carry > 0){
                answer[i] += carry;
            }
        }
        string result = "";
        int start = 0;
        while(start < answer.size() && answer[start] == 0){
            start++;
        }
        if(start == answer.size()){
            return "0";
        }
        for(int i = start; i < answer.size(); i++){
            result += answer[i] + '0';
        }
        return result;
    }
};

int main(){
    Solution43 s;
    cout << s.multiply("123", "456");
    return 0;
}