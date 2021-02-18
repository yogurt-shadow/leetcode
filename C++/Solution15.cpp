#include<iostream>
#include<vector>

#include<algorithm>

using namespace std;

class Solution15 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int index1 = 0; index1 < size; index1++){
            if(index1 > 0 && nums[index1] == nums[index1 - 1]){
                continue;
            }
            if(nums[index1] > 0){
                break;
            }
            int target = -nums[index1];
            int index2 = index1 + 1, index3 = size - 1;
            while(index3 > index2){
                if(nums[index2] + nums[index3] == target){
                    result.push_back(vector<int>{nums[index1], nums[index2], nums[index3]});
                    index2++;
                    index3--;
                    while(index2 < size && nums[index2] == nums[index2 - 1]){
                        index2++;
                    }
                    while(index3 >= 0 && nums[index3] == nums[index3 + 1]){
                        index3--;
                    }
                }
                else if(nums[index2] + nums[index3] > target){
                    index3--;
                    while(index3 >= 0 && nums[index3] == nums[index3 + 1]){
                        index3--;
                    }
                }
                else{
                    index2++;
                    while(index2 < size && nums[index2] == nums[index2 - 1]){
                        index2++;
                    }
                }
            }
        }
        return result;
    }
};

int main(){
    Solution15 s;
    vector<int> test = {1};
    vector<vector<int>> result = s.threeSum(test);
    return 0;
}