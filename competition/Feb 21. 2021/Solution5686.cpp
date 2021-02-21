#include<iostream>
#include<vector>

#include<unordered_set>

using namespace std;

class Solution5686 {
public:
    vector<int> minOperations(string boxes) {
        unordered_set<int> set;
        for(int i = 0; i < boxes.length(); i++){
            if(boxes[i] == '1'){
                set.insert(i);
            }
        }
        vector<int> result(boxes.length());
        for(int i = 0; i < boxes.length(); i++){
            int cur = 0;
            for(auto ele: set){
                cur += abs(ele - i);
            }
            result[i] = cur;
        }
        return result;
    }
};