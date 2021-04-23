#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<stack>
using namespace std;

class Solution88 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index1 = m - 1;
        int index2 = n - 1;
        int index = m + n - 1;
        while(index1 >= 0 || index2 >= 0){
            if(index1 < 0){
                nums1[index--] = nums2[index2--];
            }
            else if(index2 < 0){
                nums1[index--] = nums1[index1--];
            }
            else if(nums1[index1] >= nums2[index2]){
                nums1[index--] = nums1[index1--];
            }
            else{
                nums1[index--] = nums2[index2--];
            }
        }
    }
};