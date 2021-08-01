#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>

using namespace std;

class Self1 {
public:
    string convert(string str){
        int num = 0;
        string ans;
        bool have = false;
        int i = 0;
        while(i < str.length()){
            auto cur = str[i];
            if(cur >= '0' && cur <= '9'){
                num = 10 * num + (cur - '0');
                have = true;
                i ++;
            }
            else if((cur >= 'a' && cur <= 'z') || (cur >= 'A' && cur <= 'Z')){
                if(!have){
                    num = 1;
                }
                ans.push_back(cur);
                i ++;
            }
            else if(cur == '['){
                int right = i + 1;
                int state = 1;
                for(; right < str.length(); right++){
                    auto cur2 = str[right];
                    if(cur2 == '['){
                        state ++;
                    }
                    else if(cur2 == ']'){
                        state --;
                        if(state == 0){
                            break;
                        }
                    }
                }
                auto copy = str.substr(i + 1, right - i - 1);
                auto inner = convert(copy);
                ans += inner;
                i = right + 1;
            }
        }
        return repeat(num, ans);
    }

    string repeat(int num, string str){
        string ans;
        while(num){
            num --;
            ans += str;
        }
        return ans;
    }
};

int main(){
    Self1 s;
    auto input = "A[10BC[2D]]";
    auto output = s.convert(input);
    cout << output << endl;
    return 0;
}