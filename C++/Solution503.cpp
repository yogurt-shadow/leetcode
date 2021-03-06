#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<stack>
using namespace std;

class Solution503 {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int size = nums.size();
        vector<int> copy(size * 2);
        for(int i = 0; i < size; i++){
            copy[i] = nums[i];
            copy[i + size] = nums[i];
        }
        stack<int> stk;
        vector<int> res(size);
        int index = 2 * size - 1;
        while(index >= 0){
            while(!stk.empty() && stk.top() <= copy[index]){
                stk.pop();
            }
            if(index <= size - 1){
                if(stk.empty()){
                    res[index] = -1;
                }
                else{
                    res[index] = stk.top();
                }
            }
            stk.push(copy[index]);
            index--;
        }
        return res;
    }
};

int main(){
    Solution503 s;
    vector<int> test = {1, 2, 1};
    vector<int> res = s.nextGreaterElements(test);
    for(auto ele: res){
        cout << ele << " ";
    }
}