#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<cstring>

using namespace std;
using ll = long long;

class Solution2{
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> vec(queries.size());
        for(int i = 0; i < queries.size(); i++){
            int res = 0;
            int x0 = queries[i][0];
            int y0 = queries[i][1];
            int r = queries[i][2];
            for(auto ele: points){
                int x = ele[0];
                int y = ele[1];
                if((x-x0)*(x-x0) + (y-y0)*(y-y0) <= r*r){
                    res++;
                }
            }
            vec[i] = res;
        }
        return vec;
    }
};

int main(){
    
    
    return 0;
}