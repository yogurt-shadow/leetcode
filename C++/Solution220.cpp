#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<queue>
#include<set>

using namespace std;
typedef long long ll;

class Solution220 {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<ll> st;
        for(int i = 0; i < nums.size(); i++){
            auto pos = st.lower_bound((ll) nums[i] - t);
            if(pos != st.end() && *pos <= (ll) nums[i] + t){
                return true;
            }   
            st.insert(nums[i]);
            if(st.size() > k){
                st.erase(nums[i - k]);
            }
        }
        return false;
    }
};

int main(){
    set<int> st;
    st.insert(123);
    st.insert(123);
    st.insert(12);
    return 0;
}