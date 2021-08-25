#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution345 {
public:
    string reverseVowels(string s) {
        vector<int> vec;
        unordered_set<char> st = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for(int index = 0; index < s.length(); index++) {
            if(st.count(s[index])){
                vec.push_back(index);
            }
        }
        int left = 0, right = vec.size() - 1;
        while(right > left){
            char l = s[vec[left]], r = s[vec[right]];
            s[vec[left]] = r;
            s[vec[right]] = l;
            left ++;
            right --;
        }
        return s;
    }
};