#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<stack>
using namespace std;

class Solution71 {
public:
    string simplifyPath(string path) {
        string res = "";
        stack<string> stk;
        vector<string> path2 = split(path, '/');
        for(string str: path2){
            if(str == "."){
                continue;
            }
            if(str == ".."){
                if(!stk.empty()){
                    stk.pop();
                }
            }
            else{
                stk.push(str);
            }
        }
        if(stk.empty()){
            return "/";
        }
        while(!stk.empty()){
            res = stk.top() + res;
            res = "/" + res;
            stk.pop();  
        }
        return res;
    }

    vector<string> split(string path, char x){
        vector<string> res;
        int start = 0;
        while(start < path.length()){
            while(start < path.length() && path[start] == x){
                start++;
            }
            if(start == path.length()){
                return res;
            }
            int end = start;
            while(end < path.length() && path[end] != x){
                end++;
            }
            end--;
            res.push_back(path.substr(start, end - start + 1));
            start = end + 1;
        }
        return res;
    }
};

int main(){
    Solution71 s;
    string str = "/hom/////e/";
    vector<string> test = s.split(str, '/');
    for(auto ele: test){
        cout << ele << " ";
    }
}