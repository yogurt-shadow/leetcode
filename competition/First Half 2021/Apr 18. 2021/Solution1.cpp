#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<cstring>

using namespace std;
using ll = long long;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> freq(26);
        for(auto ele: sentence){
            freq[ele - 'a']++;
        }
        for(auto ele: freq){
            if(!ele){
                return false;
            }
        }
        return true;
    }
};

int main(){

    return 0;
}