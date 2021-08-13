#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

class Solution309 {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int x = -prices[0], y = 0, z = 0;
        for(int i = 1; i < size; i++){
            int curx = max(x, z - prices[i]);
            int cury = x + prices[i];
            int curz = max(y, z);
            x = curx, y = cury, z = curz;
        }
        return max(y, z);
    }
};

void swap(int& x, int& y){
    x += y;
    y = x - y;
    x -= y;
}

int main(){
    int x = 5, y= 3;
    swap(x, y);
    cout << x << " " << y << endl;
    return 0;
}