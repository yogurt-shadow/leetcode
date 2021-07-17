#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution779 {
public:
    int kthGrammar(int n, int k) {
        if(n == 1){
            return 0;
        }
        int last = kthGrammar(n - 1, (k + 1) / 2);
        if(last == 0){
            if(k % 2 == 1){
                return 0;
            }
            return 1;
        }
        if(k % 2 == 1){
            return 1;
        }
        return 0;
    }
};