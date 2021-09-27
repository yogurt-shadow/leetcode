#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

bool cmp(string& a, string& b){
    if(a.length() == b.length()){
        for(int i = 0; i < a.length(); i++){
            if(a[i] != b[i]){
                return a[i] < b[i];
            }
        }
    }
    return a.length() > b.length();
}


class Solution524 {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end(), cmp);
        for(auto ele: dictionary){
            int index = 0;
            for(int i = 0; i < s.length(); i++){
                if(index < ele.length() && s[i] == ele[index]){
                    index ++;
                }
            }
            if(index == ele.length()){
                return ele;
            }
        }
        return "";
    }
};

int main(){
    vector<string> s = {"c", "abcas", "basd", "bcsad", "a"};
    sort(s.begin(), s.end(), cmp);
    for(auto ele: s){
        cout << ele << endl;
    } 
    return 0;
}