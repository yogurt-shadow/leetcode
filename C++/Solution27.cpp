#include<iostream>
#include<vector>

using namespace std;

class Solution27 {
public:
    int removeElement(vector<int>& nums, int val) {
        int index1 = 0, index2 = 0, size = nums.size();
        while(index2 < size){
            while(index2 < size && nums[index2] == val){
                index2++;
            }
            if(index2 == size){
                return index1;
            }
            nums[index1] = nums[index2];
            index1++;
            index2++;
        }
        return index1;
    }
};