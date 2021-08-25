#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<map>
#include<math.h>

using namespace std;

class Solution1646 {
public:
    int getMaximumGenerated(int n)
    {
        if (n <= 1){
            return n;
        }
        vector<int> vec(n + 1);
        vec[0] = 0;
        vec[1] = 1;
        for (int i = 2; i <= n; i++){
            if (i % 2 == 0){
                vec[i] = vec[i / 2];
            }
            else{
                vec[i] = vec[i / 2] + vec[i / 2 + 1];
            }
        }
        return *max_element(vec.begin(), vec.end());
    }
};