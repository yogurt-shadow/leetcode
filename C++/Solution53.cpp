#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution53 {
public:
    struct SegTree{
        int iSum, lSum, rSum, mSum;
        SegTree(SegTree left, SegTree right){
            iSum = left.iSum + right.iSum;
            lSum = max(left.lSum, left.iSum + right.lSum);
            rSum = max(right.rSum, left.rSum + right.iSum);
            mSum = max(max(left.mSum, right.mSum), left.rSum + right.lSum);
        }
        SegTree(int x){
            iSum = x;
            lSum = x;
            rSum = x;
            mSum = x;
        }
    };

    int maxSubArray(vector<int>& nums) {
        SegTree seg = build(nums);
        return seg.mSum;
    }

    SegTree build(vector<int>& nums){
        int size = nums.size();
        if(size == 1){
            return SegTree(nums[0]);
        }
        int mid = (size - 1) / 2;
        vector<int> left(nums.begin(), nums.begin() + mid + 1);  
        vector<int> right(nums.begin() + mid + 1, nums.end());
        SegTree seg1 = build(left);
        SegTree seg2 = build(right);
        return SegTree(seg1, seg2);
    }
};

int main(){
    Solution53 s;
    vector<int> test1 = {1, -1};
    cout << s.maxSubArray(test1) << endl;
    return 0;
}