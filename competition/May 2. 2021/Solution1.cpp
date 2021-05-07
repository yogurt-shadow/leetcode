#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>

using namespace std;

typedef long long ll;

class Solution1{
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int m = nums.size();
        int cur = -1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target){
               if(abs(i - start) < m){
                   m = abs(i - start);
                   cur = i;
               } 
            }
        }
        return m;
    }

};

int main(){

    
    return 0;
}