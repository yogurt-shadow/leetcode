#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>

using namespace std;

typedef long long ll;

class Solution2{
public:
    int maxDistance(vector<int> &nums1, vector<int> &nums2)
    {
        int ans = 0;
        int size1 = nums1.size(), size2 = nums2.size();
        int index1 = size1 - 1, index2 = size2 - 1;
        while (index1 >= 0)
        {
            while (index2 >= index1)
            {
                if (nums2[index2] >= nums1[index1])
                {
                    ans = max(ans, index2 - index1);
                    break;
                }
                else
                {
                    index2--;
                }
            }
            index1--;
        }
        return ans;
    }
};

int main(){

    
    return 0;
}