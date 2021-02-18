#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution18 {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int size = nums.size();
        sort(nums.begin(), nums.end());
        for(int index1 = 0; index1 < size; index1++){
            if(index1 > 0 && nums[index1] == nums[index1 - 1]){
                continue;
            }
            for(int index2 = index1 + 1; index2 < size; index2++){
                if(index2 > index1 + 1 && nums[index2] == nums[index2 - 1]){
                    continue;
                }

                int tar = target - nums[index1] - nums[index2];
                int index3 = index2 + 1, index4 = size - 1;
                while(index4 > index3){
                    int sum = nums[index3] + nums[index4];
                    if(sum == tar){
                        result.push_back({nums[index1], nums[index2], nums[index3], nums[index4]});
                        index3++;
                        index4--;
                        while(index3 < size && nums[index3] == nums[index3 - 1]){
                            index3++;
                        }
                        while(index4 >= 0 && nums[index4] == nums[index4 + 1]){
                            index4--;
                        }
                    }
                    else if(sum > tar){
                        index4--;
                        while(index4 >= 0 && nums[index4] == nums[index4 + 1]){
                            index4--;
                        }
                    }
                    else{
                        index3++;
                        while(index3 < size && nums[index3] == nums[index3 - 1]){
                            index3++;
                        }
                    }
                }
            }
        }
        return result;
    }
};