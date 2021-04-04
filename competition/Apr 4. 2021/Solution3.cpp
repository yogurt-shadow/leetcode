#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>

using namespace std;
typedef long long ll;

class Solution3 {
public:
    const int MOD = 1000000000 + 7;
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        ll res = 0;
        vector<int> store(nums1.size());
        for(int i = 0; i < nums1.size(); i++){
            store[i] = abs(nums1[i] - nums2[i]);
            res += store[i];
        }
        ll res2 = res;
        ll res3 = res;
        //cout << res << endl;
        vector<int> copy1(nums1.begin(), nums1.end());
        sort(copy1.begin(), copy1.end());
        for(int index = 0; index < nums1.size(); index++){
            int value = find(copy1, nums2[index]);
            //cout << value << endl;
            res -= store[index];
            res += value;
            res3 = min(res3, res);
            res = res2;
        }
        return res3 % MOD;
    }

    int find(vector<int>& nums1, int x){
        int left = 0;
        int right = nums1.size() - 1;
        if(nums1[left] >= x){
            return nums1[left] - x;
        }
        if(nums1[right] <= x){
            return x - nums1[right];
        }
        int mm = nums1[right] - x;
        while(right - left > 1){
            int mid = (left + right) / 2;
            mm = min(mm, abs(nums1[mid] - x));
            if(mm == 0){
                return 0;
            }
            if(nums1[mid] < x){
                left = mid;
            }
            else{
                right = mid;
            }
        }
        return mm;
    }
};