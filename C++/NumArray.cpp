#include<iostream>
#include<vector>

using namespace std;

// Solution303
class NumArray {
public:
    vector<int> sum;
    NumArray(vector<int>& nums) {
        sum.resize(nums.size() + 1);
        sum[0] = 0;
        for(int i = 1; i <= nums.size(); i++){
            sum[i] = sum[i - 1] + nums[i - 1];
        }
    }
    
    int sumRange(int i, int j) {
        return sum[j + 1] - sum[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */

int main(){
    vector<int> test = {-2, 0, 3, -5, 2, -1};
    NumArray s(test);
    cout << s.sumRange(0, 2) << " " << s.sumRange(2, 5) << " " << s.sumRange(0, 5) << endl;
    return 0;
}