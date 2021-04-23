#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<string>
#include<stack>

using namespace std;
typedef long long ll;

class Solution726 {
public:
    string countOfAtoms(string formula) {
        auto mp = count(formula);
        string res = "";
        for(auto ele: mp){
            res += ele.first;
            if(ele.second > 1){
                res += to_string(ele.second);
            }
        }
        return res;
    }

    map<string, int> count(string formula){
        map<string, int> mp;
        string str = "";
        int index = 0;
        int number = 0;
        while(index < formula.length()){
            char cur = formula[index];
            if(cur >= 'A' && cur <= 'Z'){
                int index2 = index + 1;
                str = cur;
                while(index2 < formula.length()){
                    if(formula[index2] >= 'a' && formula[index2] <= 'z'){
                        str += formula[index2];
                        index2++;
                    }
                    else if(formula[index2] >= '0' && formula[index2] <= '9'){
                        number = 10*number + formula[index2] - '0';
                        index2++;
                    }
                    else if((formula[index2] >= 'A' && formula[index2] <= 'Z') || formula[index2] == '('){
                        break;
                    }
                }
                if(number == 0){
                    number = 1;
                }
                mp[str] += number;
                number = 0;
                str = "";
                index = index2;
            }
            else if(cur == '('){
                int index2 = index + 1;
                //cout << "index2 " << index2 << endl;
                int pos = 1;
                while(index2 < formula.length()){
                    if(formula[index2] == '('){
                        pos++;
                    }
                    else if(formula[index2] == ')'){
                        pos--;
                        if(pos == 0){
                            break;
                        }
                    }
                    index2++;
                }
                string mid = formula.substr(index + 1, index2 - index - 1);
                //cout << "index2 " << index2 << endl;
                auto mp2 = count(mid);
                index2++;
                int number2 = 0;
                //cout << number2 << endl;
                while(index2 < formula.length()){
                    if(formula[index2] >= '0' && formula[index2] <= '9'){
                        number2 = 10 * number2 + formula[index2] - '0';
                    }
                    else if(formula[index2] >= 'A' && formula[index2] <= 'Z'){
                        break;
                    }
                    index2++;
                }
                //cout << mp["O"] << endl;
                if(number2 == 0){
                    number2 = 1;
                }
                //cout << number2 << endl;
                for(auto ele: mp2){
                    mp[ele.first] += ele.second * number2;
                }
                index = index2 + 1;
                //cout << mp["O"] << endl;
            }
            cout << "index1 " << index << endl;
        }
        return mp;
    }
};

int main(){
    Solution726 s;
    cout << s.countOfAtoms("H2O") << endl;
    return 0;
}




















