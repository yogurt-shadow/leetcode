#include<iostream>
#include<vector>
using namespace std;

class Solution5698 {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long sum = 0;
        for(auto ele: nums){
            sum += ele;
        }
        //cout << sum  << endl;
        long diff = abs((long) goal - sum);
        if(diff == 0){
            return 0;
        }
        return (diff - 1) / limit + 1;
    }
};