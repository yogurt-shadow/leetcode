#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution75 {
public:
    void sortColors(vector<int>& nums) {
        int number[3];
        for(int i = 0; i < 3; i++){
            number[i] = 0;
        }
        for(auto ele: nums){
            number[ele]++;
        }
        int start = 0;
        for(int index = 0; index < 3; index++){
            for(int i = 0; i < number[index]; i++){
                nums[start] = index;
                start++;
            }
        }
    }
};