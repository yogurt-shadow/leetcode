#include<iostream>
#include<vector>


using namespace std;

class Solution575 {
public:
    int distributeCandies(vector<int>& candyType) {
        int kind = 0;
        int size = candyType.size();
        int count[200001] = {0};
        for(auto& ele: candyType){
            if(!count[ele + 100000]){
                count[ele + 100000]++;
                kind++;
            }
        }
        return min(kind, size / 2);
    }
};