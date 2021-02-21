#include<iostream>
#include<vector>

#include<unordered_map>
using namespace std;

class Solution697 {
public:
    int findShortestSubArray(vector<int>& nums) {
        int size = nums.size();
        unordered_map<int, int> map1;
        int degree = 0;
        for(auto ele: nums){
            map1[ele]++;
            degree = max(degree, map1[ele]);
        }
        unordered_map<int, int> map2;
        int left = 0, right = degree - 1, len = size;
        for(int i = left; i <= right; i++){
            map2[nums[i]]++;
        }
        while(right < size){
            int cur = 0;
            for(auto ele: map2){
                cur = max(cur, ele.second);
            }
            if(cur < degree){
                right++;
                if(right < size){
                    map2[nums[right]]++;
                }
            }
            else{    
                len = min(len, right - left + 1);
                if(len == degree){
                    return len;
                }
                map2[nums[left]]--;
                left++;
            }
        }
        return len;
    }
};

int main(){
    Solution697 s;
    vector<int> test = {1,2,2,3,1,4,2};
    cout << s.findShortestSubArray(test);
    return 0;
}