#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution11 {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int area = 0;
        while(right > left){
            if(height[left] >= height[right]){
                area = max(area, (right - left) * height[right]);
                right--;
            }
            else{
                area = max(area, (right - left) * height[left]);
                left++;
            }
        }
        return area;
    }
};

int main(){
    pair<int, int> p ={1, 2};
    cout << p.first << p.second << endl;
    return 0;
}