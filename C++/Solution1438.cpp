#include<iostream>
#include<vector>

#include<set>
using namespace std;

class Solution1438 {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int left = 0, right = 0;
        int len = 0;
        int size = nums.size();
        multiset<int> set;
        set.insert(nums[0]);
        while(right < size){
            int maxx = *set.rbegin();
            int minn = *set.begin();
            if(maxx - minn > limit){
                set.erase(set.find(nums[left]));
                left++;
            }
            else{
                len = max(len, right - left + 1);
            }
            right++;
            if(right < size){
                set.insert(nums[right]);
            }
        }
        return len;
    }
};

int main(){
    set<int> sets;
    sets.insert(123);
    sets.insert(1231);
    sets.insert(671);
    for(auto ele: sets){
        cout << ele << endl;
    }
    cout << *sets.begin() << endl;
    cout << *sets.rbegin() << endl;
    return 0;
}