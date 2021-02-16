#include<iostream>
#include<vector>

using namespace std;

class Solution6 {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }
        string result = "";
        int size = s.length();
        for(int i = 0; i < numRows; i++){
            int step = 2 * (numRows - i - 1);
            if(i == numRows - 1){
                step = 2 * (numRows - 1);
            }
            if(step != 2 * (numRows - 1)){
                step = 2 * (numRows - 1) - step;
            }
            for(int j = i; j < size; j += step){
                result += s[j];
                if(step != 2 * (numRows - 1)){
                    step = 2 * (numRows - 1) - step;
                }
            }
        }
        return result;
    }
};

int main(){
    Solution6 s;
    string test = "PAYPALISHIRING";
    cout << s.convert(test, 3);
    return 0;
}