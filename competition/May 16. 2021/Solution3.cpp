#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef long long ll;

class FindSumPairs
{
public:
    unordered_map<int, int> mp1, mp2;
    unordered_set<int> st1, st2;
    vector<int> nums1;
    vector<int> nums2;

    FindSumPairs(vector<int> &nums1, vector<int> &nums2)
    {
        for (auto ele : nums1)
        {
            mp1[ele]++;
            st1.insert(ele);
        }
        for (auto ele : nums2)
        {
            mp2[ele]++;
            st2.insert(ele);
        }
        this->nums1 = nums1;
        this->nums2 = nums2;
    }

    void add(int index, int val)
    {
        mp2[nums2[index]]--;
        st2.erase(nums2[index]);
        nums2[index] += val;
        mp2[nums2[index]]++;
        st2.insert(nums2[index]);
    }

    int count(int tot)
    {
        int ans = 0;
        for (auto ele1 : st1)
        {
            ans += mp1[ele1] * mp2[tot - ele1];
            //cout << ele1 << ans << endl;
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */

int main(){

    return 0;
}