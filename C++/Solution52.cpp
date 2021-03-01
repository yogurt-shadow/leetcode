#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution52 {
public:
    unordered_set<int> col, line1, line2;
    int size;
    int count = 0;

    int totalNQueens(int n) {
        count = 0;
        size = n;
        fill(0);
        return count;    
    }

    void fill(int index){
        for(int xx = 0; xx < size; xx++){
            if(col.count(xx) > 0 || line1.count(index - xx) > 0 || line2.count(xx + index) > 0){
                continue;
            }
            if(index == size - 1){
                count++;
                return;
            }
            col.insert(xx);
            line1.insert(index - xx);
            line2.insert(xx + index);
            fill(index + 1);
            col.erase(col.find(xx));
            line1.erase(line1.find(index - xx));
            line2.erase(line2.find(xx + index));
        }
    }
};

int main(){
    Solution52 s;
    cout << s.totalNQueens(2) << endl;
    for(int i = 1; i <= 9; i++){
        cout << "i: " << i << " number: " << s.totalNQueens(i) << endl;
    }
    return 0;
}