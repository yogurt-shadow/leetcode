#include<iostream>
#include<vector>
#include<string>

using namespace std;

typedef long long ll;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;

class Solution401 {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for(int hour = 0; hour <= 11; hour++){
            for(int minute = 0; minute <= 59; minute++){
                int cur = 0;
                for(int i = 0; i < 4; i++){
                    if((1 << i) & hour){
                        cur ++;
                    }
                }
                for(int i = 0; i < 6; i++){
                    if((1 << i) & minute){
                        cur ++;
                    }
                }
                if(cur == turnedOn){
                    string str = to_string(hour) + ":" + (minute < 10 ? "0" + to_string(minute) : to_string(minute));
                    ans.push_back(str);
                }
            }
        }
        return ans;
    }
};