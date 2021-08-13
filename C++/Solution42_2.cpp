#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<stack>
using namespace std;

typedef long long ll;

class Solution42_2 {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int size = height.size();
        vector<int> left(size), right(size);
        left[0] = height[0];
        for(int i = 1; i < size; i++){
            left[i] = max(left[i - 1], height[i]);
        }
        right[size - 1] = height[size - 1];
        for(int i = size - 2; i >= 0; i--){
            right[i] = max(right[i + 1], height[i]);
        }
        for(int i = 0; i < size; i++){
            ans += min(left[i], right[i]) - height[i];
        }
        return ans;
    }
};