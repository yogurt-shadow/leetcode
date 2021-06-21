#include<iostream>
#include<vector>
#include<string>

using namespace std;

typedef long long ll;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;

class Solution949 {
public:
    int m = -1;

    string largestTimeFromDigits(vector<int>& arr) {
        vector<int> vec(4, 0);
        dfs(arr, 0, vec, 0);
        string res = "";
        string left = to_string(m / 100), right = to_string(m % 100);
        if(left.length() == 1){
            left = "0" + left;
        }
        if(right.length() == 1){
            right = "0" + right;
        }
        res = left + ":" + right;
        return m == -1 ? "" : res;
    }

    void dfs(vector<int>& arr, int index, vector<int>& vec, int cur){
        if(index == 4){
            int hour = cur / 100;
            if(hour >= 24){
                return;
            }
            int minute = cur % 100;
            if(minute >= 60){
                return;
            }
            m = max(m, cur);
        }
        else{
            for(int i = 0; i < 4; i++){
                if(vec[i]){
                    continue;
                }
                vec[i] = 1;
                dfs(arr, index + 1, vec, 10 * cur + arr[i]);
                vec[i] = 0;
            }
        }
    }
};