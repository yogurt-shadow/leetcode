#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<set>
#include<algorithm>

using namespace std;

typedef long long ll;

class Solution3{
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >= 0 && nums[i] >= nums[j]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }

    int getMinSwaps(string num, int k) {
        vector<int> vec(num.length());
        for(int i = 0; i < num.length(); i++){
            vec[i] = num[i] - '0';
        }
        vector<int> copy(vec.begin(), vec.end());
        for(int i = 0; i < k; i++){
            nextPermutation(vec);
        }
        //cout << endl;
        int sum = 0;
        for(int i = 0; i < vec.size(); i++){
            if(vec[i] == copy[i]) continue;
            for(int k = i + 1; k < vec.size(); k++){
                if(vec[k] == copy[i]){
                    for(int m = k - 1; m >= i; m--){
                        sum ++;
                        swap(vec[m], vec[m + 1]);
                    }
                    break;
                }
            }
        }
        return sum;
    }
};



int main(){
    Solution3 s;
    s.getMinSwaps("059", 5);
    return 0;
}