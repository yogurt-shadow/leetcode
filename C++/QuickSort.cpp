#include<iostream>
#include<vector>
#include<deque>

using namespace std;

class QuickSort {
public:
    void quicksort(vector<int>& nums){
        quicksort2(nums, 0, nums.size() - 1);
    }

    void quicksort2(vector<int>& nums, int start, int end){
        if(start >= end){
            return;
        }
        int pivot = nums[start];
        int small = 0;
        deque<int> smaller, larger;
        for(int i = start + 1; i <= end; i++){
            if(nums[i] < pivot){
                small++;
                smaller.push_back(nums[i]);
            }
            else{
                larger.push_back(nums[i]);
            }
        }
        nums[start + small] = pivot;
        for(int i = start; i < start + small; i++){
            nums[i] = smaller.front();
            smaller.pop_front();
        }
        for(int i = start + small + 1; i <= end; i++){
            nums[i] = larger.front();
            larger.pop_front();
        }
        quicksort2(nums, start, start + small - 1);
        quicksort2(nums, start + small + 1, end);
    }
};

int main(){
    QuickSort s;
    vector<int> test = {31, -13, 14, -241, 13, 626, 14, 858, -141, -14, 141};
    s.quicksort(test);
    for(auto ele: test){
        cout << ele << " ";
    }
}