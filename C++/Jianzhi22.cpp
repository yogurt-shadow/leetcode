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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        int size = 0;
        ListNode* p = head;
        while(p){
            size ++;
            p = p -> next;
        }
        p = head;
        while(size > k){
            p = p -> next;
            size --;
        }
        return p;
    }
};