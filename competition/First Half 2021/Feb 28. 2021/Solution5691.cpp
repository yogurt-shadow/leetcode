#include<iostream>
#include<vector>

#include<algorithm>

using namespace std;

class Solution5691 {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int res = 0;
        int sum1 = 0, sum2 = 0;
        for(auto ele: nums1){
            sum1 += ele;
        }
        for(auto ele: nums2){
            sum2 += ele;
        }
        int diff = sum1 - sum2;
        if(diff == 0){
            return 0;
        }
        if(sum1 < sum2){
            auto copy = nums1;
            nums1 = nums2;
            nums2 = copy;
            diff = -diff;
        }
        int size1 = nums1.size(), size2 = nums2.size();
        //cout << " sum1 " << sum1 << " sum2 " << sum2 << endl;
        int index1 = size1 - 1;
        int index2 = 0;
        while(diff){
            //cout << " index1 " << index1 << " index2 " << index2 << " diff " << diff << endl;
            if(index1 < 0 || nums1[index1] == 1){
                if(index2 >= size2 || nums2[index2] == 6){
                    return -1;
                }
                int diff2 = 6 - nums2[index2];
                if(diff2 >= diff){
                    res++;
                    return res;
                }
                diff -= diff2;
                index2++;
                res++;
            }
            else if(index2 >= size2 || nums2[index2] == 6){
                int diff1 = nums1[index1] - 1;
                if(diff1 >= diff){
                    res++;
                    return res;
                }
                diff -= diff1;
                index1--;
                res++;
            }
            else{
                int diff1 = nums1[index1] - 1;
                int diff2 = 6 - nums2[index2];
                if(max(diff1, diff2) == 0){
                    return -1;
                }
                if(diff1 >= diff || diff2 >= diff){
                    res++;
                    return res;
                }
                if(diff1 >= diff2){
                    diff -= diff1;
                    index1--;
                    res++;
                }
                else{
                    diff -= diff2;
                    index2++;
                    res++;
                }
            }
        }
        return res;
    }
};

int main(){
    Solution5691 s;
    vector<int> test1 = {5,6,4,3,1,2};
    vector<int> test2 = {6,3,3,1,4,5,3,4,1,3,4};
    cout << s.minOperations(test1, test2);
    return 0;
}