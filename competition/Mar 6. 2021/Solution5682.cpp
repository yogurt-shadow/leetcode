#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution5682 {
public:
    int beautySum(string s) {
        int res = 0;
        for(int i = 0; i < s.length(); i++){
            multiset<int> set;
            vector<int> freq(26);
            for(int j = i; j < s.length(); j++){
                if(set.count(freq[s[j] - 'a']) > 0){
                    set.erase(set.find(freq[s[j] - 'a']));
                }
                freq[s[j] - 'a']++;
                set.insert(freq[s[j] - 'a']);
                int m1 = *set.begin();
                int m2 = *set.rbegin();
                res += m2 - m1;
            }
        }
        return res;
    }
};