#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solutio470 {
public:
    int rand10() {
        int row, col, idx;
        do {
            row = rand7();
            col = rand7();
            idx = col + (row - 1) * 7;
        } while (idx > 40);
        return 1 + (idx - 1) % 10;
    }
};