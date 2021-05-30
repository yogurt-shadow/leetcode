#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>

using namespace std;

typedef long long ll;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        arr[0] = 1;
        for(int i = 1; i < arr.size(); i++){
            int last = arr[i - 1];
            if(arr[i] > last + 1){
                arr[i] = last + 1;
            }
        }
        return arr[arr.size() - 1];
    }
};

int main(){
    
    
    return 0;
}