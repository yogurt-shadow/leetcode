#include<iostream>
#include<vector>

using namespace std;

class Solution4 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        if(size1 + size2 == 0){
            return 0;
        }
        int size = size1 + size2;
        return size % 2 == 1 ? Kthsmallest(nums1, nums2, size/2 + 1) : (Kthsmallest(nums1, nums2, size / 2) + Kthsmallest(nums1, nums2, size / 2 + 1)) / 2.0;
    }

private:
    int Kthsmallest(vector<int>& nums1, vector<int>& nums2, int k){
        int size1 = nums1.size();
        int size2 = nums2.size();
        if(size1 == 0){
            return nums2[k - 1];
        }
        else if(size2 == 0){
            return nums1[k - 1];
        }

        if(k == 1){
            return min(nums1[0], nums2[0]);
        }
        int index1 = k / 2, index2 = k / 2;
        if(size1 < index1){
            index1 = size1;
        }
        else if(size2 < index2){
            index2 = size2;
        }
        if(nums1[index1 - 1] >= nums2[index2 - 1]){
            vector<int> copy2(nums2.begin() + index2, nums2.end());
            return Kthsmallest(nums1, copy2, k - index2);
        }
        else{
            vector<int> copy1(nums1.begin() + index1, nums1.end());
            return Kthsmallest(copy1, nums2, k - index1);
        }
    }
};

int main(){
    Solution4 s;
    vector<int> test11 = {1, 3};
    vector<int> test12 = {2};
    double result = s.findMedianSortedArrays(test11, test12);
    cout << result << endl;
}