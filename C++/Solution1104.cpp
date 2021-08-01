#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>

using namespace std;

class Solution1104 {
public:
    vector<int> pathInZigZagTree(int label) {
       vector<int> ans;
       while(label != 1){
           ans.push_back(label);
           int depth = floor(log2(label));
           int edge = (1 << depth);
           int dist = label - edge;
           int pre_edge = edge - 1;
           int pre = pre_edge - dist / 2;
           label = pre;
       }
       ans.push_back(1);
       reverse(ans.begin(), ans.end());
       return ans;
    }
};

int main(){
    Solution1104 s;
    auto output = s.pathInZigZagTree(13);
    for(auto ele: output){
        cout << ele << endl;
    }
    return 0;
}