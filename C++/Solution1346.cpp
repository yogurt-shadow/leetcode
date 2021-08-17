#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution1346 {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> st;
        for(auto ele: arr){
            if(st.count(ele * 2) || (ele % 2 == 0 && st.count(ele / 2))){
                return true;
            }
            st.insert(ele);
        }
        return false;
    }
};