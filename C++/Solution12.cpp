#include<iostream>
#include<vector>


using namespace std;

class Solution12 {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> map = {
            {1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"}, {10, "X"}, {40, "XL"}, {50, "L"}, {90, "XC"}, 
            {100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"}
        };
        string result = "";
        int size = map.size();
        while(num > 0){
            for(int i = size - 1; i >= 0; i--){
                auto cur = map[i];
                if(num >= cur.first){
                    num = num - cur.first;
                    result += cur.second;
                    break;
                }
            }
        }
        return result;
    }
};

int main(){
    Solution12 s;
    cout << s.intToRoman(1994) << endl;
    return 0;
}