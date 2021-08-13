#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution4 {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int> &obstacles) {
        vector<int> ans, d;
        for(int ele: obstacles){
            if(d.empty() || ele > d.back()){
                d.push_back(ele);
                ans.push_back(d.size());
            }
            else{
                int index = upper_bound(d.begin(), d.end(), ele) - d.begin();
                d[index] = ele;
                ans.push_back(index + 1);
            }
        }
        return ans;
    }
};

int main(){

    return 0;
}