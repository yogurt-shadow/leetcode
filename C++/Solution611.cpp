#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution611 {
public:
    int triangleNumber(vector<int> &nums){
        int ans = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i + 2 < nums.size(); i++){
            int index = i + 2;
            for (int j = i + 1; j + 1 < nums.size(); j++){
                while (index < nums.size() && nums[i] + nums[j] > nums[index]){
                    index++;
                }
                //cout << index << endl;
                //cout << nums[i] << " " << nums[j] << " " << index << endl;
                ans += max(index - j - 1, 0);
            }
        }
        return ans;
    }
};