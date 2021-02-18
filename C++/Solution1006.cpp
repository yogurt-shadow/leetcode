#include<iostream>
#include<vector>

using namespace std;

class Solution1006 {
public:
    int clumsy(int N) {
        int diff[] = {2, 2, -1, 1};
        if(N >= 5){
            return N + diff[(N - 1) % 4];
        }
        if(N >= 3){
            return N + 3;
        }
        return N;
    }
};