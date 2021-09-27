#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>

using namespace std;

typedef long long ll;

// Solution528

class Solution {
public:
    int sum;
    int size;
    vector<int> pre;
    vector<int> w;


    Solution(vector<int>& w) {
        this -> w = w;
        size = w.size();
        pre.resize(size);
        pre[0] = w[0];
        for(int i = 1; i < size; i++){
            pre[i] = pre[i - 1] + w[i];
        }
        sum = pre.back();
    }
    
    int pickIndex() {
        int x = rand() % sum + 1;
        int left = 0, right = size;
        while(right - left > 1){
            int mid = (right - left) / 2 + left;
            if(pre[mid] - w[mid] + 1 <= x && x <= pre[mid]){
                return mid;
            }
            if(x > pre[mid]){
                left = mid;
            }
            else{
                right = mid;
            }
        }
        return left;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

int main(){
    vector<int> vec = {1, 3};
    Solution s(vec);
    cout << s.pickIndex() << endl;
    return 0;
}