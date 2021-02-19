#include<iostream>
#include<vector>

using namespace std;

class Solution26 {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        int index1 = 0, index2 = 0;
        while(index2 < size){
            while(index2 < size && nums[index2] == nums[index1]){
                index2++;
            }
            if(index2 < size){
                nums[index1 + 1] = nums[index2];
            }
            else{
                return index1 + 1;
            }
            index1++;
        }
        return index1 + 1;
    }
};